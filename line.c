#include "line.h"
#include "memory.h"

void initLineArray(LineArray* array) {
    array->count = 0;
    array->capacity = 0;
    array->number = NULL;
    array->repeat = NULL;
}

void writeLineArray(LineArray* array, uint16_t line) {
    if (array->capacity < array->count + 1) {
        int oldCapacity = array->capacity;
        array->capacity = GROW_CAPACITY(oldCapacity);
        array->number = GROW_ARRAY(uint16_t, array->number,
                   oldCapacity, array->capacity);
        array->repeat = GROW_ARRAY(uint8_t, array->repeat,
                   oldCapacity, array->capacity);
    }
    
    if (array->number[array->count - 1] == line) {
        array->repeat[array->count]++;
    } else {
        array->number[array->count] = line; 
        array->repeat[array->count] = 1;
        array->count++;
    }
}

void freeLineArray(LineArray* array) {
    FREE_ARRAY(int, array->number, array->count);
    FREE_ARRAY(int, array->repeat, array->count);
    initLineArray(array);
}

uint16_t getLine(LineArray* array, uint16_t idx) {
    int32_t sum = 0;
    for (uint16_t i = 0; i < array->count; i++) {
        sum += array->repeat[i];
        if (sum - 1 >= idx) return array->number[i];
    }
    return 0;
}
