

#include "ImagePPM.h"

//constructeurs

ImagePPM::ImagePPM (){
	W=0;
	H=0;
	MaxVal = 255;
	nfile = "";
	p = nullptr;
}

ImagePPM::ImagePPM (const ImagePPM& model){
	
	W = model.get_W();
	H = model.get_H();
	MaxVal = model.get_MaxVal();
	nfile = model.get_nfile();
	p = nullptr;
	int length = 3*H*W;
	
	if (length != 0){
		p = new unsigned char[length];
		for (int i = 0; i < length; i++){
			p[i] = model.get_p()[i];
		}
	}	
}

ImagePPM::ImagePPM (string Name){
	//lecture ASCII
	ifstream g;
	g.open(Name,ios::in);
	string P6;
	g >> P6 >> W >> H >> MaxVal;
	g.get();
	int length = 3*H*W;
	p = new unsigned char[length];
	g.read((char*) p, sizeof(unsigned char)*length);
	g.close();
}

ImagePPM::ImagePPM (unsigned int nW, unsigned int nH, int nMax, string newfile){
	W = (int) nW;
	H = (int) nH;
	MaxVal = nMax;
	nfile = newfile;
	p = new unsigned char[3*W*H];
}



//destructeurs
ImagePPM::~ImagePPM (){
delete [] p;	
}

//accesseurs

unsigned int ImagePPM::get_W () const{
	return W;
}

unsigned char* ImagePPM::get_p () const{
	return p;
}

unsigned int ImagePPM::get_H () const{
	return H;
}

int ImagePPM::get_MaxVal () const{
	return MaxVal;
}

string ImagePPM::get_nfile () const{
	return nfile;
}

//Mutateurs

void ImagePPM::set_nfile (string newname){
	nfile = newname;
} 

//Méthode

void ImagePPM::saveImage (string nameout){
	
	ofstream g(nameout, ios::out | ios::trunc | ios::binary);
	g << "P6\n" << W << " " << H << "\n" << MaxVal << "\n";
	g.write((char*)p, sizeof(char)*W*H*3);
	g.close();
}


void ImagePPM::desaturate (){
	
	for (int x = 0; x<W; x++){
		
		for (int y = 0; y<H; y++){
			
			double r = (double)p[(x*H+y)*3];
			double g = (double)p[(x*H+y)*3+1];
			double b = (double)p[(x*H+y)*3+2];
			double m = 0.21*r+0.71*g+0.07*b;
			
			if (m<0){
				m = 0.0;
			}else if (m>MaxVal) {
				m = (double) MaxVal;
			}
			
			p[(x*H+y)*3] = (unsigned char) m;
			p[(x*H+y)*3+1] = (unsigned char) m;
			p[(x*H+y)*3+2] = (unsigned char) m;
		}
	}

} 

void ImagePPM::gaussian (double* matrix){
	unsigned char* new_data = new unsigned char[W*H*3];
  for (int x = 0; x < W; x++)
  {
    for (int y = 0; y < H; y++)
    {
      for(int c = 0; c < 3; c++)
      {
        double s   = 0.0;
        double sum = 0.0;
        for (int i = -1; i < 2; i++)
        {
          for(int j = -1; j < 2; j++)
          {
            if (x+i < W && x+i >= 0 && y+j < H && y+j >= 0)
            {
              s   += (double)p[((x+i)*H+(y+j))*3+c]*matrix[(i+1)+3*(j+1)];
              sum += matrix[(i+1)+3*(j+1)];
            }
          }
        }
        s /= sum;
        if (s > 255.0)
        {
          s = 255.0;
        }
        if (s < 0.0)
        {
          s = 0.0;
        }
        new_data[((x)*H+(y))*3+c] = (unsigned char)s;
      }
    }
  }
	memcpy(p, new_data, sizeof(unsigned char)*W*H*3);
  delete[] new_data;
  new_data = nullptr;
	
	
}



