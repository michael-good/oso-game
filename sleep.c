#include <time.h>
#include "sleep.h"

/*
 * void sleep(long nanoseconds);
 * Given a time value in nanoseconds,
 * it stops program's execution flow for that amount of time.
 */
void sleep(long nanoseconds) {
	struct timespec tim, tim2;
	tim.tv_sec = 0;
	tim.tv_nsec = nanoseconds;

	nanosleep(&tim , &tim2);
}

/*
 * void sleep_for_while();
 * Calls sleep function in order to make the program sleep
 * for a while.
 */
void sleep_for_while() {
	sleep(SOME_TIME);
}

