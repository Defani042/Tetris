Tetris: build/main.o build/MainWindow.o build/plateau.o build/piece.o build/scoreboard.o build/save.o build/gameWindow.o
	gcc -o Tetris  build/main.o  build/MainWindow.o  build/plateau.o  build/piece.o  build/scoreboard.o  build/save.o  build/gameWindow.o `pkg-config --libs-only-other --libs-only-L --libs-only-l MLV`

build/main.o: src/main.c src/MainWindow.h src/plateau.h src/piece.h src/save.h src/scoreboard.h src/gameWindow.h
	gcc -c -Wall -W -std=c89 -pedantic -O2 `pkg-config --cflags MLV` src/main.c -o build/main.o

build/MainWindow.o: src/MainWindow.c src/MainWindow.h
	gcc -c -Wall -W -std=c89 -pedantic -O2 `pkg-config --cflags MLV` src/MainWindow.c -o build/MainWindow.o

build/plateau.o: src/plateau.c src/plateau.h
	gcc -c -Wall -W -std=c89 -pedantic -O2 `pkg-config --cflags MLV` src/plateau.c -o build/plateau.o

build/piece.o: src/piece.c src/piece.h
	gcc -c -Wall -W -std=c89 -pedantic -O2 `pkg-config --cflags MLV` src/piece.c -o build/piece.o

build/save.o:	src/save.c src/save.h
	gcc -c -Wall -W -std=c89 -pedantic -O2 `pkg-config --cflags MLV` src/save.c -o build/save.o

build/scoreboard.o: src/scoreboard.c src/scoreboard.h
	gcc -c -Wall -W -std=c89 -pedantic -O2 `pkg-config --cflags MLV` src/scoreboard.c -o build/scoreboard.o

build/gameWindow.o: src/gameWindow.c src/gameWindow.h
	gcc -c -Wall -W -std=c89 -pedantic -O2 `pkg-config --cflags MLV` src/gameWindow.c -o build/gameWindow.o

clean:
	rm -rf build/*.o *~ Tetris

