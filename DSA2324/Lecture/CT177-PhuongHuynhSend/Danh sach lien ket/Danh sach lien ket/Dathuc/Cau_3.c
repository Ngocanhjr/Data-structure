void inDaThuc(DaThuc d){
	Position p=d;
	while(p->Next!=NULL){
		if (p->Next->Next==NULL)
			printf("%.3fX^%d",p->Next->e.he_so,p->Next->e.bac);
		else
			printf("%.3fX^%d + ",p->Next->e.he_so,p->Next->e.bac);
		p=p->Next;	
	}
	printf("\n");
}
