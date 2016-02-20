#include <iostream>
#include <fstream>

#include "ImagePPM.h"
#include "Array.h"
#include "RandomArray.h"
#include "Complexes.h"
#include "DLA.h"
#include "Poly.h"
#include "Cellular.h"

#include <string>

using namespace std;
int main(int argc, char **argv)
{
	using namespace std;
	
	//~int size = 600;
	//~DLA Pla2 = DLA(size);
	//~cout << Pla2.L()<<endl;
	//~//Pla2.aggreg();
//~
	//~Cellular C = Cellular();
	//~
	//~Cellular C2 = Cellular(C);
	//~
	//~Cellular C3 = Cellular(800);
	//C3.calculate();
	cout << "okaay" << endl;
	//~double *co = new double[3];
	//~co[0] = 3;
	//~co[2] = 7;

	double co[4] = {1.5,1.5,-1.5,5.0};
	Poly p = Poly(co,4);
	double ci[3] = {-1.5,3,1.5};
	Poly pr = Poly(ci,3);
	Poly p4 = p + pr; //attention opérateur d'attribution non fait
	Poly p5 = p4;
	cout << p4.get_size() <<endl;

	//delete co;
	
	return 0;
}


	//~//ecriture
	//~ofstream f;
	//~int a = 42;
	//~f.open("TestEcriture.txt",ios::out | ios::trunc);
	//~f<< "This is a test "<<a<<"\n";
	//~f.close();
	//~
	//~//lecture
	//~ifstream g;
	//~g.open("TestEcriture.txt",ios::in);
	//~string l,m,n,o,q;
	//~int p;
	//~g>>l>>m>>n>>o>>p>>q;
	//~cout << l<<m<<n<<o<<p<<q<<endl;
	//~g.close();
	//~
	//~int b = 25;
	//~ofstream Ob;
	//~Ob.open("TestBinaire.txt",ios::out | ios::trunc | ios::binary);
	//~Ob.write((char*)&b , sizeof(int));
	//~Ob.close();
	//~
	//~ifstream Ib;
	//~Ib.open("TestBinaire.txt",ios::in |ios::binary);
	//~Ib.read((char*)&a,sizeof(int));
	//~Ib.close();
	//~cout <<a<<endl;
	
	//ImagePPM
	//~
	//~ImagePPM I = ImagePPM("m.ppm");
	//~ImagePPM PM = ImagePPM("p.ppm");
	//~ImagePPM IM = ImagePPM("im.ppm");
	//~cout << IM.get_W() <<endl;
//~
	//~I.desaturate();
	//~IM.desaturate();
	//~I.saveImage("mD.ppm");
	//~IM.saveImage("imD.ppm");
	//~
	//~double matrix[9] = {1, 2, 1, 2, 4, 2, 1, 2, 1};
	//~PM.gaussian(matrix);
	//~PM.saveImage("pGaussian.ppm"); 
	//~
	//~ImagePPM Man = ImagePPM(800,800,255,"Mandelbrot.ppm");
	//~MandelbrotSave(Man);
	//~


