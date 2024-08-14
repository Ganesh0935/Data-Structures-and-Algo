//complete prefix
#include <stdio.h>
#include <string.h>
#include <math.h>
char infix[100];
char prefix[100];
char stack[100];
int stackin[100] = {0};
int top = -1, topin = -1;
int prec(char y)
{
  switch (y)
  {
  case '^':
    return 3;
    break;
  case '*':
  case '/':
    return 2;
    break;
  case '+':
  case '-':
    return 1;
    break;
  default:
    return 0;
    break;
  }
}
void push(char y)
{
  top = top + 1;
  stack[top] = y;
}
char pop()
{
  char x = stack[top];
  top = top - 1;
  return x;
}
int isEmpty()
{
  if (top == -1)
    return 1;
  else
    return 0;
}
void evaluate()
{
  // in prefix evaluation
  int vals[100] = {0}, i, a = 0, b = 0, result;
  for (i = 0; i < strlen(prefix); i++)
  {
    if (prefix[i] >= 97 && prefix[i] <= 122)
    {
      printf("Enter value of %c", prefix[i]);
      scanf("%d", &vals[i]);
    }
  }
  i = strlen(prefix) - 1;
  while (i >= 0)
  {
    if (prefix[i] >= 97 && prefix[i] <= 122)
    {
      stackin[++topin] = vals[i];
    }
    else
    {
      a = stackin[topin--];
      b = stackin[topin--];
      switch (prefix[i])
      {
      case '+':
      {
        result = a + b;
        break;
      }
      case '-':
      {
        result = a - b;
        break;
      }
      case '*':
      {
        result = a * b;
        break;
      }
      case '/':
      {
        result = a / b;
        break;
      }
      case '%':
      {
        result = a % b;
        break;
      }
      case '^':
      {
        result = pow(a, b);
        break;
      }
      }
      stackin[++topin] = result;
    }
    i--;
  }
  result = stackin[topin];
  printf("The result is %d", result);
}
void main()
{
  int i = 0, j = 0;
  char s, x;
  printf("Enter infix expression:");
  gets(infix);
  strrev(infix);
  for (i = 0; i < strlen(infix); i++)
  {
    s = infix[i];
    if (s == ')')
    {
      push(s);
    }
    else if (s == '(')
    {
      while ((x = pop()) != ')')
      {
        prefix[j++] = x;
      }
    }
    else if (s == '+' || s == '-' || s == '*' || s == '/' || s == '^')
    {
      while (!isEmpty() && prec(stack[top]) > prec(s))
      {
        prefix[j++] = pop();
      }
      push(s);
    }
    else
    {
      prefix[j++] = s;
    }
  }
  while (!isEmpty())
  {
    prefix[j++] = pop();
  }
  prefix[j] = '\0';
  printf("\nTHe required prefix expression is:");
  strrev(prefix);
  puts(prefix);
  evaluate(prefix);
}