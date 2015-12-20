// cursim1.c -- an ncurses learning sandbox
// copyright 2015 robert holder, MIT license
// https://github.com/rdholder/cursim

#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include <math.h>
#include <signal.h>

static void finish(int sig);


// DESIGN NOTES:
// typical gameplay characters
// - = ; ' , . / : " < > ? ` ~ ! @ # $ % ^ & * ( ) _ +
// @ player
// ~ crop
// # machine
// $ gold
// + tool
// % horse
// & cow
// = dog
// - cat
// ^ wolf
// ; fox
// " rabbit
// ' rodent
// * cart

// alternatively...
// . seedling plant
// : growing plant
// ; harvestable plant
// ^ tree

int main(int argc, char *argv[])
{
	int num = 0;
	int row=0;
	int col=0;
	int mycolor=0;
	int colorchance=10;
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
        init_pair(1, COLOR_RED,     COLOR_BLACK);
        init_pair(2, COLOR_GREEN,   COLOR_BLACK);
        init_pair(3, COLOR_YELLOW,  COLOR_BLACK);
        init_pair(4, COLOR_BLUE,    COLOR_BLACK);
        init_pair(5, COLOR_CYAN,    COLOR_BLACK);
        init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
        init_pair(7, COLOR_WHITE,   COLOR_BLACK);
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
        addstr("ncurses test!  ");
        for (count=0; count < 500000; count++) {
//                napms(50);
                move(1,0);
                printw("row = %d col = %d", row, col);
                row = rand()%20+2;
                col = rand()%40;
                selector = rand()%5;
                switch (selector) {
                        case 0: letter='.';
                        break;
                        case 1: letter='-';
                        break;
                        case 2: letter='+';
                        break;
                        case 3: letter='=';
                        break;
                        case 4: letter='*';
                        break;
                }
                move(row,col);
		if ( rand()%colorchance==1 )
		{
			attrset(COLOR_PAIR(rand()%8));
                }
                addch(letter);
		attrset(COLOR_PAIR(7));
                refresh();
                napms(1);
                move(row,col);
//                addch(' ');
                refresh();
        }
	refresh();
        move(22,0);
        addstr("Hit any key to exit.");
        getch();

	finish(0);               /* we're done */
}

static void finish(int sig)
{
    endwin();

    /* do your non-curses wrapup here */

    exit(0);
}

