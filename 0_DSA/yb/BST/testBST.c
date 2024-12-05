#include "libBST.h"

int main() {
    Tree T;
    makeNull(&T);
    insertNode(10, &T);
    insertNode(5, &T);
    insertNode(15, &T);
    insertNode(3, &T);
    insertNode(7, &T);
    insertNode(12, &T);
    insertNode(17, &T);
    insertNode(1, &T);
    printf("Preorder: \n");
    NLR(T);
    printf("\n");
    printf("Delete min %d\n", deleteMin(&T));

    printf("Preorder: \n");
    NLR(T);
    printf("\n");

    printf("Delete 5 \n");
    deleteNode(5, &T);
    printf("Preorder: \n");
    NLR(T);
    printf("\n");

    return 0;
}