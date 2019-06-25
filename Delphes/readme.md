## First -> compile  
> source compile.sh 
### Second -> run  
> ./Ztuto.exe  
### Third -> Check the root file  
> root hist.root

---

## Delphes Installation  

### 1. CMSSW set  
```bash
export SCRAM_ARCH=slc6_amd64_gcc530
export VO_CMS_SW_DIR=/cvmfs/cms.cern.ch
echo "$VO_CMS_SW_DIR $SCRAM_ARCH"
source $VO_CMS_SW_DIR/cmsset_default.sh
cmsrel CMSSW_9_1_0_pre3
cd CMSSW_9_1_0_pre3/src
cmsenv
cd YOUR_WORKING_DIR
```  

### 2. Install Delphes and Configure
```bash
git clone git://github.com/delphes/delphes.git Delphes3.4.2
cd Delphes3.4.2
git checkout tags/3.4.2pre15
./configure
```  

### 3. Modifying make file, Pythia setting(bash)  
```bash
sed -i -e 's/c++0x/c++1y/g' Makefile
export PYTHIA8=/cvmfs/cms.cern.ch/slc6_amd64_gcc530/external/pythia8/223-mlhled2/
export LD_LIBRARY_PATH=$PYTHIA8/lib:$LD_LIBRARY_PATH
```  

### 3. Modifying make file, Pythia setting(tcsh)  
```tcsh
sed -i -e 's/c++0x/c++1y/g' Makefile
setenv PYTHIA8 /cvmfs/cms.cern.ch/slc6_amd64_gcc530/external/pythia8/223-mlhled2/
setenv LD_LIBRARY_PATH $PYTHIA8/lib:$LD_LIBRARY_PATH
```  

### 4. Run!
```bash
make -j 4 HAS_PYTHIA8=true DelphesPythia8
```

