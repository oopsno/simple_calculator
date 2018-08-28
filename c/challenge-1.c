/**
 * 第一道题
 * --------
 * 题目描述：解析“逆波兰表达式”法表示的一串整数四则运算。
 * 样例输入：1 2 3 + *
 * 样例解释：相当于 1*(2+3)
 * 样例输出：5
 *
 * 改进：支持负数(negative)，例题 "-1 1 +"，应输出 0
 * 改进：支持浮点数(float)，例题 "0.3 0.5 +"，相当于 0.3+0.5，应输出
 * 0.8，可能有误差，不管 改进：支持数学常量 pi 和 e，例题
 * "pi"，应输出 3.1415926，我忘了精度能到多少了，不管不管能输出就行
 * 改进：支持三角函数 sin cos tan，例题 "pi 2 / sin"，相当于 sin(pi/2)，应输出
 * 0.5
 */

#include <ctype.h>
#include <math.h>
#include <string.h>
#include "common.h"

number_t op_add(number_t lhs, number_t rhs) { return lhs + rhs; }
number_t op_sub(number_t lhs, number_t rhs) { return lhs - rhs; }
number_t op_mul(number_t lhs, number_t rhs) { return lhs * rhs; }
number_t op_div(number_t lhs, number_t rhs) { return lhs / rhs; }

keyword_t KEYWORDS[] = {
    {.keyword = "e", .symbol = {.type = CONSTANT, .value = E}},
    {.keyword = "pi", .symbol = {.type = CONSTANT, .value = PI}},
    {.keyword = "sin", .symbol = {.type = UNARY, .unary_function = sin}},
    {.keyword = "cos", .symbol = {.type = UNARY, .unary_function = cos}},
    {.keyword = "tan", .symbol = {.type = UNARY, .unary_function = tan}},
    {.keyword = "+", .symbol = {.type = BINARY, .binary_function = op_add}},
    {.keyword = "-", .symbol = {.type = BINARY, .binary_function = op_sub}},
    {.keyword = "*", .symbol = {.type = BINARY, .binary_function = op_mul}},
    {.keyword = "/", .symbol = {.type = BINARY, .binary_function = op_div}}};

static const size_t NUM_KEYWORDS = sizeof(KEYWORDS) / sizeof(keyword_t);

result_t evaluate(char *expression) {
  number_t stack[STACK_SIZE];
  size_t top = 0;
  result_t result = {.success = false, .message = NULL};
  for (symbol_t symbol = next_symbol(expression, KEYWORDS, NUM_KEYWORDS);
       symbol.type != NOTHING;
       symbol = next_symbol(NULL, KEYWORDS, NUM_KEYWORDS)) {
    switch (symbol.type) {
      case NUMBER:
      case CONSTANT:
        if (top < STACK_SIZE - 1) {
          stack[++top] = symbol.value;
        } else {
          result.message = "STACK OVERFLOW";
        }
        break;
      case UNARY:
        if (top >= 1) {
          stack[top] = symbol.unary_function(stack[top]);
        } else {
          result.message = "EMPTY STACK";
        }
        break;
      case BINARY:
        if (top >= 2) {
          stack[top - 1] = symbol.binary_function(stack[top - 1], stack[top]);
          top -= 1;
        } else {
          result.message = "NO ENOUGH ARGUMENTS ON STACK";
        }
        break;
      default:
        break;
    }
  }
  if (result.message == NULL) {
    result.success = true;
    result.value = stack[top];
  }
  return result;
}

int main() { return repl(evaluate); }
