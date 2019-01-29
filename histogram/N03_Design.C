void N03_Design(){

// --Design Parameters
	double XMIN = 0;
	double XMAX = 1000;
	long YMAX = 100;
	double rebin=1;


//////////////////////////// -- Analysis Parameters
// --Lumi and xsec
		 	const double Lumi         = 150000.0;
	// 	const double xsecSignal = 0.00127224;

// --read file,hist
	// TFile *fSignal = TFile::Open("signal.root") ;
	// TFile *fBKG    = TFile::Open("BKG.root")    ;
	// TString histname = "Mass"; XMAX=180; XMIN=70; rebin=155; YMAX=20;
	
// --Weighting	
	// 	TH1F *hSignal = (TH1F*)fSignal->Get(histname); hSignal->Scale(xsecSignal/100000*Lumi) ;
	// 	TH1F *hBKG = (TH1F*)fBKG ->Get(histname); hBKG ->Scale(xsecBKG/100000*Lumi) ;
////////////////////////////////////////////////////////////////////////////////////////

// --Pad Design
	gStyle->SetOptStat(0);
   gStyle->SetCanvasColor(0);
   gStyle->SetCanvasBorderMode(0);
   gStyle->SetPadBorderMode(0);
   gStyle->SetPadColor(0);
	gStyle->SetFrameBorderMode(0);

	double binwidth = 10;
	//double binwidth= hBKG->GetBinWidth(1); // -- Use this when you analyze Ntuple
	
	TCanvas* c1 = new TCanvas("c1", "c1", 500, 500);
	   	TPad *pad1 = new TPad("pad1", "pad1", 0.0, 0.0001, 1.0, 1.0);
	   	pad1->SetGrid();
		// pad1->SetLogy();  // -- Y-axis Log scale 
	   	pad1->Draw();
		pad1->cd();
   		TH2F *null1 = new TH2F("null1","", 2, XMIN, XMAX, 2, 0.09,YMAX);
   		null1->GetYaxis()->SetTitle(Form("Number of events / %3.1f GeV",binwidth)); // --Y Axis title
   		null1->GetXaxis()->SetTitle("Variable");												 // --X Axis title
   		null1->GetYaxis()->SetTitleOffset(1.4);
   		null1->GetXaxis()->SetTitleOffset(1.2);
   		null1->GetYaxis()->SetTitleSize(0.03);
   		null1->GetYaxis()->SetLabelSize(0.03);
   		null1->Draw();
   		 //hBKG->Draw("same");      // --Draw hist or graph here. You must add 'SAME' option
   		 //hSignal->Draw("same");

// -- Legend Design

	TLegend *l0 = new TLegend(0.65,0.89,0.90,0.65);
   		l0->SetFillStyle(0);
   		l0->SetBorderSize(0);
   		l0->SetTextSize(0.03);
	
	// -- Use this when you analyze Ntuple
	//TLegendEntry* l01 = l0->AddEntry(hSignal,"Signal"   ,"l"  );    l01->SetTextColor(hSignal->GetLineColor());  
	//TLegendEntry* l02 = l0->AddEntry(hBKG,"Background" ,"f" ); l02->SetTextColor(hBKG->GetLineColor());
	l0->Draw();

// -- Add some characters(Latex type)
	pad1->cd();
	TLatex latex;
  		latex.SetNDC();
   	latex.SetTextSize(0.04);
    	latex.SetTextAlign(11);
		latex.DrawLatex(0.6,0.91,Form("%.1f fb^{-1} (13 TeV)", Lumi/1000.0));
}
