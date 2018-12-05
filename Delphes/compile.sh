# --Edit the path 
g++ `root-config --cflags` `root-config --libs` Ztuto.C -I/home/jkim/Generator/Delphes/Delphes-3.4.1 -L/home/jkim/Generator/Delphes/Delphes-3.4.1 -lDelphes -o Ztuto.exe

