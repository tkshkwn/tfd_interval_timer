#include <stdio.h>

#include "tfd_interval_timer.h"

#define INTERVAL_TIME_MSEC 100


int main(void)
{
	int32_t tfd = tfd_interval_timer_create(INTERVAL_TIME_MSEC);
	if (tfd == -1) {
		return 1;
	}
	struct timespec ts;
	for(;;) {
		clock_gettime(CLOCK_MONOTONIC, &ts);
		printf("%10ld.%09ld:Hello\n", ts.tv_sec, ts.tv_nsec);
		tfd_interval_timer_wait(tfd);
	}
	tfd_interval_timer_close(tfd);
	return 0;
}
