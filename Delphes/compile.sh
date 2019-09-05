####  Compiling Delphes ####
##  --Please modify the path 

### Specifying location of header file
export PATH=/x3/cms/jelee/MCProd/Delphes3.4.2/classes:$PATH

### Specifying location of lib.so files
export LD_LIBRARY_PATH=/x3/cms/jelee/MCProd/Delphes3.4.2:$LD_LIBRARY_PATH

### --Compile it!
## -I(location of header) -L(location of lib.so) 
g++ `root-config --cflags` `root-config --libs` $1.C -I/x3/cms/jelee/MCProd/Delphes3.4.2/classes -L/x3/cms/jelee/MCProd/Delphes3.4.2 -lDelphes -o $1.exe

