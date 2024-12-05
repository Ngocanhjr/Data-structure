#include "1_bstlib.h"

KeyType deleteMax(Tree* tr) {
    if ((*tr)->right != NULL)
        return deleteMin(&((*tr)->right));
    else {
        Tree temp = (*tr);
        KeyType x = temp->key;
        (*tr)->right = temp->left;

        free(temp);
        printf("%d\n", x);

        return x;
    }
}

void deleteNodeByT(KeyType x, Tree* tr) {
    if ((*tr) != NULL) {
        if (x < (*tr)->key)
            deleteNodeByT(x, &((*tr)->left));
        else if (x > (*tr)->key)
            deleteNodeByT(x, &((*tr)->right));
        else {
            if ((*tr)->left == NULL && (*tr)->right == NULL) {
                free((*tr));
                (*tr) = NULL;
            } else if ((*tr)->left == NULL) {
                Tree temp = (*tr);
                (*tr) = (*tr)->right;
                free(temp);
                // temp = NULL;
            } else if ((*tr)->right == NULL) {
                Tree temp = (*tr);
                (*tr) = (*tr)->left;
                free(temp);
                // temp = NULL;
            } else {
                Tree minNode = (*tr)->right;
                while (minNode->left != NULL) minNode = minNode->left;
                (*tr)->key = minNode->key;

                deleteNodeByT(minNode->key, &((*tr)->right));
            }
        }
    }
}

int main() {
    Tree T;
    T = readTree();
    printf("Prefix: ");
    NLR(T);
    printf("\n");

    T = delete_node(3, T);

    printf("Prefix: ");
    NLR(T);
    printf("\n");

    LNR(T);

    // print_path(56, T);
    // printf("\n");
    // KeyType x = findMax(T);
    // printf("Max: %d\n", x);
    // printf("height: %d\n", get_height(T));
    // printf("Infix: ");
    // LNR(T);
    // printf("\n");

    // printf("Profix: ");
    // LRN(T);
    // printf("\n");

    // printf("Count node: %d\n", nb_nodes(T));
    // printf("Count leaf: %d\n", countLeaf(T));

    // Tree s;
    // makeNull(&s);
    // s = search(56,T);
    // printf("Search Infix: ");
    // if(isEmptyTree(s)){
    // 	printf("Not found!\n");
    // } else {
    // 	LNR(s);
    // 	printf("\n");
    // }

    // s = search(7,T);
    // printf("Search Infix: ");
    // if(isEmptyTree(s)){
    // 	printf("Not found!\n");
    // } else {
    // 	LNR(s);
    // 	printf("\n");
    // }

    // printf("Delete Node\n");
    // int xoa;
    // printf("Nhap vao phan tu muon xoa: ");
    // scanf("%d", &xoa);
    // deleteNode(xoa,&T);
    // printf("Prefix: ");
    // NLR(T);
    // printf("\n");
    // deleteNode(xoa,&T);
    // printf("Prefix: ");
    // NLR(T);
    // printf("\n");
    // deleteNode(xoa,&T);
    // printf("Prefix: ");
    // NLR(T);
    // printf("\n");
}
