

#ifndef COMPLEXES_H_
#define COMPLEXES_H_
#include "ImagePPM.h"

class Complexes {
	protected :
		double Re;
		double Im;
		double Norme;
		
	public :
		//constructeurs
			Complexes();
			Complexes(double, double);
			Complexes(const Complexes&);
		//Accesseurs
			double get_Norme() const;
			double get_Re() const;
			double get_Im() const; 
		
		//Mutateurs
			void set_Re(double);
			void set_Im(double);
			void set(double, double);
		//Méthodes 
			Complexes& operator= (const Complexes&);
			Complexes T() const;
			Complexes Ca() const;

		//Méthodes extérieures
		friend Complexes operator+ (const Complexes&,const Complexes&);
		friend Complexes operator- (const Complexes&,const Complexes&);
		friend Complexes operator* (const Complexes&,const Complexes&);
		friend Complexes operator/ (const Complexes&,const Complexes&);
		friend Complexes operator/ (const Complexes&,double);
		
};

void Mandelbrot(double); 
void MandelbrotSave(ImagePPM);
int Div(const Complexes&, const Complexes&);
#endif //COMPLEXES_H_
