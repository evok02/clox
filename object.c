#include <stdio.h>
#include <string.h>

#include "memory.h"
#include "object.h"
#include "value.h" 
#include "vm.h"

#define ALLOCATE_OBJ(type, objectType) \
    (type*)allocateObject(sizeof(type), objectType)

#define ALLOCATE_STRING_OBJ(length) \
    (ObjString*)allocateObject( \
           sizeof(ObjString) + length + 1, OBJ_STRING);


static Obj* allocateObject(size_t size, ObjType type) {
    Obj* object = (Obj*)reallocate(NULL, 0, size);
    object->type = type;

    object->next = vm.objects;
    vm.objects = object;
    return object;
}

static ObjString* allocateString(const char* chars, int length,
                                       uint32_t hash) {
    ObjString* string = ALLOCATE_STRING_OBJ(length);
    string->length = length;
    string->hash = hash;
    memcpy(string->chars, chars, length);
    string->chars[length] = '\0';
    return string;
}

//
// FNV-1a hashing function implementation.
//
static uint32_t hashString(const char* key, int length) {
    uint32_t hash = 2166186261u; // magic number
    for (int i = 0; i < length; i++) { 
        hash ^= (uint8_t)key[i]; // xor magic
        hash *= 16777619; // cherry on top
    }
    return hash; //voila
}

ObjString* takeString(char* chars, int length) {
    uint32_t hash = hashString(chars, length);
    return allocateString(chars, length, hash);
}

ObjString* copyString(const char* chars, int length) {
    uint32_t hash = hashString(chars, length);
    return allocateString(chars, length, hash);
}

void printObject(Value value) {
    switch (OBJ_TYPE(value)) {
        case OBJ_STRING:
            printf("%s", AS_CSTRING(value));
            break;
    }
}

