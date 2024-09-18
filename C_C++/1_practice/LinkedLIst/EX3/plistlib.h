#include <stdio.h>

typedef int ElementType;
typedef int Position;

typedef struct NodeTag {
  ElementType data;
  struct NodeTag *next; 
}Node;

typedef Node *List;
typedef Node* PNode;

/*
Initialize an empty list
*/
void makeNull(List *L){

}

/*
return Number of elements
*/
int len(List L){

}

/*
Check whether the list is empty?
*/
int empty(List L){

}

/*
Check whether the list is full?
*/
int fullList(List L){
	
}

/*
Traverse the list to print out all elements
*/
void print(List L){

}

/*
Return the element at position p
*/
ElementType getAt(Position p, List L){

}

/*
Return the pointer referring to the ith element
*/
PNode getPosition(Position p, List L){

}

/*
Return the pointer referring to the first element of L
*/
PNode first(List L){
}

/*
Return the pointer referring to the last element of L
*/
PNode end(List L){

}

/*
Update the element at position p by a new value
*/
void setAt(Position p, ElementType x,List *L){

}

/*
Insert x at position p
*/
void insertAt(Position p, ElementType x, List *L){
}
/*
Remove and return the element at position p
*/
ElementType popAt(Position p, List *L){

}

/*
Insert x to the first position
*/
void insertFirst(ElementType x, List *L){

}

/*
Remove and return the first element
*/
ElementType popFirst(List *L){

}
/*
Append a new element to the list
*/
void append(ElementType x,List *L){


}

/*
Remove and return the last element
*/
ElementType popLast(List *L){

}

/*
Return the position of the first appearance of x in the list
*/
Position locate(ElementType x, List L){

}

/*
Return the pointer referring to the next position of i in L
*/
PNode next(Position p,List L){
	
}

/*
Return the pointer referring to the previous position of p in L
*/
PNode previous(Position p,List L){

}
