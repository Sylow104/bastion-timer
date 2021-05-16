#include "bastion-timer.h"

int main(int argc, char *argv)
{
        uint32_t minutes = 0;
        uint32_t seconds = 0;
        timer_setup(5, 59, 10);
        printf("hello world\n");
        while (timer_decrement(&minutes, &seconds) == NEXT_INTERVAL) {
                printf("%u minutes %u seconds\n", minutes, seconds);
        }
        return 0;
}