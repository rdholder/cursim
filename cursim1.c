// cursim1.c -- an ncurses learning sandbox
// copyright 2015 inhabited.systems, MIT license
// github.com/inhabited.systems/cursim1

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include <math.h>

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

int main(void)
{
        int row=0, col=0, letter, count, selector;
        srand(time(NULL));
        initscr();
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
                addch(letter);
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
        endwin();

	return(0);
}

