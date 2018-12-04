#include <iostream>
using namespace std;


void N02_hist_function(){
	
	TCanvas *c1 = new TCanvas("c1","c1",1500,1500);
	c1->cd(1);
	
	// 1차원 Double 형 히스토그램을 선언합니다.
	// x축 범위는 0 부터 10 까지 총 200 개의 bin으로 나눕니다
	TH1D *h1 = new TH1D("Gauss","Gauss",200,0,10);
	
	// 가우시안 분포를 넣기위해 평균값과 표준편차를 정의합니다
	double mean=5;
	double sigma=0.5;
	
	// 현재 히스토그램의 세부적인 내용을 히스토그램과 함께 보여줍니다.
	// 평균값, RMS, Overflower, Integral 등을 포함시켰습니다.
	// 숫자 1 의 갯수가 늘어날수록 많은 정보가 표기됩니다.
	gStyle->SetOptStat(1111111);
	
	// 총 1만개의 데이터를 미리 정의한 평균값과 표준편차를 가지는
	// 가우시안 분포로 랜덤적으로 히스토그램에 Fill 함니다.
	for(int i=0; i<10000; i++){
		h1->Fill(gRandom->Gaus(mean,sigma));
	}	
	
	// 이번에는 일정한 형태로 랜덤하게 5만개를 Fill합니다
	// 따라서 총 6만개의 Entries 가 생겼습니다
	for(int i=0; i<50000; i++){
		h1->Fill(gRandom->Uniform(10));
	}	
	
	// 히스토그램은 bin 을 통해서만 content(y값)에 접근할 수 있습니다.
	// 가장 큰 content값의 bin을 가져오는 코드입니다
	int binMax = h1->GetMaximumBin();
	
	// 빈은 하나의 막대기로 볼 수 있는데 그 중심이 정확히 x축의 어디에 위치했는지
	// x 축의 값을 가져옵니다
	double binCenter = h1->GetXaxis()->GetBinCenter(binMax);
	
	//해당 x축값의 빈값을 가져옵니다 GetBinCenter와 반대입니다
	double whreBin = h1->GetXaxis()->FindBin(5);
	
	// 해당 빈의 content의 Sqrt값을 가져옵니다
	double binError  = h1->GetBinError(binMax);
	
	// 히스토그램의 총 빈 수를 가져옵니다
	double totalbin = h1->GetNbinsX();

	// 히스토그램의 x축 range / 총 빈수를 가져옵니다
	double xperbin = h1->GetBinWidth(1) ;
	

	cout <<  "Maxbin:		" << binMax << endl;
	cout <<  "WhereIsbin:   " << whreBin << endl;
	cout <<  "BinCenter:	" << binCenter << endl;
	cout <<  "BinError:		" << binError	<< endl;
	cout <<  "Sqrt(Maxbin contents):	"<< sqrt(h1->GetBinContent(binMax)) << endl;
	cout <<  "Totalbin: 				" << totalbin << endl;
	cout <<  "Xrange/totalbin: 			" << xperbin << endl;
	// X 축의 범위를 새롭게 조절 할 수 있습니다.
	//h1->GetXaxis()->SetRangeUser(4,6);
	h1->Draw();

}

