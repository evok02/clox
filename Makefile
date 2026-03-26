CFLAGS = -Wall -Wextra
DEPENDENCIES = chunk.c memory.c debug.c value.c \
			   line.c vm.c scanner.c compiler.c \
			   object.c table.c
DEFAULT_GOAL = run
LOX_FILE = ./main.txt

# TODO:
# read how to make dynamic linking and
# create precompiled libraries

build: 
	@ gcc -o ./bin/clox $(CFLAGS) main.c $(DEPENDENCIES)

build-debug:
	@ gcc -o ./bin/debug -g main.c $(DEPENDENCIES)

run: build
	@ ./bin/clox

run-file: build
	@ ./bin/clox $(LOX_FILE)

debug: build-debug
	@ gdb ./bin/debug
