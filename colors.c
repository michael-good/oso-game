#include <stdio.h>
#include "colors.h"


/*
 * void set_print_color(int color);
 * Given a color -1Default, 0Red, 1Green, 2Yellow, 3Blue, 4Magenta, 5Cyan
 * makes the terminal print in that color.
 */
void set_print_color(int color) {
	switch (color) {
		case -1: printf(ANSI_COLOR_RESET ); break;
		case  0: printf(ANSI_COLOR_RED    ); break;
		case  1: printf(ANSI_COLOR_GREEN  ); break;
		case  2: printf(ANSI_COLOR_YELLOW ); break;
		case  3: printf(ANSI_COLOR_BLUE   ); break;
		case  4: printf(ANSI_COLOR_MAGENTA); break;
		case  5: printf(ANSI_COLOR_CYAN   ); break;
	}
}

/*
 * void reset_print_color();
 * Makes terminal print in its default color.
 */
void reset_print_color() {
	set_print_color(-1);
}

