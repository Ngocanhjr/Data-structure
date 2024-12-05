#include "ptreelib.h"

int main()
{
    Tree T;
    makeNull(&T);
    T = create('A', create('B', create('D', NULL, NULL), create('E', NULL, NULL)), create('C', create('F', NULL, NULL), create('G', NULL, NULL)));
    LNR(T);
    return 0;
}