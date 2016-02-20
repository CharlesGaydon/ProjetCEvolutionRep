#ifndef IMAGEPPM_H_
#define IMAGEPPM_H_
#include <string.h>
#include <iostream>
#include <fstream>

using namespace std;


class ImagePPM{

	public :

	  //attributs
		
		unsigned char *p;
		
		//constructeurs
		
		ImagePPM ();
		ImagePPM (const ImagePPM&);
		ImagePPM(string);
		ImagePPM (unsigned int, unsigned int, int, string);
		
		//destructeurs
		~ImagePPM();

		//accesseurs
		unsigned int get_W () const;
		unsigned int get_H () const;
		unsigned char* get_p () const;
		int get_MaxVal () const;
		string get_nfile () const;
		
		//mutateurs
		void set_nfile (string);
		
		//méthodes
		void saveImage (string);
		void desaturate();
		void gaussian (double*);
		
		
	protected :
	
		//attributs
		
		string nfile;
		unsigned int W;
		unsigned int H;
		int MaxVal;
};

#endif //IMAGEPPM_H_
