#include "common.h"
#include <ctype.h>
#include <string.h>

void rstrip(char *expression) {
  int length = strlen(expression);
  for (int i = length - 1; i >= 0 && isspace(expression[i]); --i) {
    expression[i] = 0;
  }
}

int repl(evaluate_fn function) {
  char buffer[STACK_SIZE];
  while (true) {
    printf(">>> ");
    if (fgets(buffer, STACK_SIZE - 1, stdin) != buffer) {
      printf("exiting\n");
      return EXIT_SUCCESS;
    }
    rstrip(buffer);
    result_t result = function(buffer);
    if (result.success) {
      printf("%lf\n", result.value);
    } else if (result.message != NULL) {
      fprintf(stderr, "ERROR: %s\n", result.message);
      return EXIT_FAILURE;
    } else {
      break;
    }
  }
  return EXIT_SUCCESS;
}

bool looks_like_a_number(char *expression) {
  return isdigit(expression[0]) ||
         (expression[0] == '-' && isdigit(expression[1]));
}

symbol_t next_symbol(char *expression, const keyword_t keywords[],
                     const size_t num_keywords) {
  symbol_t symbol = {.type = ERROR};
  char *token = strtok(expression, " ");
  if (token != NULL) {
    if (looks_like_a_number(token)) {
      number_t number = atof(token);
      symbol.type = NUMBER;
      symbol.value = number;
    } else {
      for (size_t i = 0; i < num_keywords; ++i) {
        if (strcmp(token, keywords[i].keyword) == 0) {
          symbol = keywords[i].symbol;
          break;
        }
      }
      if (symbol.type == ERROR) {
        symbol.message = "UNKNOWN KEYWORDS";
      }
    }
  } else {
    symbol.type = NOTHING;
  }
  return symbol;
}
