
#include "dastacklib.h"


int Fibo(int n)
{
    ElementType result = 0;
    Stack store;
    makeNull(&store);
    push(n, &store);
    while (!isEmpty(store))
    {
        n = pop(&store);
        if (n == 1 || n == 2)
        {
            result += 1;
        }
        else
        {
            push(n - 1, &store);
            push(n - 2, &store);
        }
        // printf("%d ", n);
    }
    return result;
}

int C(ElementType n, ElementType k)
{
    Stack store;
    makeNull(&store);
    ElementType result = 0;
    push(k, &store);
    push(n, &store);

    while (!isEmpty(store))
    {
        n = pop(&store);
        k = pop(&store);
        if (k == 0 || k == n)
        {
            result++;
        }
        else if (k == 1)
        {
            result += n;
        }
        else
        {
            push(k - 1, &store);
            push(n - 1, &store);
            push(k, &store);
            push(n - 1, &store);
        }
    }
    return result;
}

int main()
{
    int result;
    result = Fibo(30);
    printf("Fibo: %d \n", result);
    int c = C(15, 3);
    printf("C: %d \n", c);
}