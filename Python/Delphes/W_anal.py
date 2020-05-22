import ROOT
import argparse


## --Developing ------>
'''
# rootpy for histograming
from rootpy.plotting import Hist, HistStack, Legend, Canvas

# rootpy for matplotlib 
import rootpy.plotting.root2matplotlib as rplt
import matplotlib.pyplot as plt
'''
## <--------------------

# --Setup parser
parser = argparse.ArgumentParser()
parser.add_argument('infile', type=str,
            help="Add your input rootfile path")
args = parser.parse_args()



# --Set your Delphes/libDelphes.so path, header path
ROOT.gSystem.Load("/x5/cms/jwkim/Delphes_NEW/Delphes3.4.2/libDelphes.so")

try:
  ROOT.gInterpreter.Declare('#include "classes/DelphesClasses.h"')
  ROOT.gInterpreter.Declare('#include "external/ExRootAnalysis/ExRootTreeReader.h"')
except:
  pass



# Read File
inputFile = args.infile

# Create chain of root trees
chain = ROOT.TChain("Delphes")
chain.Add(inputFile)

# Create object of class ExRootTreeReader
treeReader = ROOT.ExRootTreeReader(chain)
numberOfEntries = treeReader.GetEntries()

# Get pointers to branches used in this analysis
branchMET = treeReader.UseBranch("MissingET")
branchElectron = treeReader.UseBranch("Electron")

# Define histograms
histMass = ROOT.TH1F("mass", "Transverse Mass", 100, 0, 1000.0)



# --EventLoop start
for entry in range(0, numberOfEntries):
	# Load selected branches with data from specified event
	treeReader.ReadEntry(entry)

	# If event contains at least 1 electrons
	if branchElectron.GetEntries() == 0:
		continue
	
	# Take e, ve
	elec = branchElectron.At(0)
	metc = branchMET.At(0)


	TVmass = (elec.P4() + metc.P4()).Mt()

	# Plot their transverse mass
	histMass.Fill(TVmass)

# -- EventLoop Ends

# --Show histogram
c1 = ROOT.TCanvas()
c1.cd()
histMass.GetXaxis().SetTitle("M_{T}")
histMass.GetYaxis().SetTitle("Events")
histMass.Draw()
input("Press Enter to continue...")



#### Developing ------------------------------>
'''
## --set parametres for plotting
plt.rcParams["figure.figsize"] = (7,5)
plt.rc('xtick', labelsize=20)
plt.rc('ytick', labelsize=20)
plt.title("Transverse mass", fontsize=20)
plt.grid(which='major', linestyle='-')
plt.minorticks_on()

## --draw hist
rplt.hist(histMass, linewidth=3, color="royalblue")
plt.show()
'''
## <-----------------------------------------------
