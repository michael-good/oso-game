#ifndef SLEEP_H
#define	SLEEP_H

#define SOME_TIME		50000000


/*
 * void sleep(long nanoseconds);
 * Given a time value in nanoseconds,
 * it stops program's execution flow for that amount of time.
 */
void sleep(long nanoseconds);


/*
 * void sleep_for_while();
 * Calls sleep function in order to make the program sleep
 * for a while.
 */
void sleep_for_while();

#endif	/* DUERME_H */

