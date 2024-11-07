MainWindow:
	gcc -Wall -W -std=c89 -pedantic -O2 `pkg-config --cflags MLV` `pkg-config --libs-only-other --libs-only-L MLV` MainWindow.c `pkg-config --libs-only-l MLV` -o MainWindow
clean:
	rm -rf *.o *~ MainWindow