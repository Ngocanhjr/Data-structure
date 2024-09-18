#include <conio.h>
#include "plistlib.h"

int a[]={32,51,27,83,66,11,45,75};

// a.ham nhap theo thu tu nhap
void appendList(int a[], int n, List *L){

}
// ham tao danh sach dao
void reverseList(int a[],int n, List *L){
}


// ham sap xep bubble sort
void bubbleSort(List *L){
}

// hàm chinh de chay chuong trinh
int main(int argc, char *argv[]){
	List L1;
	appendList(a, sizeof(a)/sizeof(int), &L1);
	print(L1);
	reverseList(a, sizeof(a)/sizeof(int), &L1);
	print(L1);
	insertAt(3,22,&L1);
	print(L1);
	bubbleSort(&L1);
	print(L1);

}


