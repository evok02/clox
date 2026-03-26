#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"
#include "value.h"
#include "line.h"

typedef enum {
    OP_CONSTANT,
    OP_NIL,
    OP_TRUE,
    OP_FALSE,
    OP_DEFINE_GLOBAL,
    OP_EQUAL,
    OP_GREATER,
    OP_LESS,
    OP_RETURN,
    OP_NEGATE,
    OP_ADD,
    OP_SUBTRACT,
    OP_MULTIPLY,
    OP_DIVIDE,
    OP_NOT,
    OP_PRINT,
    OP_POP,
    OP_GET_GLOBAL,
    OP_SET_GLOBAL,
} OpCode;

typedef struct {
    int count;
    int capacity;
    uint8_t* code;
    ValueArray constants;
    LineArray lines;
} Chunk;

void initChunk(Chunk* chunk);
void freeChunk(Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t byte, uint16_t line);
int addConstant(Chunk* chunk, Value value);
int addLine(Chunk* chunk, uint16_t line);

#endif

