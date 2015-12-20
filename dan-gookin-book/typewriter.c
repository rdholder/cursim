// typewriter.c -- A SUPER AWESOME TYPEWRITER SIMULATOR
// copyright 2015 robert holder, MIT license
// https://github.com/rdholder/cursim

#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include <math.h>

int main(void)
{
	char ch;

        initscr();
        addstr("Type a few lines of text\n");
        addstr("Press ~ to quit\n");
	refresh();

	while( (ch = getch() ) != '~')
		;
        endwin();

	return(0);
}

