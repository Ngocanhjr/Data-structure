#include <iostream>

using namespace std;

enum COLOR
{
    RED, BLACK;
};

struct RBNode
{
    int Info;
    RBNode* Left;
    RBNode* Right;
    RBNode* Parent;
    COLOR Color;
};

RBNode* search(RBNode* root, int key)
{
    if (root == NULL) return NULL;
    if (root->Info == key)
    {
        return root;
    } else if (root->Info < key)
    {
        return search(root->Right, key);
    }else {
        return search(root->Left, key);
    } 
}