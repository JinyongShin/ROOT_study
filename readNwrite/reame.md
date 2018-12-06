### Simplest way to analyze Ntuple  
  
#### Make class  
> root filename.root  
> TTree *myTree = (TTree*)_file0->Get("treename");  
> myTree->MakeClass("test");  
#### test.C and test.h are made  
#### Edit the test.C file by using class defined in test.h  
#### Then run followings:  
> .L test.C
> test aaa
> aaa.Loop()


