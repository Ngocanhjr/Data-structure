void chenDonThuc(DonThuc s, DaThuc *pD){
	Position p=(*pD);	
	int Found=0;
	while(p->Next!=NULL && !Found){
		if (p->Next->e.bac>s.bac)
			p=p->Next;
		else			
			Found=1;				
	}
	if (p->Next!=NULL){
		if(p->Next->e.bac==s.bac)
			p->Next->e.he_so += s.he_so;
		else {
			struct Node *t=(struct Node*)malloc(sizeof(struct Node));
			t->e=s;
			t->Next=p->Next;
			p->Next=t;
		}				
	}
	else{
		struct Node *t=(struct Node*)malloc(sizeof(struct Node));
		t->e=s;
		t->Next=p->Next;
		p->Next=t;
	}
}
