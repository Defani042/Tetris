Tetris: main.o MainWindow.o plateau.o
	gcc -o Tetris main.o MainWindow.o plateau.o `pkg-config --libs-only-other --libs-only-L --libs-only-l MLV`

main.o: main.c MainWindow.h plateau.h
	gcc -c -Wall -W -std=c89 -pedantic -O2 `pkg-config --cflags MLV` main.c -o main.o

MainWindow.o: MainWindow.c MainWindow.h
	gcc -c -Wall -W -std=c89 -pedantic -O2 `pkg-config --cflags MLV` MainWindow.c -o MainWindow.o

plateau.o: plateau.c plateau.h
	gcc -c -Wall -W -std=c89 -pedantic -O2 `pkg-config --cflags MLV` plateau.c -o plateau.o

clean:
	rm -rf *.o *~ Tetris

