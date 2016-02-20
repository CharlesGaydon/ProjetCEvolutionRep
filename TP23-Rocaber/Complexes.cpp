#include <iostream>
#include "Complexes.h"
#include <cmath>
#include<cstdio>
using namespace std; 

//Constructeurs

Complexes::Complexes () {
	Re = 0.0;
	Im = 0.0;
}

Complexes::Complexes (double NRe, double NIm){
	Re = NRe;
	Im = NIm;
}

Complexes::Complexes(const Complexes& model){
	Re = model.get_Re();
	Im = model.get_Im();
}

//Accesseurs

double Complexes::get_Norme () const{
	return sqrt(Re*Re + Im*Im);
}

double Complexes::get_Re () const{
	return Re;
}

double Complexes::get_Im () const{
	return Im;
}

//Mutateurs

void Complexes::set_Re (double NRe){
	Re = NRe;
}

void Complexes::set_Im (double NIm){
	Im = NIm;
}

void Complexes::set (double NRe, double NIm){
	Re = NRe;
	Im = NIm;
}
//Méthodes 

Complexes& Complexes::operator= (const Complexes& A){
	Re = A.get_Re();
	Im = A.get_Im();
	return *this;
}

Complexes Complexes::T () const{
	return Complexes(Re,-Im);
}

Complexes Complexes::Ca () const{
	Complexes r = (*this)*(*this);
	return  r;
}

//Méthodes extérieures

Complexes operator+ (const Complexes& A, const Complexes& B){
	double NRe = A.get_Re() + B.get_Re();
	double NIm = A.get_Im() + B.get_Im();
	return Complexes(NRe,NIm);
}

Complexes operator- (const Complexes& A, const Complexes& B){
	double NRe = A.get_Re() - B.get_Re();
	double NIm = A.get_Im() - B.get_Im();
	return Complexes(NRe,NIm);
}

Complexes operator* (const Complexes& A, const Complexes& B){
	double NRe = A.get_Re()*B.get_Re() - A.get_Im()*B.get_Im();
	double NIm = A.get_Re()*B.get_Im() + B.get_Re()*A.get_Im();
	return Complexes(NRe,NIm);
}

Complexes operator/ (const Complexes& z, double div){
	double NRe = z.get_Re()/div;
	double NIm = z.get_Im()/div;
	return Complexes(NRe,NIm);
}

Complexes operator/ (const Complexes& A, const Complexes& B){
	Complexes r = (A*B.T())/((B.get_Norme())*B.get_Norme());
	return r;
}

void Mandelbrot(double pas){
	using namespace std; 

	FILE* f;
	f = fopen ("Mandelbrot.txt","wt");
	if (f == NULL){
		cout << "Impossible d'ouvrir le fichier en écriture !" << endl;
	}else{
			int di = 0;
			Complexes Uo = Complexes();
			Complexes c = Complexes();
			for(double x = -2.0 ; x <= 2 ; x = x + pas){
				c.set_Re(x);
				for(double y = -2.0; y<=2; y = y + pas){
					c.set_Im(y);
					di = Div(Uo,c);
					if (di == 0){
						fprintf (f, "%f %f %d \n", x, y, di);
					}
				}
			}
			fclose (f);
		}
}

int Div(const Complexes& Uo, const Complexes& c){
	Complexes Ui = Complexes(Uo);
	for(int i = 0;i<200;i++){
		Ui = Ui*Ui + c;
		if (i%49 == 0){
			if (Ui.get_Norme() > 4){
				return 1;
			}
		}
	} 
	if (Ui.get_Norme() < 4){
		return 0;
	}else{
		return 1;
	}
}

void MandelbrotSave(ImagePPM model){
	
	using namespace std;
	unsigned int W = model.get_W();
	unsigned int H = model.get_H();
	int MaxVal = model.get_MaxVal();
	string nfile = model.get_nfile();
	unsigned char* p = model.get_p();
	
	Complexes Uo = Complexes();
	Complexes c = Complexes();
	int di = 0;
	int index = 0;
	for (double x = 0 ; x<=W ; x++){
		
		double ax = (x - ((double) W)/2.0)/(((double)W)/4.0) ;		
		c.set_Re(ax);
		
		for (double y = 0; y<=H; y++){

			double ay = (y - ((double) H)/2.0)/(((double)H)/4.0) ;
			c.set_Im(ay);
			di = Div(Uo,c);	
			
			for (int c = 0 ; c<3 ; c++){
				
				index = (int) (x*W + y);
				cout << index << "et" << di <<endl;
				p[index*3 + c] = (unsigned int) (di*MaxVal);			
					
			}		
		}
	}
	model.saveImage(nfile);
		
}
