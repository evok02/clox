CFLAGS = -Wall -Wextra
DEPENDENCIES = chunk.c memory.c debug.c value.c
DEFAULT_GOAL = run

# TODO:
# read how to make dynamic linking and
# create precompiled libraries

build: 
	@ gcc -o ./bin/clox $(CFLAGS) main.c $(DEPENDENCIES)

run: build
	@ ./bin/clox
