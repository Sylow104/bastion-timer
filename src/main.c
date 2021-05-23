#include "bastion-timer.h"

bool is_ready = false;
extern pthread_mutex_t mtx;
extern pthread_cond_t cond;

int main(int argc, char *argv)
{
        uint32_t minutes = 0;
        uint32_t seconds = 0;
        uint32_t interval = 8;
        int c;

        pthread_t thrd_id;
        if (pthread_create(&thrd_id, NULL, timer_main, (void *) &interval)) {
                perror("pthread_create");
                exit(EXIT_FAILURE);
        }
        pthread_mutex_lock(&mtx);
        printf("Press Enter to stop the timer\n");
        is_ready = true;
        pthread_mutex_unlock(&mtx);
        pthread_cond_signal(&cond);

        do {
                c = fgetc(stdin);
        } while (c != EOF && c != '\n');

        printf("Stopped the timer...\n");
        return 0;
}