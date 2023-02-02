rs ?= nl
RSF = rs.txt
RC = ./main $(args)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -pedantic-errors
VFLAGS = -v -s --show-leak-kinds=all --leak-check=full --track-origins=yes

ifeq (dbg, $(findstring dbg, $(rs)))
	CFLAGS += -g -Og
endif

ifeq (mem, $(findstring mem, $(rs)))
	RC := valgrind $(RC)
endif

FS =

run: clear setup main
	$(RC)

setup:
	@if [ -f "$(RSF)" ] && [ "$$(cat $(RSF))" != "$(rs)" ]; then \
		rm main $(FS); \
	fi

	@echo "$(rs)" > $(RSF)

main: $(FS)
	$(CC) $(CFLAGS) $(FS) -o main

%.o: %.c
	$(CC) $(CFLAGS) -c $?

clear:
	clear

clean:
	rm $(RSF) main $(FS)
