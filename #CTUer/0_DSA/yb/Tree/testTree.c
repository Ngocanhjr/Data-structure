#include "atreelib.h"

int main()
{
    Tree T;
    makeNull(&T);
    readTree(&T);
    PreOrder(root(T), T);
    return 0;
}