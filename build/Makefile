CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -pedantic-errors
VPATH = ../src:../lib
CDIR = -I../src -I../lib
SRCDIR =../src ../lib
VFLAGS = -v -s --show-leak-kinds=all --leak-check=full --track-origins=yes

RS ?= nl
RSF = rs.txt
OUT = main
RC = ./$(OUT) $(args)

ifeq (dbg, $(findstring dbg,$(RS)))
	CFLAGS += -g -Og
endif

ifeq (mem, $(findstring mem,$(RS)))
	RC := valgrind $(VFLAGS) $(RC)
endif

FS =
# FS = $(subst .c,.o,$(strip $(shell find $(SRCDIR) -type f -name '*.c' -printf '%f ')))

run: clear setup $(OUT)
	$(RC)

setup:
	@if [ -f "$(RSF)" ] && [ "$$(cat $(RSF))" != "$(RS)" ]; then \
		rm $(OUT) $(FS); \
	fi

	@echo "$(RS)" > $(RSF)

$(OUT): $(FS)
	$(CC) $(CFLAGS) $(FS) -o $(OUT)

%.o: %.c
	 $(CC) $(CFLAGS) $(CDIR) -c $^

fs:
	@echo "$(subst .c,.o,$(strip $(shell find $(SRCDIR) -type f -name '*.c' -printf '%f ')))"

clear:
	clear

clean:
	rm $(RSF) $(OUT) $(FS)
