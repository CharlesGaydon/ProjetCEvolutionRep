
#include "Environnement.h"

Environnement::Environnement () {
	W = 0;
	H = 0;
	D = 0;
	
	res = nullptr;
	
}

Environnement::Environnement (unsigned int nW, unsigned int nH, double nAinit) {
	
	W = nW;
	H = nH;
	D = 0.1;
	Ainit = nAinit;
	
	res = new double**[W];
	
	for (int i = 0 ; i< W ; i++){
		
		res[i] = new double*[H];
		
		for (int j = 0 ; j<H ; j++){
			
			res[i][j] = new double[3];
			res[i][j][0] = Ainit;
			
			for (int k = 1 ; k<3 ; k++){
				res[i][j][k] = 0;
			}
			
		}
		
	}

}

Environnement::Environnement (unsigned int nW, unsigned int nH, double nAinit, double nD) {
	
	W = nW;
	H = nH;
	D = nD;
	Ainit = nAinit;
	
	res = new double**[W];
	
	for (int i = 0 ; i< W ; i++){
		
		res[i] = new double*[H];
		
		for (int j = 0 ; j<H ; j++){
			
			res[i][j] = new double[3];
			res[i][j][0] = Ainit;
			
			for (int k = 1 ; k<3 ; k++){
				res[i][j][k] = 0;
			}
			
		}
		
	}
	
}

Environnement::~Environnement (){
	
	for (int i = 0 ; i< W ; i++){

		for (int j = 0 ; j<H ; j++){
			for (int k = 1 ; k<3 ; k++){
				delete[] res[i][j];
			}
			delete[] res[i];		
				
		}		
		delete[] res;
	}
	
}








