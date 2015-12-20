// screensize.c -- ncurses screensize example
// copyright 2015 robert holder, MIT license
// https://github.com/rdholder/cursim

#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include <math.h>

int main(void)
{
        // int row=0, col=0, letter, count, selector;
        srand(time(NULL));
        initscr();
        printw("Window size is %d,%d (row,col).\n", LINES, COLS);

	refresh();
	getch();
        endwin();

	return(0);
}

