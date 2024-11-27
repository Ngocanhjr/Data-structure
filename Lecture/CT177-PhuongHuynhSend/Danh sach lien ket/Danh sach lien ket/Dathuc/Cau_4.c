DaThuc nhapDaThuc(){
	DaThuc d;
	DonThuc s;
	int n;	
	d=khoitao();
	scanf("%d",&n);
	for (int i=1; i<=n; i++){
		scanf("%lf",&s.he_so);
		scanf("%d",&s.bac);
		chenDonThuc(s,&d);
	}
	return d;
}
