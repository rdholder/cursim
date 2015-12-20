// curtemplate.c -- basic ncurses template
// copyright 2015 robert holder, MIT license
// https://github.com/rdholder/cursim

#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include <math.h>

int main(void)
{
	char text[] = "Greetings from Ncurses!";
	char *t=NULL;

        initscr();
	t = text;

	while (*t)
	{
		addch(*t);
		t++;
		refresh();
		napms(100);
	}
	getch();
        endwin();

	return 0;
}

