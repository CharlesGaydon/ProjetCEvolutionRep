#include <iostream>
#include "Environnement.h"

Environnement::Environnement () {
	W = 0;
	H = 0;
	D = 0;
	
	resA = nullptr;
	resB = nullptr;
	resC = nullptr;

	NresA = nullptr;
	NresB = nullptr;
	NresC = nullptr;
	
}

Environnement::Environnement (unsigned int nW, unsigned int nH, double nAinit) {
	
	W = nW;
	H = nH;
	D = 0.1;
	Ainit = nAinit;
	
	//Ressources
	
	resA = new double*[W];
	resB = new double*[W];
	resC = new double*[W];

	NresA = new double*[W];
	NresB = new double*[W];
	NresC = new double*[W];
	
	for (unsigned int i = 0 ; i< W ; i++){	
		
		resA[i] = new double[H];
		resB[i] = new double[H];
		resC[i] = new double[H];
		
		NresA[i] = new double[H];
		NresB[i] = new double[H];
		NresC[i] = new double[H];
		
		for (unsigned int j = 0 ; j<H ; j++){			
			resA[i][j] = Ainit;	
			resB[i][j] = 0;	
			resC[i][j] = 0;
			
			NresA[i][j] = Ainit;	
			NresB[i][j] = 0;	
			NresC[i][j] = 0;			
		}	
		
	}

}

Environnement::Environnement (unsigned int nW, unsigned int nH, double nAinit, double nD) {
	
	W = nW;
	H = nH;
	D = nD;
	Ainit = nAinit;
	
	//Ressources
	
	resA = new double*[W];
	resB = new double*[W];
	resC = new double*[W];

	NresA = new double*[W];
	NresB = new double*[W];
	NresC = new double*[W];
	
	for (unsigned int i = 0 ; i< W ; i++){	
		
		resA[i] = new double[H];
		resB[i] = new double[H];
		resC[i] = new double[H];
		
		NresA[i] = new double[H];
		NresB[i] = new double[H];
		NresC[i] = new double[H];
		
		for (unsigned int j = 0 ; j<H ; j++){			
			resA[i][j] = Ainit;	
			resB[i][j] = 0;	
			resC[i][j] = 0;
			
			NresA[i][j] = Ainit;	
			NresB[i][j] = 0;	
			NresC[i][j] = 0;			
		}	
		
	}
	
}

Environnement::~Environnement (){
	
	for (int i = 0 ; i< W ; i++){	
		delete[] resA[i];
		delete[] resB[i];
		delete[] resC[i];
		
		delete[] NresA[i];
		delete[] NresB[i];
		delete[] NresC[i];				
	}		
	delete[] resA;
	delete[] resB;
	delete[] resC;
	
	delete[] NresA;
	delete[] NresB;
	delete[] NresC;
}


