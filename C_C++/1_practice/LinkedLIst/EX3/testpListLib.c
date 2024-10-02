// #include <conio.h>
// #include "plistlib.h"
#include "alistlib.h"
int a[] = {32, 51, 27, 83, 66, 11, 45, 75};

// a.ham nhap theo thu tu nhap
void appendList(int a[], int n, List *L)
{
	makeNull(L);
	for (int i = 0; i < n; i++)
	{
		append(a[i], L);
	}
}
// ham tao danh sach dao
void reverseList(int a[], int n, List *L)
{
	makeNull(L);
	for (int i = 0; i < n; i++)
	{
		insertFirst(a[i], L);
	}
}

// ham sap xep bubble sort
void bubbleSort(List *L)
{
	int size = len(*L);
	for (int i = first(*L); i < size; i++)
	{
		int isSorted = 1;
		for (int j = first(*L); j <= size - i; j++)
		{
			if (getAt(j, *L) > getAt(j + 1, *L))
			{
				isSorted = 0;
				int temp = getAt(j, *L);
				setAt(j, getAt(j + 1, *L), L);
				setAt(j + 1, temp, L);
			}
		}
		if (isSorted)
		{
			break;
		}
	}
}

void bubbleSort_plist(List *L)
{
	int size = len(*L);
	for (int i = 0; i < size; i++)
	{
		int isSorted = 1;
		for (int j = 0; j < size - i - 1; j++)
		{
			if (getAt(j, *L) > getAt(j + 1, *L))
			{
				isSorted = 0;
				int temp = getAt(j, *L);
				setAt(j, getAt(j + 1, *L), L);
				setAt(j + 1, temp, L);
			}
		}
		if (isSorted)
		{
			break;
		}
	}
}

// h�m chinh de chay chuong trinh
int main(int argc, char *argv[])
{
	List L1;
	appendList(a, sizeof(a) / sizeof(int), &L1);
	print(L1);
	reverseList(a, sizeof(a) / sizeof(int), &L1);
	print(L1);
	insertAt(3, 22, &L1);
	print(L1);
	bubbleSort(&L1);
	print(L1);
}
