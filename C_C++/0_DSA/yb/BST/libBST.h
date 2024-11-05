#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;

typedef struct Node {
    KeyType key;
    struct Node *left, *right;
} Node;

typedef Node* Tree;

void makeNull(Tree* T) {
    (*T) = NULL;
}

int isEmpty(Tree T) {
    return T == NULL;
}

int isLeaf(Tree T) {
    return T->left == NULL && T->right == NULL;
}

Tree leftTree(Tree n) {
    if (n != NULL) return n->left;
    return NULL;
}

Tree rightTree(Tree n) {
    if (n != NULL) return n->right;
    return NULL;
}

Tree createEmptyTree(KeyType x, Tree T) {
    T = (Node*)malloc(sizeof(Node));
    T->key = x;
    T->left = NULL;
    T->right = NULL;
    return T;
}

Tree search(KeyType x, Tree root) {
    if (root == NULL) {
        printf("Not found!.\n");
        return NULL;
    } else if (x == root->key) {
        return root;
    } else if (x < root->key) {
        search(x, root->left);
    } else {
        search(x, root->right);
    }
}

void insertNode(KeyType x, Tree* T) {
    if (isEmpty(*T)) {
        (*T) = createEmptyTree(x, *T);
    } else {
        // case: x is existing in BTS
        if ((*T)->key == x) {
            printf(">>Key %d is existing in Binary Search Tree!.\n", (*T)->key);
        } else if (x < (*T)->key) {
            insertNode(x, &((*T)->left));
        } else {
            insertNode(x, &((*T)->right));
        }
    }
}

//
KeyType deleteMin(Tree* T) {
    KeyType k;
    if ((*T)->left == NULL) {
        k = (*T)->key;
        Tree temp = *T;
        (*T) = (*T)->right;
        free(temp);
        return k;
    } else {
        return deleteMin(&(*T)->left);
    }
}

void deleteNode(KeyType x, Tree(*T)) {
    if (!isEmpty(*T)) {
        if (x < (*T)->key) {
            deleteNode(x, &((*T)->left));
        } else if (x > (*T)->key) {
            deleteNode(x, &((*T)->right));
        }
        // found x
        else if (isLeaf(*T)) {
            // case 1: x is leaf
            Tree temp = *T; 
            (*T) = NULL;  // delete x
            free(temp);
        }
        // case 2: one subtrees
        else if ((*T)->left == NULL) {
            Tree temp = *T;
            (*T) = (*T)->right;
            free(temp);
        } else if ((*T)->right == NULL) {
            Tree temp = *T;
            (*T) = (*T)->left;
            free(temp);
        } else {
            // case 3: two subtrees
            (*T)->key = deleteMin(&(*T)->right);
        }

    } else {
        printf("Null tree !.\n");
    }
}

// void deleteNode(KeyType x, Tree(*T)) {
//     if (!isEmpty(*T)) {
//         if (x < (*T)->key) {
//             deleteNode(x, &((*T)->left));
//         } else if (x > (*T)->key) {
//             deleteNode(x, &((*T)->right));
//         }
//         // found x
//         else  if ((*T)->left == NULL) {
//             (*T) = (*T)->right;
//         } else if ((*T)->right == NULL) {
//             (*T) = (*T)->left;
//         } else {
//             // case 3: two subtrees
//             (*T)->key = deleteMin(&(*T)->right);
//         }

//     } else {
//         printf("Null tree !.\n");
//     }
// }

Tree create(KeyType v, Tree l, Tree r) {
    Tree createTree = (Node*)malloc(sizeof(Node));
    if (createTree == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    createTree->key = v;
    createTree->left = l;
    createTree->right = r;
    return createTree;
}

void NLR(Tree root) {
    if (!isEmpty(root)) {
        printf("data: %d \n", root->key);
        NLR(root->left);
        NLR(root->right);
    }
}