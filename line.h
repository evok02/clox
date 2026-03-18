#ifndef clox_line_h
#define clox_line_h

#include "common.h"

typedef struct {
    int number;
    int repeat;
} Line;

typedef struct {
    uint16_t* number;
    uint8_t* repeat;
    uint16_t capacity;
    uint16_t count;
} LineArray;

void initLineArray(LineArray* array);
void writeLineArray(LineArray* array, uint16_t line);
void freeLineArray(LineArray* array);
uint16_t getLine(LineArray* array, uint16_t idx);

#endif

