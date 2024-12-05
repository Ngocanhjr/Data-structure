
#include <stdio.h>
#include <stdlib.h>
typedef int KeyType;

typedef struct Node {
    KeyType key;
    struct Node* left;
    struct Node* right;
} Node;

typedef Node* Tree;
Tree T;

void makeNull(Tree* T) {
    (*T) = NULL;
}

int isEmptyTree(Tree T) {
    return T == NULL;
}

Tree leftChild(Tree n) {
    if (n != NULL) {
        return n->left;
    } else {
        return NULL;
    }
}

Tree rightChild(Tree n) {
    if (n != NULL) {
        return n->right;
    } else {
        return NULL;
    }
}

int isLeaf(Tree n) {
    if (n != NULL) {
        //		return n->left == NULL && n->right == NULL
        return (leftChild(n) == NULL) && (rightChild(n) == NULL);
    }
    return 0;
}
Tree creat2(KeyType v, Tree left, Tree right) {
    Tree N;
    N = (Node*)malloc(sizeof(Node));
    N->key = v;
    N->left = left;
    N->right = right;
    return N;
}

void NLR(Tree root) {
    if (!isEmptyTree(root)) {
        printf("%d ", root->key);
        NLR(leftChild(root));
        NLR(rightChild(root));
    }
}

void LNR(Tree root) {
    if (!isEmptyTree(root)) {
        LNR(root->left);
        printf("%d ", root->key);
        LNR(root->right);
    }
}

void LRN(Tree root) {
    if (!isEmptyTree(root)) {
        LRN(root->left);
        LRN(root->right);
        printf("%d ", root->key);
    }
}

int nb_nodes(Tree root) {
    if (isEmptyTree(root)) {
        return 0;
    } else
        return 1 + nb_nodes(leftChild(root)) + nb_nodes(rightChild(root));
}

int countLeaf(Tree T) {
    if (isEmptyTree(T)) {
        return 0;
    } else if (isLeaf(T)) {
        return 1;
    } else {
        return countLeaf(leftChild(T)) + countLeaf(rightChild(T));
    }
}

Tree search(KeyType key, Tree root) {
    // O(h): h la chieu cao cay
    if (isEmptyTree(root)) {
        return NULL;
    } else if (key == root->key) {
        return root;
    } else if (key < root->key) {
        return search(key, root->left);
    } else {
        return search(key, root->right);
    }
}

void insert(KeyType key, Tree* T) {
    if (isEmptyTree(*T)) {
        (*T) = (Node*)malloc(sizeof(Node));
        (*T)->key = key;
        (*T)->left = NULL;
        (*T)->right = NULL;
    } else if (key < (*T)->key) {
        insert(key, &((*T)->left));
    } else if (key > (*T)->key) {
        insert(key, &((*T)->right));
    }
}

// Case 1: 0 con thay bang null, 1 con thay no bang con, 2con
KeyType deleteMin(Tree* T) {
    KeyType key;
    Tree temp;
    if (((*T)->left) == NULL) {
        temp = (*T);
        key = (*T)->key;
        (*T) = (*T)->right;
        free(temp);
        return key;
    } else {
        return deleteMin(&((*T)->left));
    }
}

KeyType deleteMinByT(Tree* tr) {
    if ((*tr)->left != NULL)
        return deleteMin(&((*tr)->left));
    else {
        // if ((*tr)->right != NULL) {
        Tree temp = (*tr);
        KeyType x = temp->key;
        (*tr) = temp->right;

        free(temp);
        printf("%d\n", x);

        return x;
        // }
    }
}

void deleteNode(KeyType x, Tree* T) {
    Tree temp;
    if (!isEmptyTree(*T)) {
        // Tim x
        if (x < (*T)->key) {
            deleteNode(x, &((*T)->left));
        } else if (x > (*T)->key) {
            deleteNode(x, &((*T))->right);
        } else {  // found x
            if (isLeaf(*T)) {
                temp = (*T);
                (*T) = NULL;
                free(temp);
            } else if ((*T)->left == NULL && (*T)->right != NULL) {
                temp = (*T);
                (*T) = (*T)->right;
                free(temp);
            } else if ((*T)->right == NULL && (*T)->left != NULL) {
                temp = (*T);
                (*T) = (*T)->left;
                free(temp);
            } else {
                (*T)->key = deleteMin(&((*T)->right));
            }
        }
    }
}

