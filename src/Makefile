<<<<<<< HEAD
Tetris: main.o MainWindow.o plateau.o piece.o
	gcc -o Tetris main.o MainWindow.o plateau.o piece.o `pkg-config --libs-only-other --libs-only-L --libs-only-l MLV`
=======
Tetris: main.o plateau.o save.o scoreboard.o MainWindow.o
	gcc -o Tetris main.o MainWindow.o plateau.o save.o scoreboard.o `pkg-config --libs-only-other --libs-only-L --libs-only-l MLV`
>>>>>>> Gaultier

main.o: main.c MainWindow.h plateau.h piece.h
	gcc -c -Wall -W -std=c89 -pedantic -O2 `pkg-config --cflags MLV` main.c -o main.o

MainWindow.o: MainWindow.c MainWindow.h
	gcc -c -Wall -W -std=c89 -pedantic -O2 `pkg-config --cflags MLV` MainWindow.c -o MainWindow.o

plateau.o: plateau.c plateau.h
	gcc -c -Wall -W -std=c89 -pedantic -O2 `pkg-config --cflags MLV` plateau.c -o plateau.o

<<<<<<< HEAD
piece.o: piece.c piece.h
	gcc -c -Wall -W -std=c89 -pedantic -O2 `pkg-config --cflags MLV` piece.c -o piece.o
=======
save.o:
	gcc -c -Wall -W -std=c89 -pedantic -O2 `pkg-config --cflags MLV` save.c -o save.o

scoreboard.o:
	gcc -c -Wall -W -std=c89 -pedantic -O2 `pkg-config --cflags MLV` scoreboard.c -o scoreboard.o
>>>>>>> Gaultier

clean:
	rm -rf *.o *~ Tetris

