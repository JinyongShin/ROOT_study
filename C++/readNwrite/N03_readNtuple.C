

////////////////////////////////////////////////////////////////////////////////////
// Basic tutorial for reading Ntuple data format and draw some histograms and graph 
////////////////////////////////////////////////////////////////////////////////////


void N03_readNtuple() {


	//*	TChain: TChain basically makes it possible to deal with "tree objects"
	//			Also it can read tree in multiple files  inChain->Add("file1") inChain->Add("file2")....
	TChain *inChain = new TChain("nt");	// Read Ntuple 
	inChain->Add("dat.root");			// Read input Files

	TH1F *h1 = new TH1F("x","x",100,0,10);
	TH1F *h2 = new TH1F("sinx","sinx",100,0,1);

	int totalN = inChain->GetEntries(); // Read Totla Entries in Ntuple
	float a,sina;						// variables for reading Branch or leaf


	float x[100], y[100];				// Data structure for storing the data of Ntuple format

	inChain->SetBranchAddress("x",&a);		// Read branch( or leaf ) named "x" as "a"   ( previously defined )
	inChain->SetBranchAddress("y",&sina);	// Read branch( or leaf ) named "y" as "asin"( previously defined )

	cout << totalN << endl;					// Check the total number of Entries


	// -- Loop for scanning all the entries of tree.( So called event loop )
	for(int eventLoop=0; eventLoop < totalN; eventLoop++){
		inChain->GetEntry(eventLoop); // -- Access each Entry

		x[eventLoop] = a;
		y[eventLoop] = sina;

		h1->Fill(a);
		h2->Fill(sina);

	} // End event loop 


	TCanvas *c1 = new TCanvas();
	c1->Divide(2,2);


	// --Draw a graph using x.y
	TGraph *gr = new TGraph(100,x,y);
	
	c1->cd(1);
	gr->Draw();
	
	c1->cd(2);
	h1->Draw();

	c1->cd(3);
	h2->Draw();


}
