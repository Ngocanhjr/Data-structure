DaThuc congDaThuc(DaThuc D1, DaThuc D2){
	DaThuc d;
	d=khoitao();
	Position p=D1;
	while (p->Next!=NULL){
		chenDonThuc(p->Next->e,&d);
		p=p->Next;
	}
	p=D2;
	while (p->Next!=NULL){
		chenDonThuc(p->Next->e,&d);
		p=p->Next;
	}
	return d;
}
