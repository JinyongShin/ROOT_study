from rootpy.plotting import Hist, HistStack, Legend, Canvas
from rootpy.plotting.style import get_style, set_style
from rootpy.plotting.utils import draw
import rootpy.plotting.root2matplotlib as rplt
import matplotlib.pyplot as plt
import numpy as np


## -- Define histogram
h1 = Hist(200,-5,5)

## -- Generate 10,000 number pf gauss pdf using numpy
signal = np.random.randn(10000)

## -- Fill hist v1_ using map function
map(h1.Fill,signal)


## -- Fill hist v2_ using for loop
#for i in range(len(signal)):
#	h1.Fill(signal[i])


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
