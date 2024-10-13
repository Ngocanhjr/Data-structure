#include "plistlib.h"
//#include "a.h"

int a[] = {32, 51, 27, 83, 66, 11, 45, 75};

// a.ham nhap theo thu tu nhap
void appendList(int a[], int n, List *L)
{
	makeNull(L);
	for (int i = 0; i < n; i++)
	{
		append(i,a[i], L);
	}
}

// hàm chinh de chay chuong trinh
int main(int argc, char *argv[])
{
	List L1;
	appendList(a, sizeof(a) / sizeof(int), &L1);
	print(L1);

	List result = bubbleSort(L1);
	print(result);
}


