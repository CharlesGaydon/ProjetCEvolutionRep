#include <iostream>

#ifndef POLY_H_
#define POLY_H_

class Poly {
	public :
		//Constructeurs
		
		Poly();
		Poly(int Nsize, double Nvalue = 1.0); //argument par defaut : il faut toujours préciser les noms des variables!
		Poly(double* coeffs, int Nsize);
		Poly(const Poly	&);
		
		//Destructeurs
		
		virtual ~Poly();
		
		//Accesseurs
		
		int get_size() const;
		double* get_poly() const;
		
		//Mutateurs
		
		//Méthodes
		Poly& operator= (const Poly& B);
		friend Poly operator+(const Poly&, const Poly&); 
		friend Poly operator-(const Poly&, const Poly&); 
		
		Poly derivation ();
		  
	protected :
		int size;
		double *poly;
	
};

#endif // POLY_H_
