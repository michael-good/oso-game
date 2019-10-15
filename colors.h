#ifndef COLORS_H
#define	COLORS_H

#define ANSI_COLOR_BLACK   "\x1b[30m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_WHITE   "\x1b[37m"
#define ANSI_COLOR_RESET   "\x1b[0m"


/*
 * void set_print_color(int color);
 * Given a color -1Default, 0Red, 1Green, 2Yellow, 3Blue, 4Magenta, 5Cyan
 * makes the terminal print in that color.
 */
void set_print_color(int color);


/*
 * void reset_print_color();
 * Makes terminal print in its default color.
 */
void reset_print_color();

#endif	/* COLORS_H */

