#include <stdio.h>
#include <stdlib.h>

struct Term
{
    int coeff, exp;
    struct Term *next;
};

struct Term *createTerm(int coeff, int exp)
{
    struct Term *node = malloc(sizeof(struct Term));
    if (node == NULL) exit(1);
    node->coeff = coeff;
    node->exp = exp;
    node->next = NULL;
    return node;
}

void appendTerm(struct Term **head, int coeff, int exp)
{
    struct Term *node, *temp;
    if (coeff == 0) return;

    node = createTerm(coeff, exp);
    if (*head == NULL)
    {
        *head = node;
        return;
    }

    temp = *head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = node;
}

struct Term *readPolynomial(void)
{
    struct Term *poly = NULL;
    int n, i, coeff, exp;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter coefficient and exponent: ");
        scanf("%d%d", &coeff, &exp);
        appendTerm(&poly, coeff, exp);
    }
    return poly;
}

struct Term *addPolynomials(struct Term *a, struct Term *b)
{
    struct Term *result = NULL;

    while (a != NULL && b != NULL)
    {
        if (a->exp == b->exp)
        {
            appendTerm(&result, a->coeff + b->coeff, a->exp);
            a = a->next;
            b = b->next;
        }
        else if (a->exp > b->exp)
        {
            appendTerm(&result, a->coeff, a->exp);
            a = a->next;
        }
        else
        {
            appendTerm(&result, b->coeff, b->exp);
            b = b->next;
        }
    }

    while (a != NULL)
    {
        appendTerm(&result, a->coeff, a->exp);
        a = a->next;
    }

    while (b != NULL)
    {
        appendTerm(&result, b->coeff, b->exp);
        b = b->next;
    }

    return result;
}

void displayPolynomial(struct Term *poly)
{
    if (poly == NULL)
    {
        printf("0\\n");
        return;
    }

    while (poly != NULL)
    {
        printf("%dx^%d", poly->coeff, poly->exp);
        if (poly->next != NULL) printf(" + ");
        poly = poly->next;
    }
    printf("\\n");
}

int main(void)
{
    struct Term *p1, *p2, *sum;

    printf("First polynomial (enter terms in descending exponent order):\\n");
    p1 = readPolynomial();
    printf("Second polynomial (enter terms in descending exponent order):\\n");
    p2 = readPolynomial();

    sum = addPolynomials(p1, p2);
    printf("Sum: ");
    displayPolynomial(sum);
    return 0;
}
