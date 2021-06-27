#include <stdio.h>
#include <stdlib.h> // for dynamic memory allocation
#include <string.h> // for checking the length of the expression using strlen()
// Structure representing stack
struct Stack
{
    char *array; // stores the elements in the stack
    int top;     // index of the top element
    int maxSize; // Maximum size of the stack
};
// isFull() for checking if the stack is full
int isFull(struct Stack *s)
{
    if (s->top == s->maxSize - 1)
    { // when top is equal to the last index, the stack is full
        return 1;
    }
    else
        return 0;
}
// isEmpty() for checking if the stack is empty
int isEmpty(struct Stack *s)
{
    // when top is equal to -1, the stack is empty
    if (s->top == -1)
    {
        return 1;
    }
    else
        return 0;
}
// Push function
void push(struct Stack *s, char ch)
{
    if (isFull(s))
    {
       printf("Stack is full!");
    }
    s->array[++s->top] = ch;
}
// Pop function
int pop(struct Stack *s)
{
    if (isEmpty(s))
    {
        return 0;
    }
    s->top--;
    return 1;
}
int main()
{
    int expSize, i, ret;
    char exp[30];
    struct Stack s;
    s.top = -1;                     // initializing top to -1.
    printf("\t\t BALANCED PARENTHESIS \n");
    printf("Enter the expression : ");
    gets(exp);                   // input the expression using gets()
    expSize = strlen(exp);      // using strlen() to find the length of the expression.
    s.maxSize = expSize;        // assigning the size of the expression as the maximum size of the stack.
    s.array = (char *)malloc(s.maxSize * sizeof(char)); // allocating memory
    for (i = 0; i < expSize; i++)
    {
        // check if the character is a opening bracket.
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(&s, exp[i]); // if the character is the starting bracket,then push into the stack.
        }
        // check if the character is the closing bracket.
        if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            // if the character is a closing bracket, check if the top of the stack is the pair of the character.
            if ((s.array[s.top] == '(' && exp[i] == ')') || (s.array[s.top] == '{' && exp[i] == '}') || (s.array[s.top] == '[' && exp[i] == ']'))       // <---- part extracted from Aditya Kotwal's code
            {
                // if matching pairs are found, pop from the stack.
                ret = pop(&s);
            }
            else
            {
                printf("Expression is Not Balanced. \n");
                return 0;
            }    
        }
    }
    if (isEmpty(&s))
    {
        // if the stack is empty, the expression is balanced.
        printf("Expression is Balanced. \n");
    }
    else
    {
        // if the stack is not empty, the expression is not balanced.
        printf("Expression is Not Balanced. \n");
    }
    return 0;
}
