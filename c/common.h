#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 4096
typedef double number_t;

#define E 2.718281828459045235360287471352662498L
#define PI 3.141592653589793238462643383279502884L

typedef struct {
  bool success;
  union {
    number_t value;
    char *message;
  };
} result_t;

typedef result_t evaluate_fn(char *);

typedef enum {
  NUMBER = 1,
  CONSTANT = 2,
  UNARY = 3,
  BINARY = 4,
  NOTHING = 5,
  ERROR = 6

} symbol_type_t;

typedef number_t unary_function_t(number_t);
typedef number_t binary_function_t(number_t, number_t);

typedef struct {
  symbol_type_t type;
  union {
    char *message;
    number_t value;
    unary_function_t *unary_function;
    binary_function_t *binary_function;
  };
} symbol_t;

typedef struct {
  const char *keyword;
  symbol_t symbol;
} keyword_t;

int repl(evaluate_fn function);
bool looks_like_a_number(char *expression);
symbol_t next_symbol(char *expression, const keyword_t keywords[],
                     const size_t num_keywords);
