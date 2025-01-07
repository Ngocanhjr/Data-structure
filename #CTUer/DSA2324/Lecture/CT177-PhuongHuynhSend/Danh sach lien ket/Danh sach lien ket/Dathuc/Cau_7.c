DaThuc nhanDaThuc(DaThuc D1, DaThuc D2){
	DaThuc d;
	DonThuc e,temp;
	d=khoitao();
	Position q,p;
	p=D1;
	while (p->Next!=NULL){
		e=p->Next->e;
		q=D2;
		while (q->Next!=NULL){
			temp.he_so = e.he_so * q->Next->e.he_so;
			temp.bac = e.bac + q->Next->e.bac;
			chenDonThuc(temp,&d);
			q=q->Next;
		}	
		p=p->Next;
	}
	return d;
}
