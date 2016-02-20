#include <iostream>
#include "Poly.h"
using namespace std; 

Poly::Poly (){
	size = 0;
	poly = nullptr;
}

Poly::Poly (int Nsize, double Nvalue){
	size = Nsize;
	poly = new double[size];
	for (int k = 0 ; k<size ; k++){
		poly[k] = Nvalue;
	}
	cout << Nvalue << endl;
}
//~Poly::Poly (int Nsize){
	//~int Nvalue = 1;
	//~size = Nsize;
	//~poly = new double[size];
	//~for (int k = 0 ; k<size ; k++){
		//~poly[k] = Nvalue;
	//~}
//~}

Poly::Poly (const Poly& model){
	size = model.get_size();
	poly = new double[size];
	
	double* polymodel = model.get_poly();
	
	for (int k = 0 ; k<size ; k++){
		poly[k] = polymodel[k];
	}
}

Poly::Poly (double* coeffs,int Nsize){
	size = Nsize;
	poly = new double[size];
	for (int k = 0 ; k<Nsize ; k++){
		poly[k] = coeffs[k];
	}	
}
//destructeur

Poly::~Poly (){
	delete[] poly;
}


//getters

int Poly::get_size () const{
	return size;
}

double* Poly::get_poly () const{
	return poly;
}

Poly Poly::derivation (){
	double* poD = new double[size-1];
	for (int k = 0; k<size-1; k++ ){
		
	}
	
}


//opérateurs

Poly& Poly::operator= (const Poly& B){
	size = B.get_size();
	poly = new double[size];
	
	double* polymodel = B.get_poly();
	
	for (int k = 0 ; k<size ; k++){
		poly[k] = polymodel[k];
	}	
	
	return *this;
}

Poly operator+(const Poly& left, const Poly& right){
	int sizel = left.get_size();
	int sizer = right.get_size();
	int SIZE = 1;
	int LONGUEUR = 1;
	double* base = nullptr;
	double* ajoute = nullptr;
	
	if (sizel<=sizer){
		SIZE = sizel;
		LONGUEUR = sizer;
		base = right.get_poly();
		ajoute = left.get_poly();
		
	}else {
		SIZE = sizer;
		LONGUEUR = sizel;
		base = left.get_poly();
		ajoute = right.get_poly();
	}
	for(int i = 0; i<SIZE ; i++){
		base[i]+=ajoute[i];
	}
	return Poly(base,LONGUEUR);
}

Poly operator-(const Poly& left, const Poly& right){
	int sizel = left.get_size();
	int sizer = right.get_size();
	int SIZE = 1;
	int LONGUEUR = 1;
	double* base = nullptr;
	double* ajoute = nullptr;
	
	if (sizel<=sizer){
		SIZE = sizel;
		LONGUEUR = sizer;
		base = right.get_poly();
		ajoute = left.get_poly();
		
	}else {
		SIZE = sizer;
		LONGUEUR = sizel;
		double* base = left.get_poly();
		double* ajoute = right.get_poly();
	}
	for(int i = 0; i<SIZE ; i++){
		base[i]-=ajoute[i];
	}
	
	return Poly(base,LONGUEUR);
}

