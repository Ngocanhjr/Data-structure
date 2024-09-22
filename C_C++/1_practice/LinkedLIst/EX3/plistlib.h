#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef int Position;

typedef struct NodeTag
{
  ElementType data;
  struct NodeTag *next;
} Node;

typedef Node *List;
typedef Node *PNode;

/*
Initialize an empty list
*/
void makeNull(List *L)
{
  List newList = (Node *)malloc(sizeof(Node));
  newList->next = NULL;
  (*L) = newList;
}

/*
return Number of elements
*/
int len(List L)
{
  int count = 0;
  while (L->next != NULL)
  {
    count++;
    L = L->next;
  }
  return count;
}

/*
Check whether the list is empty?
*/
int empty(List L)
{
  return L->next == NULL;
}

/*
Check whether the list is full?
*/
int fullList(List L)
{
}

/*
Check position is valid?
*/
int isValid(Position p, List L)
{
  if (p >= 0 && p <= len(L))
    return 1;
  return 0;
}

/*
Traverse the list to print out all elements
*/
void print(List L)
{
  if (empty(L))
  {
    printf("<!> List is empty!");
  }
  else
  {
    while (L->next != NULL)
    {
      printf("%d ", L->next->data);
      L = L->next;
    }
  }
  printf("\n");
}

/*
Return the pointer referring to the ith element
*/
PNode getPosition(Position p, List L)
{
  if (isValid(p, L))
  {
    int found = 0;
    PNode pos = L;
    while (pos->next != NULL && found < p)
    {
      found++;
      pos = pos->next;
    }
    return pos;
  }
  else
  {
    printf("<!> Position is invalid <!>");
  }
}

/*
Return the element at position p
*/
ElementType getAt(Position p, List L)
{
  PNode pos = getPosition(p, L);
  return pos->next->data;
}

/*
Return the pointer referring to the first element of L
*/
PNode first(List L)
{
  return L;
}

/*
Return the pointer referring to the last element of L
*/
PNode end(List L)
{
  PNode last = L;
  while (last->next->next != NULL)
  {
    last = last->next;
  }
  return last;
}

/*
Update the element at position p by a new value
*/
void setAt(Position p, ElementType x, List *L)
{
  if (isValid(p, *L))
  {
    List new;
    new = getPosition(p, *L);
    new->next->data = x;
  }
  else
  {
    printf("<!> Position is invalid <!>");
  }
}

/*
Insert x at position p
*/
void insertAt(Position p, ElementType x, List *L)
{
  if (isValid(p, *L))
  {
    List newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;
    // newNode->next = NULL;
    List current = getPosition(p, *L);
    newNode->next = current->next;
    current->next = newNode;
  }
  else
  {
    printf("<!> Position is invalid <!>");
  }
}
/*
Remove and return the element at position p
*/
ElementType popAt(Position p, List *L)
{
  if (isValid(p, *L))
  {
    List cur = getPosition(p, *L);
    ElementType value = cur->next->data;
    List del = cur->next;
    cur->next = del->next;
    free(del);
    return value;
  }
  else
  {
    printf("<!> Position is invalid <!>");
  }
}

/*
Insert x to the first position
*/
void insertFirst(ElementType x, List *L)
{
  List newNode = (Node *)malloc(sizeof(Node));
  newNode->data = x;
  newNode->next = (*L)->next;
  (*L)->next = newNode;
}

/*
Remove and return the first element
*/
ElementType popFirst(List *L)
{
  if (!empty(*L))
  {
    ElementType value = (*L)->next->data;
    List del = (*L)->next;
    (*L)->next = del->next;
    free(del);
    return value;
  }
  else
  {
    printf("<!> ERROR: EMPTY LIST");
  }
}
/*
Append a new element to the list
*/
void append(ElementType x, List *L)
{
  insertAt(len(*L), x, L);
}

/*
Remove and return the last element
*/
ElementType popLast(List *L)
{
  ElementType value;
  PNode posLast = *L;
  while (posLast->next->next != NULL)
  {
    posLast = posLast->next;
  }
  value = posLast->next->data;
  popAt(len(*L) - 1, L);
}

/*
Return the position of the first appearance of x in the list
*/
Position locate(ElementType x, List L)
{
  List header = L;
  int found = 0, pos = 0;
  while (header->next != NULL && !found)
  {
    if (header->next->data == x)
    {
      found = 1;
      header = header->next;
      continue;
    }
    pos++;
    header = header->next;
  }
  return pos;
}

/*
Return the pointer referring to the next position of i in L
*/
PNode next(Position p, List L)
{
  if (!empty(L))
  {
    PNode pos = getPosition(p, L);
    return pos->next;
  }
  else
  {
    printf("<!> Empty\n");
  }
}

/*
Return the pointer referring to the previous position of p in L
*/
PNode previous(Position p, List L)
{
  if (!empty(L))
  {
    PNode pos = getPosition(p - 1, L);
    return pos;
  }
  else
  {
    printf("<!> Empty\n");
  }
}

/*
Return the element at position PNode
*/
ElementType retrieve(PNode p, List L)
{
  if (p->next != NULL)
  {
    return p->next->data;
  }
}
