#ifndef TFD_INTERVAL_TIMER_H_
#define TFD_INTERVAL_TIMER_H_

#include <sys/timerfd.h>
#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>


int32_t tfd_interval_timer_create(uint32_t interval_msec);
void tfd_interval_timer_wait(int32_t tfd);
void tfd_interval_timer_close(int32_t tfd);


#endif  // TFD_INTERVAL_TIMER_H_
