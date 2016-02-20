
#ifndef __TP2_3BIM_2016__Image__
#define __TP2_3BIM_2016__Image__

#include <iostream>
#include <cstring>
#include <fstream>


class Image
{
  
public:
  
  Image( void );
  Image( std::string file );
  Image( const Image& image );
  
  ~Image( void );
  
  inline int get_w( void ) const;
  inline int get_h( void ) const;
  inline int get_maxVal( void ) const;
  
  inline void set_w( int w );
  inline void set_h( int h );
  inline void set_maxVal( int maxVal );
  
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
 * \brief    Get image width
 * \details  --
 * \param    int w
 * \return   \e void
 */
inline void Image::set_w( int w )
{
  _w = w;
}

/**
 * \brief    Get image height
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


#endif /* defined(__TP2_3BIM_2016__Image__) */
