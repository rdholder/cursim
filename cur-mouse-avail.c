#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>

int main(void)
{
        mmask_t mmask;

        initscr();

        if(NCURSES_MOUSE_VERSION > 0)
                addstr("This version of NCurses supports the mouse.\n");
        else
                addstr("This version of NCurses does not support the mouse.\n");
        refresh();
        getch();
        endwin();
        return 0;
}

