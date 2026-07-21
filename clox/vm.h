#ifndef clox_vm_h
#define clox_vm_h

#include "chunk.h"
#include "table.h"
#include "value.h"

#define STACK_MX 256

typedef struct {
  Chunk* chunk;
  uint8_t* ip;
  Value stack[STACK_MX];
  Value *stackTop;
  Table strings;
  Obj *objects;
} VM;
  
typedef enum {
  INTERPRET_OK,
  INTERPRET_COMPILE_ERROR,
  INTERPRET_RUNTIME_ERROR
} InterpretResult;

VM vm;

void initVM();
void freeVM();
InterpretResult interpret(const char *source);
void push(Value value);
Value pop();

#endif
