//complete postfix
#include <stdio.h>
#include <string.h>
#include <math.h>
char infix[100];
char postfix[100];
char stack[100];
int stackin[100];
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
void evaluate()
{
  printf("In evaluation of postfix expression:");
  int vals[100] = {0}, a = 0, b = 0, result = 0, i;
  for (i = 0; postfix[i] != '\0'; i++)
  {
    if (postfix[i] >= 97 && postfix[i] <= 122)
    {
      printf("Enter value of %c ", postfix[i]);
      scanf("%d", &vals[i]);
    }
  }
  i = 0;
  while (postfix[i] != '\0')
  {

    if (postfix[i] >= 97 && postfix[i] <= 122)
    {
      stackin[++topin] = vals[i];
    }
    else
    {
      b = stackin[topin--];
      a = stackin[topin--];
      switch (postfix[i])
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
    i++;
  }

  result = stackin[topin];
  printf("The result is %d", result);
}
int isEmpty()
{
  if (top == -1)
    return 1;
  else
    return 0;
}
void main()
{
  int i = 0, j = 0;
  char s, x;
  printf("Enter infix expression:");
  gets(infix);
  for (i = 0; i < strlen(infix); i++)
  {
    s = infix[i];
    if (s == '(')
    {
      push(s);
    }
    else if (s == ')')
    {
      while ((x = pop()) != '(')
      {
        postfix[j++] = x;
      }
    }
    else if (s == '+' || s == '-' || s == '*' || s == '/' || s == '^')
    {
      while (!isEmpty() && prec(stack[top]) >= prec(s))
      {
        postfix[j++] = pop();
      }
      push(s);
    }
    else
    {
      postfix[j++] = s;
    }
  }
  while (!isEmpty())
  {
    postfix[j++] = pop();
  }
  postfix[j] = '\0';
  printf("THe required postfix expression is:");
  puts(postfix);
  evaluate(postfix);
}