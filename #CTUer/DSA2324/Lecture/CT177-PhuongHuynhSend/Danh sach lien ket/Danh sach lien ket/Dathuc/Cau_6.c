DaThuc tinhDaoHam(DaThuc D){
	DaThuc dt;
	DonThuc e;
	dt=khoitao();
	Position p=D;
	while(p->Next!=NULL){
		e=p->Next->e;
		e.he_so *= e.bac;
		e.bac--;
		chenDonThuc(e,&dt);
		p=p->Next;
	}
	return dt;
}
