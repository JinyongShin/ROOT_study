# rootpy for histograming
from rootpy.plotting import Hist, HistStack, Legend, Canvas

# rootpy for matplotlib 
import rootpy.plotting.root2matplotlib as rplt
import matplotlib.pyplot as plt
import ROOT

import numpy as np 
import scipy.stats


def f1(k,N,p):
	func = ROOT.TMath.Power(p,k)* ROOT.TMath.Power((1.0-p),N-k)
	for i  in range(1,k,1):
		func /= i
		func *= N
		N -= 1
		
	return func


h1 = Hist(100,0,20)


for i in range(20):
	print(f1(i,20,0.5))
	h1.Fill(i,f1(i,5,0.5))



## --Set parameters for plotting
plt.rcParams["figure.figsize"] = (7,5)
plt.rc('xtick',labelsize=20)
plt.rc('ytick',labelsize=20)
plt.title("Binomial distribution",fontsize=20)
plt.grid(which='major', linestyle='-')
plt.minorticks_on()

## --Draw hist
rplt.hist(h1,linewidth=3,color="royalblue")
plt.show()
