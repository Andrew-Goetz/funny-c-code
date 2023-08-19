/* WARNING: this program makes colors flash very rapidly on the screen.
 * Do NOT run the program if you're sensitive to that kind of thing.
 * 
 * Compile with -lcurses.
 */

#include <curses.h>
#include <unistd.h>

int main(void) {
	initscr();
	start_color();
	curs_set(0);

	init_pair(1, COLOR_BLACK, COLOR_RED);
	init_pair(2, COLOR_BLACK, COLOR_GREEN);
	init_pair(3, COLOR_BLACK, COLOR_BLUE);

	for(;;) {
		wbkgd(stdscr, COLOR_PAIR(1));
		refresh();
		wbkgd(stdscr, COLOR_PAIR(2));
		refresh();
		wbkgd(stdscr, COLOR_PAIR(3));
		refresh();
	}

	curs_set(1);
	endwin();
}
