#include <stdio.h>
#include <ctype.h>

#define MAX 200

char stack[MAX];
int top = -1;

void push(char ch)
{
    if (top < MAX - 1) stack[++top] = ch;
}

char pop(void)
{
    if (top == -1) return '\\0';
    return stack[top--];
}

int precedence(char op)
{
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

void infixToPostfix(char infix[], char postfix[])
{
    int i, j = 0;
    char ch;

    for (i = 0; infix[i] != '\\0'; i++)
    {
        ch = infix[i];

        if (ch == ' ' || ch == '\\t') continue;

        if (isalnum((unsigned char)ch))
            postfix[j++] = ch;
        else if (ch == '(')
            push(ch);
        else if (ch == ')')
        {
            while (top != -1 && stack[top] != '(')
                postfix[j++] = pop();
            if (top != -1) pop();
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            while (top != -1 && stack[top] != '(' &&
                   precedence(stack[top]) >= precedence(ch))
                postfix[j++] = pop();
            push(ch);
        }
    }

    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\\0';
}

int main(void)
{
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression (single-character operands): ");
    scanf("%199s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\\n", postfix);
    return 0;
}
