
#include "Array.h"

//Constructeurs

Array::Array (){
	size_ = 0;
	pTab = nullptr;
}

Array::Array (int Nsize){
	size_ = Nsize;
	pTab = new double[Nsize];
	for(int i = 0; i<Nsize; i++){
		pTab[i] = 0;
	} 
}

Array::Array (int Nsize, double Nvalue){
	size_ = Nsize;
	pTab = new double[Nsize];
	for(int i = 0; i<Nsize; i++){
		pTab[i] = Nvalue;
	} 
}

Array::Array (const Array& A){
	int a = A.size();
	size_ = a;
	for (int i = 0 ; i< a ; i++){
		pTab[i] = A[i]; 
	}
}

//Destructeurs
Array::~Array (){
	delete[] (pTab);
}

//Accesseurs

int Array::size() const{
	return size_;
}

double Array::getValue (const int indice){
	return pTab[indice];
}

//Mutateurs

double& Array::operator[] (const int indice){
	return pTab[indice];
}

double Array::operator[] (const int indice) const{
	return pTab[indice];
}

//Méthodes publiques

Array operator+(const Array& A, const Array& B){
	int a = A.size() ;
	int b = B.size();
	int Nsize = a + b;
	Array sum = Array(Nsize);
	for (int i = 0 ; i< a ; i++){
		sum[i] = A[i]; 
	}
	for (int i = a ; i< Nsize ; i++){
		sum[i] = B[i-a];
	}
	return sum;
}

