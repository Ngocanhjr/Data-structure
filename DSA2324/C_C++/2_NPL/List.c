#include <stdio.h>
// Declare a list that can contain up to 300 integers
#define MAXLENGTH 300
typedef int ElementType;
typedef int Position;

typedef struct 
{
    ElementType Element[MAXLENGTH];
    Position last;
} List;
List L;

void printList (List L);

List readList();

//Creating an Empty List
List makeNullList ();

//Checking an Empty List
//Check if the current length of list equals to 0 
int isEmptyList (List L);

//Checking a Full List
int isFullList(List L);

//Determining Positions (first, endList, next, previous)
Position first(List L);

Position endList(List L); // trùng với số phần tử có trong x 

Position next(Position p, List L);

Position previous(Position p, List L);

//Returning the Element
ElementType retrieve(Position p, List L);

//Inserting an Element 
void insertList(ElementType x, Position p, List *pL);

//Deleting an Element
void deleteList(ElementType x, Position p, List *pL);

//Searching the Element x
Position locate(ElementType x, List L);

Position locate1(ElementType x, List L);

void deleteAllValueOfx(ElementType x, List *pL);

void demoDeleteAllValueOfx(ElementType x, List *pL);

int checkNumber(int a);

List oddList(List L); // le

List evenList(List L); //chan

void sortList(List *pL);

void swap (ElementType *a , ElementType *b);

void insertSortedList(ElementType x, List *pL);

int main (){

    //1. Build a list L of n elements.
    //2. Print all elements of the list L to stdout
    List newL = readList();
    printList(newL);

    //3. Delete all elements with value x from L.
    printf("Enter number wanna delete: ");
    int x; 
    scanf("%d", &x);
    demoDeleteAllValueOfx(x,&newL);
    // deleteAllValueOfx(x,&newL);
    printList(newL);
    List L1 = oddList(newL);
    List L2 = evenList(newL);
    printf("Odd List: ");
    printList(L1);
    printf("Odd List: ");
    printList(L2);
    printf("Sorted list: ");
    sortList(&newL);
    printList(newL);
    printf("Enter number u wanna insert: ");
    scanf("%d", &x);
    insertSortedList(x, &newL);
    printList(newL);
}

List readList(){
    int n;
    printf("Enter n element: ");
    scanf("%d", &n);
    List newList;
    newList.last = n;
    for(int i = 0; i < n; i++){
        printf("Enter element %d: ", i);
        scanf("%d", &newList.Element[i]);
    }
    // newList.Element[n] = '\0'; ?????
    // printf("last element: %d\n", newList.last);
    return newList;
}

void printList (List L){
    if (isEmptyList(L)){
        printf("Empty list!");
        return;
    } 
    Position p = 1;
    while (p != L.last + 1){
        printf("%d ", L.Element[p - 1]);
        p++;
    }
    printf("\n");
}

List makeNullList (){
    List L;
    L.last = 0;
    return L;
}

int isEmptyList (List L){
    return L.last == 0;
}

int isFullList(List L){
    return L.last == MAXLENGTH;
}

Position first(List L){
return 1;
}

Position endList(List L){
    return L.last + 1;
}

Position next(Position p, List L){
    return p + 1;
}

Position previous(Position p, List L){
    return p - 1;
}

ElementType retrieve(Position p, List L){
    return L.Element[p - 1];
}

//insert x into p position
void insertList(ElementType x, Position p, List *pL){
    if(pL->last == MAXLENGTH){
        printf("List is full");
    } else if ((p < 1) || (p > (pL->last + 1)))
    {
        printf("Position is invalid");
    } else 
    {
        Position q;
        for (q = pL->last; q >= p; q--)
        {
            pL->Element[q] = pL->Element[q - 1];
        }
        pL->Element[p - 1] = x; 
        pL->last++;
    }  
}

void deleteList(ElementType x, Position p, List *pL){
    if((p < 1) || (p > pL->last + 1)){
        printf("Position is invalid");
    } else if (isEmptyList(*pL)){
        printf("List is empty");
    } else{
        Position q;
        for (q = p; q < pL->last; q++)
        {
            pL->Element[q - 1] = pL->Element[q];
        }
        pL->last--; 
    }
}

Position locate(ElementType x, List L){
    Position p = 1;
    int found = 0;
    while ((p!=L.last + 1) && (found == 0))
    {
        if (L.Element[p - 1] == x)
           {
            found = p;
            return found;
           }
        else p++;
    }
    return found;
}

Position locate1(ElementType x, List L){
    Position P;
    int Found = 0;
    P = first(L);
    while ((P != endList(L)) && (Found == 0))
    if (retrieve(P,L) == x) Found = 1;
    else P = next(P, L);
    return P;
}

void deleteAllValueOfx(ElementType x, List *pL){
    for (int i = 1; i < pL->last + 1; i++){
        int temp = locate(x,*pL);
        deleteList(x,temp, pL);
    }
}

void demoDeleteAllValueOfx(ElementType x, List *pL){
    if (isEmptyList(*pL)){
        printf("Empty list!");
        return;
    } 
    for (int i = 1; i < pL->last + 1; i++){
        if (pL->Element[i - 1] == x)
        {
            deleteList(x, i , pL);
            i--; // kiểm tra lại vị trí sau khi xoá
        }
    }
}

int checkNumber(int a){
    if(a%2==0)
        return 1;
   return 0;
}

List oddList(List L){
    List L1;
    int count = 0;
    for(int i = 0; i < L.last; i++){
        if(!checkNumber(L.Element[i])){
            L1.Element[count] = L.Element[i];
            count ++;
        }
    }
    L1.last = count ++;
    return L1;
}

List evenList(List L){
    List L2;
    int count = 0;
    for(int i = 0; i < L.last; i++){
        if(checkNumber(L.Element[i])){
            L2.Element[count] = L.Element[i];
            count ++;
        }
    }
    L2.last = count ++;
    return L2;
}

void swap(ElementType *a , ElementType *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortList(List *pL){
    //Bubble sort
    for (int i = 0; i < pL->last; i++){
        int flag = 1;
        for (int j = 0; j < pL->last - i - 1; j++){ 
            if(pL->Element[j] > pL->Element[j + 1]){
                flag = 0;
                swap(&pL->Element[j],&pL->Element[j + 1]);
            }
        }
        if(flag){
            break;
        }
    }
}

void insertSortedList(ElementType x, List *pL){
    int left = 0, right = pL->last - 1;
    int res;
    //tim vi tri dau tien lon hon hoac bang x
    while (left <= right){
        int mid = (left + right)/2;
        if(pL->Element[mid] >= x){
            res = mid;
            right = mid - 1;
        } else
        {
            left = mid + 1;
        }
    }
    insertList(x,res + 1,pL);
}