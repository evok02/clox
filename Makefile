CFLAGS = -Wall -Wextra
DEPENDENCIES = chunk.c memory.c debug.c value.c line.c
DEFAULT_GOAL = run

# TODO:
# read how to make dynamic linking and
# create precompiled libraries

build: 
	@ gcc -o ./bin/clox $(CFLAGS) main.c $(DEPENDENCIES)

build-debug:
	@ gcc -o ./bin/debug -g main.c $(DEPENDENCIES)

run: build
	@ ./bin/clox

debug: build-debug
	@ gdb ./bin/debug
