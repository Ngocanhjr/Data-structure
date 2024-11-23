
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#define BALANCE 0
#define LEFT 1
#define RIGHT 2
typedef int KeyType;

typedef struct AVLNode {
    KeyType key;
    int bal;
    int height;
    struct AVLNode* Left;
    struct AVLNode* Right;
} AVLNode;

typedef AVLNode* AVLTree;

void MakeNullTree(AVLTree* T) {
    (*T) = NULL;
}

// Ham tao nut co khoa x, chieu cao =0, con trai va con phai NULL
AVLNode createAVLNode(KeyType x) {
}

int height(AVLNode node) {
}

AVLNode* rotateLeft(AVLNode* pNode) {
}
AVLNode* rotateRight(AVLNode* pNode) {
}

AVLNode* rotateLeftRight(AVLNode* pNode) {
}

AVLNode* rotateRightLeft(AVLNode* pNode) {
}

AVLTree* insertNode(KeyType x, AVLTree* root) {
}

void preOrder(AVLTree root) {
}

void inOrder(AVLTree root) {
}

void PosOrder(AVLTree root) {
}

void levelOrder(AVLTree root) {
}