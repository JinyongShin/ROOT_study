void N02_graph(){

	
// TGraph 로 바로 dat/txt/csv 파일을 읽어 옵니다
	TGraph *gr1 = new TGraph("graph.dat");
	
// 사각형 마커(21) 파랑색(4)	
	gr1->SetTitle("Graph");
	gr1->SetMarkerStyle(21);
	gr1->SetMarkerColor(4);
	gr1->Draw("ALP");

//////////////////////////////////////////////////////
// TGraph 공식 문서 참고                            //
// https://root.cern.ch/doc/master/classTGraph.html //
//////////////////////////////////////////////////////




}
