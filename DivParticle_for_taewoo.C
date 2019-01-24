#define test1000_cxx
#include "test1000.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void test1000::Loop()

if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;

   TFile *outfile = new TFile("hist_all1000.root","create");
   TH1F *h1 = new TH1F("h1","h1",10000,1000,7000);
   h1->SetTitle("M1000");
   gStyle->SetOptStat(111111);

   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;

      if(Particle_size != 8){

         double Mjj=  sqrt(2*Particle_PT[5]*Particle_PT[6]*(cosh(Particle_Eta[5]-Particle_Eta[6])-cos(Particle_Phi[5]-Particle_Phi[6])));
         h1->Fill(Mjj);
      }else{

         double Mjj=  sqrt(2*Particle_PT[6]*Particle_PT[7]*(cosh(Particle_Eta[6]-Particle_Eta[7])-cos(Particle_Phi[6]-Particle_Phi[7])));
         h1->Fill(Mjj);
      }

   }

   h1->Draw();
   outfile->Write();

}
