### cursim -- c/ncurses experiments sandbox

nCurses is a library that lets you control what happens on the screen in a unix or linux terminal window better than ordinary console (stream tty) programs allow.  ncurses is how games like rogue and other text-based games "draw" characters and maps and things on the screen in old-style text games.

cursim is just a fun little collection of simple programs that let us learn ncurses and maybe write some fun games or little tools we can use in ssh sessions.  There probably won't be anything here that anyone would want to use, but who knows, maybe we'll come up with something neat.

We are working from Dan Gookin's book "Programmer's Guide to nCurses", available on Amazon, et. al.  We want to write some fun simulations including critter sims, economic sims, and whatever else we can think of, focusing on game & sim logic and not having to spend a lot of time on learning a bunch of graphics stuff that we suck at anyways.  It might also be cool to write some little system monitoring tools with ncurses, for learning.

QUICKREF

TO INSTALL ON UBUNTU (from the command line):
+ sudo apt-get install build-essential git libncurses-dev
+ mkdir cursim
+ cd cursim
+ git clone https://github.com/rdholder/cursim.git
+ gcc -Wall -o cursim cursim.c -lncurses
+ cursim

[github clone help](https://help.github.com/articles/cloning-a-repository/).

TODO: REMEMBER TO VERIFY THESE INSTRUCTIONS
