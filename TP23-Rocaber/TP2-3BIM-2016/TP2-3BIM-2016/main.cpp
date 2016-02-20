
#include <iostream>
#include "Image.h"


int main( int argc, const char * argv[] )
{
  Image* img1 = new Image("m.ppm");
  
  Image* img2 = new Image(*img1);
  img2->desaturate();
  img2->save("desaturate.ppm");
  
  Image* img3 = new Image(*img1);
  double matrix[9] = {1, 2, 1, 2, 4, 2, 1, 2, 1};
  img3->gaussian_blur(matrix);
  img3->save("blur.ppm");
  
  delete img1;
  delete img2;
  delete img3;
  
  return EXIT_SUCCESS;
}
