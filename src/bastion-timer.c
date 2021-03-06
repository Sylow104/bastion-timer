#include "bastion-timer.h"

static uint32_t remaining_time = 0;
static uint32_t decrement = 0;
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

extern bool is_ready;

void *timer_main(void *args)
{
        int interval = *(int *) args;
        int i = 0;

        struct timeval time;
        pthread_mutex_lock(&mtx);
        while (!is_ready) {
                pthread_cond_wait(&cond, &mtx);
        }
        pthread_mutex_unlock(&mtx);
        while (1) {
                if (i < interval) {
                        printf("%d ", (i++) + 1);
                }
                fflush(stdout);
                
                if (i == interval) {
                        printf("Tick\n");
                        i = 0;
                }

                time.tv_sec = 1;
                time.tv_usec = 0;
                select(0, NULL, NULL, NULL, &time);
        }
        return NULL;
}

int timer_setup(uint32_t minute, uint32_t seconds, uint32_t n_decrement)
{
        if (minute == 0 && seconds == 0) {
                return NO_TIME;
        }
        if (n_decrement < 0) {
                return NO_DECREMENT;
        }
        if (seconds > 60) {
                return BAD_SECONDS;
        }
        remaining_time = seconds + (minute * 60);
        decrement = n_decrement;
        printf("Remaining time: %u seconds, decrement %u seconds\n", remaining_time, decrement);
        return 0;
}

int timer_decrement(uint32_t *o_minute, uint32_t *o_seconds)
{
        *o_minute = 0;
        *o_seconds = 0;
        if (remaining_time <= 0) {
                return FINISHED;
        }

        if (decrement == 0) {
                return NO_DECREMENT;
        }

        if (remaining_time < decrement) {
                return FINISHED;
        }

        remaining_time -= decrement;
        *o_seconds = remaining_time % 60;
        *o_minute = remaining_time / 60;

        return NEXT_INTERVAL;
}