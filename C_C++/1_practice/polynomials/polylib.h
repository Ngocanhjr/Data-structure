#include <stdio.h>
#include <stdlib.h>

#define MAX_MONOMIAL 100

typedef struct Monomial
{
    float factor;
    int exponent;
} Monomial;

typedef struct Polynomial
{
    Monomial element[MAX_MONOMIAL];
    int size;
} Polynomial;

void makeNull(Polynomial *P)
{
    P->size = 0;
}

int isEmpty(Polynomial P)
{
    return P.size == 0;
}

void addMonomialIntoPolynomial(Monomial mono, Polynomial *poly)
{
    if (mono.factor == 0)
        return;
    int length = poly->size;
    for (int i = 0; i < length; i++)
    {
        if (mono.exponent == poly->element[i].exponent)
        {
            poly->element[i].factor += mono.factor;
            return;
        }
    }
    poly->element[poly->size] = mono;
    poly->size++;
}

void sort(Polynomial *poly)
{
    int length = poly->size;
    for (int i = 0; i < length - 1; i++)
    {
        int max_pos = i;
        for (int j = i + 1; j < length; j++)
        {
            if (poly->element[max_pos].exponent < poly->element[j].exponent)
            {
                max_pos = j;
            }
        }
        if (max_pos == i)
            continue;
        Monomial temp = poly->element[i];
        poly->element[i] = poly->element[max_pos];
        poly->element[max_pos] = temp;
    }
}

Polynomial read()
{
    Polynomial newPoly;
    makeNull(&newPoly);
    int size;
    printf("Enter number of monomials: ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        Monomial newMono;
        printf("Enter the coefficient and exponent at %d: ", i + 1);
        scanf("%f %d", &newMono.factor, &newMono.exponent);
        addMonomialIntoPolynomial(newMono, &newPoly);
    }
    printf("---------------------------------------\n");
    sort(&newPoly);
    return newPoly;
}

void print(Polynomial p)
{
    if (isEmpty(p))
    {
        printf("Empty polynomial!");
        return;
    }
    int length = p.size;
    printf("Polynomial: ");
    for (int i = 0; i < length; i++)
    {
        if ((float)p.element[i].factor == 0)
            continue;
        if (p.element[i].exponent == 1)
        {
            printf("%.1fX", p.element[i].factor);
        }
        else if (p.element[i].exponent == 0)
        {
            printf("%.1f", p.element[i].factor);
        }
        else
        {
            printf("%.1fX^%d", p.element[i].factor, p.element[i].exponent);
        }
        if (i != length - 1)
        {
            printf(" + ");
        }
    }
    printf("\n---------------------------------------\n");
}

Polynomial add(Polynomial poly1, Polynomial poly2)
{
    int idxPoly1 = 0, idxPoly2 = 0;
    Polynomial newPoly;
    makeNull(&newPoly);
    while (idxPoly1 != poly1.size && idxPoly2 != poly2.size)
    {
        if (poly1.element[idxPoly1].exponent > poly2.element[idxPoly2].exponent)
        {
            addMonomialIntoPolynomial(poly1.element[idxPoly1], &newPoly);
            idxPoly1++;
        }
        else if (poly1.element[idxPoly1].exponent < poly2.element[idxPoly2].exponent)
        {
            addMonomialIntoPolynomial(poly2.element[idxPoly2], &newPoly);
            idxPoly2++;
        }
        else
        {
            Monomial newMono;
            newMono.factor = poly1.element[idxPoly1].factor + poly2.element[idxPoly2].factor;
            newMono.exponent = poly1.element[idxPoly1].exponent;
            addMonomialIntoPolynomial(newMono, &newPoly);
            idxPoly1++;
            idxPoly2++;
        }
    }
    while (idxPoly1 != poly1.size)
    {
        addMonomialIntoPolynomial(poly1.element[idxPoly1], &newPoly);
        idxPoly1++;
    }
    while (idxPoly2 != poly2.size)
    {
        addMonomialIntoPolynomial(poly2.element[idxPoly2], &newPoly);
        idxPoly2++;
    }
    sort(&newPoly);
    return newPoly;
}

Polynomial derivative(Polynomial poly)
{
    Polynomial newPoly;
    makeNull(&newPoly);
    for (int i = 0; i < poly.size; i++)
    {
        if (poly.element[i].exponent == 0)
        {
            newPoly.element[i].factor = 0;
            newPoly.size++;
            continue;
        }
        newPoly.element[i].factor = poly.element[i].factor * (poly.element[i].exponent);
        newPoly.element[i].exponent = poly.element[i].exponent - 1;
        newPoly.size++;
    }
    return newPoly;
}