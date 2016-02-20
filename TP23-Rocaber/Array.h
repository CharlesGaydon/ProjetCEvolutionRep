#include <iostream>

#ifndef ARRAY_H_
#define ARRAY_H_

class Array {
	public :
		//Constructeurs
		
		Array();
		Array(int);
		Array(int,double);
		Array(const Array&);
		//Destructeurs
		
		virtual ~Array();
		
		//Accesseurs
		
		int size() const;
		double getValue(const int);
		//Mutateurs
		
		double& operator[] (const int);
		double operator[] (const int indice) const;
		
		//Méthodes
		friend Array operator+(const Array&, const Array&); 
		  
	protected :
		int size_;
		double *pTab;
	
};

#endif // ARRAY_H_
