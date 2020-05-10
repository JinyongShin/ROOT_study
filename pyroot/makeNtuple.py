import ROOT as rt
from array import array

sigma = 2.5
mean = 91

## Define output file name
f = rt.TFile("ntuple.root","RECREATE")

## Define Tree name
tree = rt.TTree("mytree","mytree")

## Define branch name
array_gaus = array('f',[0])
tree.Branch("gaus",array_gaus,'gaus/F')

## Fill tree
for i in range(50000):
	array_gaus[0] = rt.gRandom.Gaus(mean,sigma)
	tree.Fill()


## Write file
f.Write()
