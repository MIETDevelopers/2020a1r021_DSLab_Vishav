#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
struct stack
{
    int maxSize;
    int top;
    char *stack;
};
bool isEmp(struct stack *stack)
{
    if (stack->top == -1)
    {
        return true;
    }
    return false;
}
bool isFul(struct stack *stack)
{
    if (stack->top == stack->maxSize - 1)
    {
        return true;
    }
    return false;
}
bool push(struct stack *stack, char e)
{
    if (isFul(stack))
    {
        return false;
    }
    stack->top++;
    stack->stack[stack->top] = e;
    return true;
}
bool pop(struct stack *stack)
{
    if (isEmp(stack))
    {
        return false;
    }
    stack->top--;
    return true;
}
int main()
{
    struct stack stackA;
    stackA.top = 0;
    int sizeOfExp;
    char exp[100];
    printf("Now enter expression:");
    scanf("%stack", exp);
    sizeOfExp = strlen(exp);
    stackA.stack = (char *)malloc(sizeof(char) * sizeOfExp);
    stackA.maxSize = sizeOfExp;

    for (int i = 0; i < sizeOfExp; i++)
    {
        if (exp[i] == '{' || exp[i] == '[' || exp[i] == '(')
        {
            push(&stackA, exp[i]);
            continue;
        }
        if (exp[i] == '}' || exp[i] == ']' || exp[i] == ')')
        {
            if ((stackA.stack[stackA.top] == '{' && exp[i] == '}') || (stackA.stack[stackA.top] == '(' && exp[i] == ')') || (stackA.stack[stackA.top] == '[' && exp[i] == ']'))
            {
                pop(&stackA);
            }
            else
            {
                printf("UNBALANCED\n");
                return 0;
            }
        }
    }
    if (stackA.top == 0)
    {
        printf("BALANCED\n");
    }
    else
    {
        printf("UNBALANCED\n");
    }

    return 0;
}
