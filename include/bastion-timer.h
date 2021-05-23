#ifndef _BASTION_TIMER_
#define _BASTION_TIMER_
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define NEXT_INTERVAL   (1)
#define FINISHED        (0)
#define NO_TIME         (-1)
#define NO_DECREMENT    (-2)
#define BAD_SECONDS     (-3)

/* set flags */

int timer_main(uint32_t interval);

/*
int timer_setup(uint32_t minute, uint32_t seconds, uint32_t n_decrement);
int timer_decrement(uint32_t *o_minute, uint32_t *o_seconds);
*/
#endif /* _BASTION_TIMER_ */