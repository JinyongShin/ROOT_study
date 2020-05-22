# rootpy for histograming
from rootpy.plotting import Hist, HistStack, Legend, Canvas

# rootpy for matplotlib 
import rootpy.plotting.root2matplotlib as rplt
import matplotlib.pyplot as plt

# pyroot
import ROOT
import ROOT.TMath.Pi

sigma = 1
mean  = 5

h1 = Hist(10000,0,10)

f_gaus = ROOT.TF1('gaus','(1/sqrt(2*Pi()*[0]*[0]))*Exp(-1*((x-[1])*(x-[1]))/(2*[0]*[0]))',0,10)

f_gaus.SetParameters(sigma,mean)

for i in range(10000):
	h1.Fill(f_gaus.GetRandom())


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

