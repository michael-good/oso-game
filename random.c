#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "random.h"

/*
 * void set_seed_random_generator();
 * Sets a seed for the random numbers generator.
 */
void set_seed_random_generator() {
	srand( (unsigned)time( NULL ) );
}


/*
 * int get_random_number(int max);
 * Returns a random integer between 1 and the max value specified as input.
 */
int get_random_number(int max) {
	return ( rand() % max) + 1; 
}

