#ifndef _BASTION_TIMER_
#define _BASTION_TIMER_
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#ifdef WIN32
#include <winsock2.h>
#else /* this is linux */
#include <sys/types.h>
#endif

#define NEXT_INTERVAL   (1)
#define FINISHED        (0)
#define NO_TIME         (-1)
#define NO_DECREMENT    (-2)
#define BAD_SECONDS     (-3)

/* set flags */

void *timer_main(void *args);
int options_parse(int argc, char **argv);

/*
int timer_setup(uint32_t minute, uint32_t seconds, uint32_t n_decrement);
int timer_decrement(uint32_t *o_minute, uint32_t *o_seconds);
*/
#endif /* _BASTION_TIMER_ */