//#include "aqueuelib.h"
#include "pqueuelib.h"
int main (){
	printf("hello\n");
	Queue Q;
	makeNull(&Q);
	for(int i = 1; i < 11 ; i++){
		enQueue(i,&Q);
	}
	print(Q);
	
	printf("\n");
	printf("\nXoa 4 phan tu dau tien\n");
	for(int i = 1; i <= 4; i++){
		deQueue(&Q);
	}
	print(Q);

	printf("\nThem 5 phan tu dau tien\n");
	for(int i = 1; i <=5 ; i++){
		enQueue(i,&Q);
	}
	printf("\n");
	print(Q);

	printf("\nXoa 4 phan tu dau tien\n");
	for(int i = 1; i <= 4; i++){
		deQueue(&Q);
	}

	printf("\n");
	print(Q);

	printf("\nThem 2 phan tu dau tien\n");
	for(int i = 1; i <=2 ; i++){
		enQueue(i,&Q);
	}
	printf("\n");
	print(Q);
	printf("\n------------------------\n");
    makeNull(&Q);
    print(Q);

	printf("\nThem 1 phan tu dau tien\n");
	enQueue(1,&	Q);
	print(Q);
	int x = deQueue(&Q);
	printf("\n%d\n",x);
	print(Q);
}

