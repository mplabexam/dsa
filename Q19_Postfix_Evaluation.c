#include <stdio.h>
#include <ctype.h>

#define MAX 200

int stack[MAX], top = -1;

void push(int value)
{
    if (top < MAX - 1) stack[++top] = value;
}

int pop(void)
{
    if (top == -1) return 0;
    return stack[top--];
}

int performOperation(int a, int b, char op)
{
    switch (op)
    {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return (b != 0) ? a / b : 0;
        default: return 0;
    }
}

/* This version supports single-digit operands, e.g. 23*54*+ */
int evaluatePostfix(char exp[])
{
    int i, a, b;

    for (i = 0; exp[i] != '\\0'; i++)
    {
        if (exp[i] == ' ') continue;

        if (isdigit((unsigned char)exp[i]))
            push(exp[i] - '0');
        else
        {
            b = pop();
            a = pop();
            push(performOperation(a, b, exp[i]));
        }
    }

    return pop();
}

int main(void)
{
    char exp[MAX];

    printf("Enter postfix expression (single-digit operands): ");
    scanf("%199s", exp);

    printf("Result: %d\\n", evaluatePostfix(exp));
    return 0;
}
