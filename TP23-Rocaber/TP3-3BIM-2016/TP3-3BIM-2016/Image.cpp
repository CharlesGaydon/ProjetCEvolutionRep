
#include "Image.h"


/**
 * \brief    Default constructor
 * \details  --
 * \param    void
 * \return   \e void
 */
Image::Image( void )
{
  _w      = 0;
  _h      = 0;
  _maxVal = 0;
  _data   = nullptr;
}

/**
 * \brief    Constructor
 * \details  --
 * \param    int W
 * \param    int H
 * \param    int maxVal
 * \return   \e void
 */
Image::Image( int W, int H, int maxVal )
{
  _w      = W;
  _h      = H;
  _maxVal = maxVal;
  _data   = new unsigned char[_w*_h*3];
  for (int i = 0; i < _w*_h*3; i++)
  {
    _data[i] = 0;
  }
}

/**
 * \brief    Constructor
 * \details  --
 * \param    std::string file
 * \return   \e void
 */
Image::Image( std::string file )
{
  std::ifstream f(file.c_str(), std::ios::in);
  std::string p6;
  f >> p6;
  f >> _w >> _h >> _maxVal;
  f.get();
  _data = new unsigned char[_w*_h*3];
  f.read((char*)_data, sizeof(unsigned char)*_w*_h*3);
  f.close();
}

/**
 * \brief    Copy constructor
 * \details  --
 * \param    const Array& array
 * \return   \e void
 */
Image::Image( const Image& image )
{
  _w      = image._w;
  _h      = image._h;
  _maxVal = image._maxVal;
  _data   = new unsigned char[_w*_h*3];
  memcpy(_data, image._data, sizeof(unsigned char)*_w*_h*3);
}

/**
 * \brief    Destructor
 * \details  --
 * \param    void
 * \return   \e void
 */
Image::~Image( void )
{
  delete[] _data;
  _data = nullptr;
}

/**
 * \brief    Save the image in a file
 * \details  --
 * \param    std::string file
 * \return   \e void
 */
void Image::save( std::string file )
{
  std::ofstream f(file.c_str(), std::ios::out | std::ios::trunc | std::ios::binary);
  f << "P6\n" << _w << " " << _h << "\n" << _maxVal << "\n";
  f.write((char*)_data, sizeof(char)*_w*_h*3);
  f.close();
}

/**
 * \brief    Desaturate the image
 * \details  --
 * \param    void
 * \return   \e void
 */
void Image::desaturate( void )
{
  for (int x = 0; x < _w; x++)
  {
    for (int y = 0; y < _h; y++)
    {
      double r = (double)_data[(x*_h+y)*3];
      double g = (double)_data[(x*_h+y)*3+1];
      double b = (double)_data[(x*_h+y)*3+2];
      double m = 0.21*r+0.71*g+0.07*b;
      if (m < 0.0)
      {
        m = 0.0;
      }
      if (m > _maxVal)
      {
        m = (double)_maxVal;
      }
      _data[(x*_h+y)*3]   = (unsigned char)m;
      _data[(x*_h+y)*3+1] = (unsigned char)m;
      _data[(x*_h+y)*3+2] = (unsigned char)m;
    }
  }
}

/**
 * \brief    Apply a gaussian blur to the image
 * \details  --
 * \param    double* matrix
 * \return   \e void
 */
void Image::gaussian_blur( double* matrix )
{
  unsigned char* new_data = new unsigned char[_w*_h*3];
  for (int x = 0; x < _w; x++)
  {
    for (int y = 0; y < _h; y++)
    {
      for(int c = 0; c < 3; c++)
      {
        double s   = 0.0;
        double sum = 0.0;
        for (int i = -1; i < 2; i++)
        {
          for(int j = -1; j < 2; j++)
          {
            if (x+i < _w && x+i >= 0 && y+j < _h && y+j >= 0)
            {
              s   += (double)_data[((x+i)*_h+(y+j))*3+c]*matrix[(i+1)+3*(j+1)];
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
        new_data[((x)*_h+(y))*3+c] = (unsigned char)s;
      }
    }
  }
  memcpy(_data, new_data, sizeof(unsigned char)*_w*_h*3);
  delete[] new_data;
  new_data = nullptr;
}


