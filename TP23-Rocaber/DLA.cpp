#include "DLA.h"
#include "ImagePPM.h"

DLA::DLA () {
	x = 0;
	y = 0;
	_L = 0;
	_p = nullptr;
	_image = ImagePPM();
	
}

DLA::DLA (const DLA& model) {
	x = model.x;
	y = model.y;
	_L = model.L();
	int** Pmodel= model.p();
	
	for (int k = 0; k< _L ; k++){
		for (int l = 0; l< _L ; l++){
			_p[k][l] = Pmodel[k][l];
		}
	}
	
	_image = ImagePPM(model.image());
	
}

DLA::DLA (int L){
	x = (int) L/4;
	y = (int) L/4;
	_L = L;
	_image = ImagePPM(_L,_L,255,"Aggreg.pmm");
	_p = new int*[_L];
	
	for (int k = 0; k<_L; k++){
		_p[k] = new int[_L];
		for (int l = 0; l<_L; l++){
			_p[k][l] = 0;
		}
	}	
	_p[3*x][3*y] = 1;
	this->showTab();
}
//accesseurs

int DLA::L() const{
	return _L;
}

int** DLA::p () const {
	return _p;
}

ImagePPM DLA::image () const{
	return _image;
}

//Méthodes

void DLA::aggreg (){
	//while this->keepGoing()
	while (this->keepGoing()){		
		if (this->Pout()){
			x = (int) _L/4;
			y = (int) _L/4;
		}else if (!(this->Pfree(x,y))){
			cout << "ATTRIBUTION DE la valeur" << endl;
			_p[x][y] = 1;
			x = (int) _L/4;
			y = (int) _L/4;
		} else {
			this->move();
		}
	}
	this->showTab();
	
	//saving
	string nameout = "Aggregation.ppm";
	ofstream g(nameout, ios::out | ios::trunc | ios::binary);
	g << "P6\n" << _L << " " << _L << "\n" << 255 << "\n";
	char col = 0;
	for (int i = 0; i<_L; i++){
		for (int j = 0; j<_L; j++){
			col = _p[i][j]*255;
			g.write((char*)&col, sizeof(char));
			g.write((char*)&col, sizeof(char));
			g.write((char*)&col, sizeof(char));
		}
	}
	g.close();
	cout << "ok attribution" << endl;
	cout << "Fin" << endl;
}

bool DLA::keepGoing (){
	
	return this->Pfree((int) (_L/4), (int) (_L/4));

}

//ok
bool DLA::Pout (){
	if (x>=_L || x<0 || y>=_L || y<0){
		return true;
	}
	return false;
}

bool DLA::Pfree (int X, int Y){
	for (int k = -1; k<2; k++){
		for (int l = -1; l<2; l++){
			if (X+k<_L && X+k>=0 && Y+l<_L && Y+l>=0){
				if (_p[X+k][Y+l] == 1){
					cout << "PAS FREE"<<endl; ; 
					return false;
				}
			}
		}
	}
	return true;
}

void DLA::move (){
	int a = (rand()%2)*2 -1;
	x = x + a;
	int b = (rand()%2)*2 -1;
	y = y + b;
	
}

void DLA::showTab(){
	for (int i = 0; i< _L; i++){
		for (int j = 0; j< _L; j++){
			cout << _p[i][j] << " ";
		}
		cout << endl;
	}
}



