#ifndef clox_vm_h
#define clox_vm_h

#include "chunk.h"
#include "value.h"
#include "table.h"

#define STACK_MAX 4096
#define STACK_MIN 256 

typedef struct {
    Chunk* chunk; // chunk of bytecode
    uint8_t* ip; //instruction pointer
    Value* stack;
    size_t stackCapacity;
    Value* stackTop;
    Table globals;
    Table strings;
    Obj* objects; // pointer to the heap 
} VM;

extern VM vm;

typedef enum {
    INTERPRET_OK, 
    INTERPRET_COMPILE_ERROR,
    INTERPRET_RUNTIME_ERROR
} InterpretResult;

void initVM();
void freeVM();
InterpretResult interpret(char* source);
void push(Value value);
Value pop();

#endif 
