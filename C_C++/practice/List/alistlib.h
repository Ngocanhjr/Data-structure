//Maximum size of list
#define MAXSIZE 1000

typedef int Position;
typedef int ElementType;

typedef struct {
    ElementType element[MAXSIZE]; //Array of elements
    int size; //current number of elements
}List;

List L;

void makeNull(List *pL); //Initialize an empty list

int len(List L); //Return the number of elements

int empty(List L); //check whether the list is empty

int fullList(List L); //check whether the list is full

void print(List L); //Traverse the list to print out all elements

ElementType getAt( Position p, List L); //return the element at position p

void setAt(Position p, ElementType x, List *pL); // Update the element at position p by a new value x

void insertAt(Position p, ElementType x, List *pL); //Insert a new element x

ElementType popAt(Position p, List *pL); //Remove and return the element at position p

void insertFirst(ElementType x, List *pL); //Inset x to the first element at position p

ElementType popFirst(List *pL); //Remove and return the first element

void append(ElementType x, List *pL); //Append a new element to the first

ElementType popLast(List *pL); //Remove and return a last element

Position locate(ElementType x, List L); // Return the position of the first appearance of x in the list

void build(ElementType A[], int n, List *pL);


