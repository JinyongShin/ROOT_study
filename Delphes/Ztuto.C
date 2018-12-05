#include <iostream>
#include "TClonesArray.h"
#include "TFile.h"
#include "TChain.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TCanvas.h"
#include "classes/DelphesClasses.h" //-Edit path  Delphes_Directory_location/classes/DelphesClasses.h


int main() {

	using namespace std;

	TChain* inChain = new TChain("Delphes"); // Read Tree
	inChain->Add("Ztuto_delphes.root"); //Read File

	TClonesArray* eTCA = new TClonesArray("Electron");
	inChain->SetBranchAddress("Electron",&eTCA); // Read Branch ( or leaf )

	TFile *outFile = new TFile("hist.root","recreate"); // output file format

	TH1F* h1_ePt = new TH1F("h1_ePT","h1_ePT",200,0,100); 
	TH1F* h1_eeM = new TH1F("h1_eeM","h1_eeM",200,0,200);


	int totalN = inChain->GetEntries();

	// --Event Loop start
	for(int eventLoop=0; eventLoop<totalN; eventLoop++){
	inChain->GetEntry(eventLoop); // Access Entry 

			// --Electron Loop start
			for(int eLoop=0; eLoop<eTCA->GetEntries(); eLoop++){
			Electron* ePtr = (Electron*)eTCA->At(eLoop);
		
			h1_ePt->Fill(ePtr->PT);
	      	} // Electron Loop end
		
	if(eTCA->GetEntries() != 2) continue;
	
		Electron* ePtr1 = (Electron*)eTCA->At(0);
		Electron* ePtr2 = (Electron*)eTCA->At(1);
		
	if(ePtr1->Charge * ePtr2->Charge > 0) continue;
		TLorentzVector eTVec1 = ePtr1->P4();
		TLorentzVector eTVec2 = ePtr2->P4();
		TLorentzVector eeTVec = eTVec1+eTVec2;
	
		h1_eeM->Fill(eeTVec.M());
	
	}// --Event Loop end
	
	TCanvas* c1 = new TCanvas();
	h1_ePt->Draw();
	TCanvas* c2 = new TCanvas();
	h1_eeM->Draw();
	outFile->Write();	

	return 0;
}
