// xmastree.c -- an ncurses learning sandbox
// copyright 2015 robert holder, MIT license
// https://github.com/rdholder/cursim

#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include <math.h>
#include <signal.h>

static void finish(int sig);


// typical gameplay characters
// - = ; ' , . / : " < > ? ` ~ ! @ # $ % ^ & * ( ) _ +

int main(int argc, char *argv[])
{
//	int num = 0;
	int row=0;
	int col=0;
    //int cursorx=0, cursory=0;
	int treeheight=25, treewidth=20;
    int treecoloffset=treewidth/2+10;
    int ornamentchance=10;
    //int mycolor=0;
	//int colorchance=10;
	int letter=0;
	int count=0;
	int selector=0;

	/* initialize your non-curses data structures here */

	(void) signal(SIGINT, finish);      /* arrange interrupts to terminate */

	(void) initscr();      /* initialize the curses library */
	keypad(stdscr, TRUE);  /* enable keyboard mapping */
	(void) nonl();         /* tell curses not to do NL->CR/NL on output */
	(void) cbreak();       /* take input chars one at a time, no wait for \n */
	(void) echo();         /* echo input - in color */

    if (has_colors())
    {
        start_color();

        /*
         * Simple color assignment, often all we need.  Color pair 0 cannot
         * be redefined.  This example uses the same value for the color
         * pair as for the foreground color, though of course that is not
         * necessary:
         */
        init_pair(1, COLOR_RED,     COLOR_GREEN);
        init_pair(2, COLOR_GREEN,   COLOR_GREEN);
        init_pair(3, COLOR_YELLOW,  COLOR_GREEN);
        init_pair(4, COLOR_BLUE,    COLOR_GREEN);
        init_pair(5, COLOR_RED,     COLOR_GREEN);
        init_pair(6, COLOR_MAGENTA, COLOR_GREEN);
        init_pair(7, COLOR_WHITE,   COLOR_GREEN);
    }

//    for (;;)
//    {
//        int c = getch();     /* refresh, accept single keystroke of input */
//        attrset(COLOR_PAIR(num % 8));
//        num++;

//        /* process the command keystroke */
//    }


        srand(time(NULL));
        initscr();
    	curs_set(0);
        addstr("Press any key to exit");
        for (count=0; count < 50000; count++) {
            napms(100);
            for (row=0; row < treeheight; row++) {
                for (col=treewidth/2-row+treecoloffset; col < treewidth/2+row+treecoloffset; col++) {
                    //cursorx=(treewidth/2)-row;
                    move(row,col);
                    selector = rand()%ornamentchance;
                    switch (selector) {
                        case 0: letter='*';
                                attrset(COLOR_PAIR(rand()%7+1));
                                break;
                        default: letter=' ';
                        break;
                    }
                    addch(letter);
		            attrset(COLOR_PAIR(7));
                    napms(1);
                }
            }
	        refresh();
        }
        move(22,0);
        addstr("Hit any key to exit.");
        getch();

	finish(0);               /* we're done */
	return 0;
}

static void finish(int sig)
{
    endwin();

    /* do your non-curses wrapup here */

    exit(0);
}

