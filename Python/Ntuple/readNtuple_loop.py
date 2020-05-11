#------------------------------------------#
# Reand Ntuple and fill histogram          #
# based on eventLoop                       #
# Plot hist using rootpy and matplotlib    #
# --Jiwoong                                #
#------------------------------------------#

# rootpy for histograming
from rootpy.plotting import Hist, HistStack, Legend, Canvas

# rootpy for matplotlib 
import rootpy.plotting.root2matplotlib as rplt
import matplotlib.pyplot as plt

# pyroot
import ROOT


## --file name, Tree name
file_name   = "ntuple.root"
tree_name   = "mytree"

## --Histogram definition
h1 = Hist(200,82,100)

## --Oepn file and read tree
root_file = ROOT.TFile.Open(file_name,'read')
tree = root_file.Get(tree_name)

## --Start event Loop
for Nevent, event in enumerate(tree):
	print(Nevent, event.signal)
	h1.Fill(event.signal)

## --Close file
root_file.Close()



## --Set parameters for plotting
plt.rcParams["figure.figsize"] = (7,5)
plt.rc('xtick',labelsize=20)
plt.rc('ytick',labelsize=20)
plt.title("Gauss distribution",fontsize=20)
plt.grid(which='major', linestyle='-')
plt.minorticks_on()

## --Draw hist
rplt.hist(h1,linewidth=3,color="royalblue")
plt.show()

