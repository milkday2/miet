// задание 1, проверка количества скобок в строке с помощью стека
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct char_stack {
  char *stack;
  size_t size;
  size_t count;
} char_stack;

void init_stack(char_stack *stack, size_t size);
void free_stack(char_stack *stack);
int push(char_stack *stack, char c);
int pop(char_stack *stack, char *c);

int read_expression(char *string);

int main(void) {
  char string[128];
  printf("input a string until a space or newline,\n"
         "brackets must match:\n");
  if (!read_expression(string))
    printf("%s\n", string);
  return 0;
}

int read_expression(char *string) {
  char buf[128];
  char_stack stack;
  init_stack(&stack, 32);
  int i = 0;
  char ch = getchar();
  while (ch != '\n' && ch != ' ') {
    buf[i++] = ch;
    if (ch == '(') {
      if (push(&stack, ch)) {
        printf("character stack overflow\n");
        free_stack(&stack);
        return 1;
      }
    }
    if (ch == ')') {
      if (pop(&stack, &ch)) {
        printf("unmatched closing bracket!\n");
        free_stack(&stack);
        return 1;
      }
    }
    ch = getchar();
  }
  if (stack.count != 0) {
    printf("unmatched opening bracket!\n");
    free_stack(&stack);
    return 1;
  }
  buf[i] = '\0';
  strcpy(string, buf);
  free_stack(&stack);
  return 0;
}

void init_stack(char_stack *stack, size_t size) {
  stack->stack = malloc(size * sizeof(char));
  stack->size = size;
  stack->count = 0;
}
void free_stack(char_stack *stack) { free(stack->stack); }

int push(char_stack *stack, char c) {
  if (stack->count == stack->size)
    return 1;
  stack->stack[(stack->count)++] = c;
  return 0;
}

int pop(char_stack *stack, char *c) {
  if (stack->count < 1)
    return 1;
  *c = stack->stack[--(stack->count)];
  return 0;
}
