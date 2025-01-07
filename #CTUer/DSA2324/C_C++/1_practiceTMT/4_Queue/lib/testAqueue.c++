// #include "aqueuelib.h"
// #include "err_acirclequeuelib.h"
// #include "pqueuelib.h"
#include "acirclequeuelib.h"


int main (){
	printf("hello\n");
	Queue Q;
	makeNull(&Q);
	for(int i = 1; i < 11 ; i++){
		enQueue(i,&Q);
	}
	print(Q);
	
	printf("-------------------DEQUEUE-------------------\n");
	for(int i = 1; i <= 4; i++){
		deQueue(&Q);
	}
	print(Q);
	printf("Length: %d\n",len(Q));

	printf("-------------------ENQUEUE 5-------------------\n");
	for(int i = 1; i <=5 ; i++){
		enQueue(i,&Q);
	}
	print(Q);
	printf("Length: %d\n",len(Q));

	printf("-------------------DEQUEUE 4-------------------\n");
	for(int i = 1; i <= 4; i++){
		deQueue(&Q);
	}
	print(Q);
	printf("Length: %d\n",len(Q));

	printf("-------------------ENQUEUE 2-------------------\n");
	for(int i = 1; i <=2 ; i++){
		enQueue(i,&Q);
	}
	print(Q);
	printf("Length: %d\n",len(Q));

	printf("-------------------MAKE NULL-------------------\n");
    makeNull(&Q);
    print(Q);
	printf("Length: %d\n",len(Q));

	printf("-------------------ENQUEUE 1-------------------\n");
	enQueue(1,&	Q);
	print(Q);
	printf("Length: %d\n",len(Q));

	printf("-------------------DEQUEUE-------------------\n");
	int x = deQueue(&Q);
	printf("Data delete: %d\n",x);
	print(Q);
	printf("Length: %d\n",len(Q));

	printf("-------------------ENQUEUE 10-------------------\n");
	for(int i = 1; i <= 10; i++){
		enQueue(i,&Q);
	}
	printf("Length: %d\n",len(Q));
}
