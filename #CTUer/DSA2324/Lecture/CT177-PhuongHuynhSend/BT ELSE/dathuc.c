#include <stdio.h>
typedef struct  
{
    /* data */

double he_so;
int bac;
} DonThuc;


struct Node{
    DonThuc e;
    struct Node* Next;
};
DaThuc khoitao() {
    DaThuc d;
    d = (struct Node*) malloc (sizeof(struct Node));
    d->Next=NULL;
    return d;
}

void inDonThuc( DaThuc d) {
    Position p=d;
    while (p->Next !=NULL) {
        if (p-> Next -> Next ==NULL) printf("%.3fX^%d",p->Next->e.he_so,p->Next->e.bac);
        else printf("%.3fX^%d + ",p->Next->e.he_so,p->Next->e.bac);
        p=p->Next;
    }
    printf("\n");
}

void chenDonThuc (DonThuc x, DaThuc *pD) {
    Position p= (*pD);
    int Found=0;
    while (p->Next!=NULL && !Found) {
        if (p->Next->e.bac > x.bac) p=p->Next;
        else Found=1;
    }
    if (p->Next!=NULL) {
        if (p->Next->e.bac==x.bac) {
            p->Next->e.he_so += x.he_so;
        }
        else {
struct Node* t= (struct Node*) malloc(sizeof(struct Node));
t->e=x;
t->Next =p->Next;
p->Next=t;
        }
    }
    else {
        struct Node* t = (struct Node*)malloc(sizeof(struct Node));
        t->e=x;
        t->Next=p->Next;
        p->Next =t;
    }
}
typedef struct Node* Position;
typedef Position DaThuc;
int main() {
    return 0;
}