#include "tfd_interval_timer.h"

#define ZERO 0


int32_t tfd_interval_timer_create(uint32_t interval_msec)
{
	int32_t tfd = timerfd_create(CLOCK_MONOTONIC, ZERO);
	if (tfd == -1) {
		perror("Error:timerfd_create");
		return tfd;
	}
	struct itimerspec its;
	uint32_t interval_sec = interval_msec / 1000;
	uint64_t interval_nsec = (interval_msec - (interval_sec * 1000)) * 1000000;
	its.it_interval.tv_sec = interval_sec;
	its.it_interval.tv_nsec = interval_nsec;
	its.it_value.tv_sec = interval_sec;
	its.it_value.tv_nsec = interval_nsec;
	timerfd_settime(tfd, 0, &its, 0);
	return tfd;
}

void tfd_interval_timer_wait(int32_t tfd) {
	static uint64_t buf;
	read(tfd, &buf, sizeof(uint64_t));	
}

void tfd_interval_timer_close(int32_t tfd) {
	close(tfd);
}
