// --Load header file: All useful classes are described here
// --Edit as your "ExRootClasses.h" location
#include "/x5/cms/jwkim/Madgraph/MG5_aMC_v2_6_1/ExRootAnalysis/ExRootAnalysis/ExRootClasses.h"

using namespace std;

void LHEF(){

   // --Load Lib
   // -- Edit yours...
   gSystem->Load("/x5/cms/jwkim/Madgraph/MG5_aMC_v2_6_1/ExRootAnalysis/libExRootAnalysis.so");

   // --Load tree and file
   // --Edit yours
   TChain* inChain = new TChain("LHEF");
   inChain->Add("test_out.root");

   // --Load the Class named TRootLHEFParticle
   TClonesArray* particleTCA = new TClonesArray("TRootLHEFParticle");

   // --Access the brach named Particle
   // --Branch name can be known using TBroser
   inChain->SetBranchAddress("Particle",&particleTCA);

   // --Total number of entries: 20,000
   int totalN = inChain->GetEntries();

   // Event(Entry) Loop start
   for(int eventLoop=0; eventLoop<totalN; eventLoop++){
      inChain->GetEntry(eventLoop); // Access Entry

      // Particle Loop start
      for(int pLoop=0; pLoop<particleTCA->GetEntries(); pLoop++){


         TRootLHEFParticle* particlePtr = (TRootLHEFParticle*)particleTCA->At(pLoop);
         cout << particlePtr->PID << endl;

      }// Particle Loop end

   }// Event(Entry) Loop end

}
