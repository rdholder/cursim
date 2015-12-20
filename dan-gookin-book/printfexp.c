// curtemplate.c -- basic ncurses template
// copyright 2015 robert holder, MIT license
// https://github.com/rdholder/cursim

#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include <math.h>

int main(void)
{
        initscr();
        addstr("ncurses test!  ");
	getch();
	printf("printf line");
	getch();
	printw("printw line1");
	getch();
	printw("printw line2");

	refresh();
	getch();
        endwin();

	return(0);
}

