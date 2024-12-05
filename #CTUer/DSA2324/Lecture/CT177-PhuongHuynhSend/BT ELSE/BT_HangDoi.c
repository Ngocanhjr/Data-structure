#include <stdio.h>
#define Maxlength 100
typedef int ElementType;

typedef struct {
ElementType Element[Maxlength];
int Front, Rear;
} Queue;
// Tao hang rong 
void MakeNull_Queue(Queue *Q) {
    Q->Front=-1;
    Q->Rear=-1;
}
// Kiem tra hang rong
int Empty_Queue (Queue Q) {
    return Q.Front==-1;
}

// Kiem tra hang day 
int Full_Queue (Queue Q) {
    return (Q.Rear -Q.Front +1)==Maxlength;
} 

void EnQueue(ElementType X, Queue *Q) {
    if (!Full_Queue(*Q)) {
if (Empty_Queue(*Q)) Q->Front=0; 
if (Q->Rear==Maxlength-1) {
    int i;
    for (i=Q->Front;i<=Q->Rear;i++) {
        Q->Element[i-Q->Front]= Q->Element[i];
    }
    Q->Rear= Maxlength - Q->Front-1;
    Q->Front=0;
    Q->Rear = Q->Rear+1;
    Q->Element[Q->Rear]=X;
}
    } else printf("Loi, Hang day!");
}

void DeQueue (Queue *Q) {
if (!Empty_Queue(*Q)) {
Q->Front = Q->Front+1;
if (Q->Front>Q->Rear) MakeNull_Queue(Q);
} else printf("Loi, Hang Rong");
}
ElementType Front(Queue Q) {
    return Q.Element[Q.Front];
}
void PrintQueue (Queue *Q) {
    while (!Empty_Queue(*Q)) {
printf("%d ",Front(*Q));
DeQueue(Q);
    }
    printf("\n");
}
int CountElement (Queue Q) {
    int i=Q.Front,dem=0;
while (i!=Q.Rear) {
dem++;
i++;
}
return dem;
}
int main() {
int n;
scanf("%d",&n);
scanf(" ");
Queue Q;
char x;
MakeNull_Queue(&Q);
while (n--) {
scanf("%c",&x);
if (x=='E') {
    int t;
    scanf("%d",&t);
    scanf(" ");
    EnQueue(t,&Q);
    printf("%d\n",CountElement(Q));
}  else 
if (x=='D') {
    scanf(" ");
    if (!Empty_Queue(Q)) {
int temp=Front(Q);
     DeQueue(&Q);
    printf("%d %d\n",temp,CountElement(Q));
    }
    else printf("-1 0\n");
   
}
}

    return 0;
}