KeyType delete_min(Tree* T) {
    KeyType key;
    Tree temp;
    if (((*T)->left) == NULL) {
        temp = (*T);
        key = (*T)->key;
        (*T) = (*T)->right;
        free(temp);
        return key;
    } else {
        return delete_min(&((*T)->left));
    }
}

Tree delete_node(KeyType x, Tree T) {
    Tree temp;
    if (T != NULL) {
        // Tim x
        if (x < (T)->key) {
            T->left = delete_node(x, ((T)->left));
        } else if (x > (T)->key) {
            T->right = delete_node(x, ((T))->right);
        } else {  // found x
            if ((T)->left == NULL && (T)->right == NULL) {
                temp = (T);
                (T) = NULL;
                free(temp);
            } else if ((T)->left == NULL && (T)->right != NULL) {
                temp = (T);
                (T) = (T)->right;
                free(temp);
            } else if ((T)->right == NULL && (T)->left != NULL) {
                temp = (T);
                (T) = (T)->left;
                free(temp);
            } else {
                (T)->key = delete_min(&((T)->right));
            }
        }
    }
    return T;
}

Tree readTree() {
    Tree createTree;
    makeNull(&createTree);
    int size;
    printf("Nhap vao so luong phan tu: ");
    scanf("%d", &size);
    int i;
    for (i = 0; i < size; i++) {
        int key;
        printf("Nhap vao key %d: ", i + 1);
        scanf("%d", &key);
        insert(key, &createTree);
    }
    return createTree;
}
// Sử dụng cây nhị phân
// Ex2:
KeyType findMax(Tree T) {
    if (!isEmptyTree(T)) {
        KeyType x = T->key;
        KeyType max = x;
        if (!isEmptyTree(T->right)) {
            max = findMax(T->right);
        } else {
            return x;
        }
        return max;
    }
}

void print_path(int x, Tree T) {
    if (T != NULL) {
        printf("%d ", T->key);
        if (x == T->key) {
            printf(" --> Tim thay");
        } else if (x < T->key) {
            // printf("%d ",T->key);
            print_path(x, T->left);
        } else if (x > T->key) {
            // printf("%d ",T->key);
            print_path(x, T->right);
        }
    } else {
        printf(" --> Tim khong thay");
    }
}

int get_height(Tree T) {
    if (T == NULL) {
        return -1;
    } else {
        int l = get_height(T->left);
        int r = get_height(T->right);
        return (l > r ? l : r) + 1;
    }
}

Tree getMin(Tree T) {
    if (T == NULL) {
        return NULL;
    }
    if (T->left == NULL) {
        return T;
    }
    return getMin(T->left);
}

Tree getNext(int x, Tree T) {
    Tree temp = T;
    Tree Ancestor = NULL;  //
    while (temp != NULL) {
        // x nằm ngay giữa = key
        if (x == temp->key) {
            if (temp->right == NULL) {
                return Ancestor;
            } else {
                return getMin(temp->right);
                // con nho nhat phai, qua phai -> qua trai cho toi chet
            }
        }
        // x nằm ở cây con bên trái
        else if (x < temp->key) {
            Ancestor = temp;
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }
    return NULL;
}

Tree getMax(Tree T) {
    if (T == NULL) {
        return NULL;
    }
    if (T->right == NULL) {
        return T;
    }
    return getMin(T->right);
}

Tree getPrevious(int x, Tree T) {
    Tree temp = T;
    Tree prev = NULL;  //
    while (temp != NULL) {
        // find x
        if (x == temp->key) {
            if (temp->left == NULL) {
                return prev;
            } else {
                return getMax(temp->left);
                // con nho nhat phai, qua phai -> qua trai cho toi chet
            }
        } else if (x < temp->key) {
            temp = temp->left;
        } else {
            prev = temp;
            temp = temp->right;
        }
    }
    return NULL;
}