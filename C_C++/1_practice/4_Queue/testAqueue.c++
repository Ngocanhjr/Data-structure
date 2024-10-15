#include "aqueuelib.h"

int main (){
	printf("helo\n");
	Queue Q;
	makeNull(&Q);
	for(int i = 1; i < 11 ; i++){
		enQueue(i,&Q);
	}
	print(Q);
	
	printf("\n");
	for(int i = 1; i <= 4; i++){
		deQueue(&Q);
	}
	print(Q);

	for(int i = 1; i <=5 ; i++){
		enQueue(i,&Q);
	}
	printf("\n");
	print(Q);

	for(int i = 1; i <= 4; i++){
		deQueue(&Q);
	}

	printf("\n");
	print(Q);

	for(int i = 1; i <=2 ; i++){
		enQueue(i,&Q);
	}
	printf("\n");
	print(Q);
    makeNull(&Q);
    print(Q);

	enQueue(1,&	Q);
	print(Q);
	int x = deQueue(&Q);
	printf("\n%d\n",x);
	print(Q);
}
