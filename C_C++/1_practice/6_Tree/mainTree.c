#include "0_Treelib.h"
int main (){
	Tree T;
	makeNull(&T);	
	T = creat2('+', creat2('*',creat2('3', NULL, NULL),creat2('5', NULL, NULL)),creat2('7', NULL, NULL));
	printf("Tree 1: \n");
	printf("Infix: ");
	LNR(T);
	printf("\n");
	printf("Prefix: ");
	NLR(T);
	printf("\n");
	printf("Profix: ");
	LRN(T);
	printf("\n");
	printf("Count node: %d\n", nb_nodes(T));
	printf("Count leaf: %d\n", countLeaf(T));
	printf("Tree 2: \n");
	Tree root;
	Tree subLeft;
	Tree subRight;
	makeNull(&subLeft);
	makeNull(&subRight);
	makeNull(&root);
	subLeft = creat2('+',creat2('+',creat2('a', NULL, NULL),creat2('b', NULL, NULL)), creat2('*',creat2('c', NULL,NULL),creat2('+',creat2('d', NULL, NULL),creat2('e', NULL,NULL))));
	subRight= creat2('+', creat2('g', NULL, NULL), creat2('8', NULL, NULL));
	root= creat2('*',creat2('+', subLeft, creat2('f', NULL, NULL)),subRight);
	printf("Infix: ");
	LNR(root);
	printf("\n");
	printf("Count node: %d\n", nb_nodes(root));
	printf("Count leaf: %d\n", countLeaf(root));
//	LNR(subLeft);
}