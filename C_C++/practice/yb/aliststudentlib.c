#include <stdio.h>
#include <string.h>

#define MAXLENGHT 300

typedef struct 
{
    int MSSV;
    char HoTen[50];
    float DiemTB;
} SinhVien;

typedef SinhVien ElementType;
typedef int Position;

typedef struct 
{
    ElementType elements[MAXLENGHT];
    Position last;
}List;

void makeNull(List *L){
    L->last = 0;;
}

int emptyList(List L){
    return L.last == 0;
}

int fullList(List L){
    return L.last == MAXLENGHT;
} 

Position first(List L){
    return 1;
}

Position endList(List L){
    return L.last + 1;
}

ElementType retrieve(Position p, List L){
    return L.elements[p - 1];
}

Position next(Position p, List L){
    return p + 1;
}

Position previous(Position p, List L){
    return p - 1;
}

void insertList(ElementType x, Position p, List *L){
    if(fullList(*L)){
        printf("Danh sach day");
    } else{
        Position q;
        for (q = L->last; q >=p; q--){
            L->elements[q] = L->elements[q - 1];
        }
        L->elements[p - 1] = x;
        L->last++;
    }
}

void deleteList(Position p, List *L){
    if(p < 1 || p > L->last){
        printf("Vi tri khong hop le!");
        return;
    } else{
        Position q;
        for (q = p; q < L->last; q++){
            L->elements[q - 1] = L->elements[q];
        }
        L->last--;
    }
}

int equal(ElementType X, ElementType Y){
    return X.MSSV == Y.MSSV && X.DiemTB == Y.DiemTB && strcmp(X.HoTen,Y.HoTen) == 0;
}

Position locate(ElementType X, List L){
    int found = 0;
    Position p = first(L), e = endList(L);
    while(p!=e && !found){
        if(equal(retrieve(p,L),X)){
            found = 1;
        } else {
            p = next(p, L);
        }
    }
    return p;
}

void printList(List L){
    Position p = first(L), e = endList(L);
    ElementType X;
    int stt = 1;
    printf("\n        DANH SACH SINH VIEN\n");
    printf("STT  MSSV    HO VA TEN            DIEM TB\n");
    while (p!=e){
        X = retrieve(p,L);
        printf("%3d%5d   %-25s%5.2f\n", stt++, X.MSSV, X.HoTen, X.DiemTB);
        p=next(p,L);
    }
}

void readList(List *L){
    int n, i;
    ElementType x;
    printf("Danh sach co bao nhieu sinh vien? ");
    scanf("%d", &n);
    for (i = 1; i <=n; i++){
        printf("Nhap phan tu thu %d:\n", i);
        printf("Ma sinh vien: "); scanf("%d", &x.MSSV);
        fflush(stdin);
        printf("Ho va ten: "); gets(x.HoTen);
        printf("Diem TB: "); scanf("%f", &x.DiemTB);
        insertList(x,endList(*L), L);
    }
}

void replace(ElementType x, Position p, List *L){
    insertList(x, p, L);
    Position q =next(p, *L);
    deleteList(q, L);
}

void swap(Position p, Position q, List *L){
    ElementType x = retrieve(p, *L);
    ElementType y = retrieve(q, *L);
    replace(x,q,L);
    replace(y,p,L);
}

void swap1(ElementType *x, ElementType *y){
    ElementType temp = *x;
    *x = *y;
    *y = temp;
}
void sort(List *L){
    Position p = first(*L), e = endList(*L), q;
    while (p != e){
        q = next (p,*L);
        while(q != e){
            if(retrieve(p,*L).MSSV > retrieve(q,*L).MSSV){
               swap(p,q,L);
               //swap1((&L[p]), &L[q]);

            }
            q = next(q,*L);
        }
        p = next(p, *L);
    }
}