// string1.c -- read a string in without checking input length
// copyright 2015 robert holder, MIT license
// https://github.com/rdholder/cursim

// this is a good example of why getnstr() is necessary to avoid
// smashing the stack.  at the command line, type:
// ulimit -c unlimited
// ...to enable core file writing.  then run the string1 program, and type
// in names longer than the array sizes (24 or 32) to clobber memory.  then:
// gdb string1 core
// ... then type
// where
// ... to see where the coredump occurred.

#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include <math.h>

int main(void)
{
	char first[24];
	char last[32];

        initscr();
        addstr("What is your first name? ");
	refresh();
	getstr(first);

        addstr("What is your last name? ");
	refresh();
	getstr(last);

	printw("Pleased to meet you, %s %s! Hope you guessed my name", first, last);
	refresh();
	getch();

        endwin();
	return(0);
}

