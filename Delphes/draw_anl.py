# rootpy I/O
from rootpy.io import root_open

# rootpy for histograming
from rootpy.plotting import Hist, HistStack, Legend, Canvas

# rootpy for matplotlib 
import rootpy.plotting.root2matplotlib as rplt
import matplotlib.pyplot as plt


myfile = root_open("Wmass.root")
myhist = myfile.mass.Clone()

## --Set parameters for plotting
plt.rcParams["figure.figsize"] = (10,6)
plt.rc('xtick',labelsize=20)
plt.rc('ytick',labelsize=20)
plt.title("Gauss distribution",fontsize=20)
plt.grid(which='major', linestyle='-.')
plt.minorticks_on()

## --Draw hist
rplt.hist(myhist,linewidth=3,color="royalblue")
plt.xticks([0,20,40,60,80,100,120,140,160,180,200])
plt.yticks([0,20,40,60,80,100,120,140,160])
plt.show()

#plt.savefig("fig.png")



