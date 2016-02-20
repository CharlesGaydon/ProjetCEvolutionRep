
#ifndef __TP3_3BIM_2016__Image__
#define __TP3_3BIM_2016__Image__

#include <iostream>
#include <cstring>
#include <fstream>


class Image
{
  
public:
  
  Image( void );
  Image( int W, int H, int maxVal );
  Image( std::string file );
  Image( const Image& image );
  
  ~Image( void );
  
  inline int           get_w( void ) const;
  inline int           get_h( void ) const;
  inline int           get_maxVal( void ) const;
  inline unsigned char get_color( int x, int y, int c );
  
  inline void set_w( int w );
  inline void set_h( int h );
  inline void set_maxVal( int maxVal );
  inline void set_color( int x, int y, int c, unsigned char val );
  
  void save( std::string file );
  void desaturate( void );
  void gaussian_blur( double* matrix );
  
private:
  
  int            _w;      /*!< Image width (pixels)  */
  int            _h;      /*!< Image heigth (pixels) */
  int            _maxVal; /*!< Maximum canal value   */
  unsigned char* _data;   /*!< Image data            */
  
};


/**
 * \brief    Get image width
 * \details  --
 * \param    void
 * \return   \e int
 */
inline int Image::get_w( void ) const
{
  return _w;
}

/**
 * \brief    Get image height
 * \details  --
 * \param    void
 * \return   \e int
 */
inline int Image::get_h( void ) const
{
  return _h;
}

/**
 * \brief    Get maximum clanal value
 * \details  --
 * \param    void
 * \return   \e int
 */
inline int Image::get_maxVal( void ) const
{
  return _maxVal;
}

/**
 * \brief    Get pixel color
 * \details  --
 * \param    int x
 * \param    int y
 * \param    int c
 * \return   \e int
 */
inline unsigned char Image::get_color( int x, int y, int c )
{
  return _data[(x*_h+y)*3+c];
}

/**
 * \brief    Set image width
 * \details  --
 * \param    int w
 * \return   \e void
 */
inline void Image::set_w( int w )
{
  _w = w;
}

/**
 * \brief    Set image height
 * \details  --
 * \param    int h
 * \return   \e void
 */
inline void Image::set_h( int h )
{
  _h = h;
}

/**
 * \brief    Set maximum clanal value
 * \details  --
 * \param    int maxVal
 * \return   \e void
 */
inline void Image::set_maxVal( int maxVal )
{
  _maxVal = maxVal;
}

/**
 * \brief    Set pixel color
 * \details  --
 * \param    int x
 * \param    int y
 * \param    int c
 * \param    unsigned char val
 * \return   \e void
 */
inline void Image::set_color( int x, int y, int c, unsigned char val )
{
  _data[(x*_h+y)*3+c] = val;
}


#endif /* defined(__TP3_3BIM_2016__Image__) */
