int Monte(){

	TRandom f;

	cout<<"In put random number's number\n";
	int random_number;
	double Pi, in_number, out_number;

	cin>>random_number;
	srand((unsigned)time(NULL));

	if(random_number<=0)
		return 0;

	double *X_size = new (nothrow) double[random_number];
	if(!X_size)
	{
		cout<<"In put positive number\n";
		return 0;
	}

	for(int i=0; i<random_number; i++)
	{
		X_size[i] = f.Rndm(i);
		
	}

	double *Y_size = new (nothrow) double[random_number];
	for(int i=0; i<random_number; i++)
	{
		Y_size[i] = f.Rndm(i);
	}


	int *Length = new (nothrow) int[random_number];
	for(int i=0; i<random_number; i++)
	{
		if(X_size[i] * X_size[i] + Y_size[i] * Y_size[i]<=1)
			{Length[i] = 1;}
		else {Length[i] = 0;}
		
		if(Length[i] == 1)
			{++in_number;}
		else {++out_number;}
	}

	Pi = (in_number / random_number) * 4;
	printf("Pi = %f\n",Pi);
	
	Double_t w = 600;
   	Double_t h = 600;
  	TCanvas * c1 = new TCanvas("c", "c", w, h);
 	
	TGraph *Point=new TGraph(10000, X_size, Y_size);
	TEllipse *Circle = new TEllipse(0,0,1,0,0,90);

	Point->GetXaxis()->SetRangeUser(0,1);
	Point->GetYaxis()->SetRangeUser(0,1);

	Point->Draw("AP");
	Circle->SetFillStyle(0);
	Circle->Draw("same");

	
	delete []X_size;
	delete []Y_size;

	return 0;
}
