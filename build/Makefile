CFLAGS=-Wall -Wextra -Werror -pedantic -pedantic-errors
DBGCFLAGS=-Wall -Wextra -Werror -pedantic -pedantic-errors -g -Og
VFLAGS=-v -s --show-leak-kinds=all --leak-check=full --track-origins=yes

LIBS=
SLIBS=

run: main
	./main $(args)

mem: main_dbg
	valgrind $(VFLAGS) ./main_dbg $(args)

main: clear main.c $(LIBS)
	gcc $(CFLAGS) -c main.c
	gcc $(CFLAGS) main.o $(LIBS) -o main

main_dbg: clear main.c $(LIBS)
	gcc $(DBGCFLAGS) -c main.c
	gcc $(DBGCFLAGS) main.o $(LIBS) -o main_dbg

$(LIBS): $(SLIBS)
	gcc $(CFLAGS) -c $(SLIBS)

clear:
	clear

clean:
	rm main main_dbg main.o $(LIBS)
