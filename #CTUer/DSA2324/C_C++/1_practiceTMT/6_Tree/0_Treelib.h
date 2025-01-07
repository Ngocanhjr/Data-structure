#include <stdio.h>
#include <stdlib.h>

typedef char DataType;

typedef struct Node {
	DataType data;
	struct Node *left;
	struct Node *right;
}Node;
	
typedef Node* Tree;
Tree T;

void makeNull(Tree *T){
	(*T) = NULL;
}

int isEmptyTree(Tree T){
	return T == NULL;
}

Tree leftChild(Tree n){
	if(n!=NULL){
		return n->left;
	} 
	else{
		return NULL;
	}
}

Tree rightChild(Tree n){
	if(n!=NULL){
		return n->right;
	} 
	else{
		return NULL;
	}
}

int isLeaf(Tree n){
	if(n!=NULL){
//		return n->left == NULL && n->right == NULL
		return (leftChild(n) == NULL) && (rightChild(n) == NULL);
	}
	return 0;
}
Tree creat2(DataType v, Tree left, Tree right ){
	Tree N;
	N= (Node*) malloc(sizeof(Node));
	N->data = v;
	N->left = left;
	N->right = right;
	return N;
}



void NLR(Tree root){
	if(!isEmptyTree(root)){		
		printf("%c ", root->data);
		NLR(leftChild(root));
		NLR(rightChild(root));
	}
	 

}

void LNR(Tree root){	
	if(!isEmptyTree(root)){		
		LNR(root->left);
		printf("%c ", root->data);
		LNR(root->right);
	}
	 
}

void LRN(Tree root){	
	if(!isEmptyTree(root)){		
		LRN(root->left);		
		LRN(root->right);
		printf("%c ", root->data);
	}
	 
}

int nb_nodes(Tree root){
	if(isEmptyTree(root)){
		return 0;
	} else return 1 + nb_nodes(leftChild(root)) + nb_nodes(rightChild(root));
}

int countLeaf(Tree T){
	if(isEmptyTree(T)){
		return 0;
	} else if(isLeaf(T)){
		return 1;
	} else {
		return countLeaf(leftChild(T)) + countLeaf(rightChild(T));
	}
}