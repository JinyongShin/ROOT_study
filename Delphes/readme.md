## 1. CMSSW SET
```bash
export SCRAM_ARCH=slc6_amd64_gcc530
export VO_CMS_SW_DIR=/cvmfs/cms.cern.ch
echo "$VO_CMS_SW_DIR $SCRAM_ARCH"
source $VO_CMS_SW_DIR/cmsset_default.sh
cmsrel CMSSW_9_1_0_pre3
cd CMSSW_9_1_0_pre3/src
cmsenv
cd -
```  
## 2. Install Delphes  
```bash
git clone git://github.com/delphes/delphes.git Delphes3.4.2
cd Delphes3.4.2
git checkout tags/3.4.2pre15
./configure
## -- c++ setup modifying in MakeFile
sed -i -e 's/c++0x/c++1y/g' Makefile
```  
You need to install the Pythia8 locally in this step.  
Please move to the 3rd step after successfully install the Pythia8  
Also, you should make 3 different directories separately ex) Madgraph Pythia8 Delphes  
* [Install Pyhtia link](http://home.thep.lu.se/Pythia/)  

## 3. Setup Pythia8 to link with Delphes  
```bash
## for bash : This is the pythia8 version that comes with CMSSW_9_1_0_pre3
export PYTHIA8=/cvmfs/cms.cern.ch/slc6_amd64_gcc530/external/pythia8/223-mlhled2/
export LD_LIBRARY_PATH=$PYTHIA8/lib:$LD_LIBRARY_PATH
```  

## 4. Then compile DelphesPythia in Delphes directory
```bash
cd Delphes-Working-Directory
make -j 4 HAS_PYTHIA8=true DelphesPythia8
```
