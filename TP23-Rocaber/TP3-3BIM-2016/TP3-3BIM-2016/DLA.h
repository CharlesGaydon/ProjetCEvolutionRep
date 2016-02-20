
#ifndef __TP3_3BIM_2016__DLA__
#define __TP3_3BIM_2016__DLA__

#include <iostream>
#include <cstring>
#include "Image.h"


class DLA
{

public:
  
  DLA( void ) = delete;
  DLA( int L );
  DLA( const DLA& dla ) = delete;
  
  ~DLA( void );
  
  inline bool get_state( int x, int y ) const;
  inline void set_state( int x, int y, bool state );
  
  void run_DLA( void );
  void save_picture( std::string picture_name );
  
protected:
  
  bool simulate_one_particle( void );
  bool toFreeze( int x, int y );
  bool toRemove( int x, int y );
  
  int    _L;     /*!< Arena dimension */
  bool*  _arena; /*!< DLA arena       */
  Image* _img;   /*!< Image           */
  
};

/**
 * \brief    Get state at coordinates (x, y)
 * \details  --
 * \param    int x
 * \param    int y
 * \return   \e bool
 */
inline bool DLA::get_state( int x, int y ) const
{
  return _arena[x*_L+y];
}

/**
 * \brief    Set state at coordinates (x, y)
 * \details  --
 * \param    int x
 * \param    int y
 * \param    bool state
 * \return   \e void
 */
inline void DLA::set_state( int x, int y, bool state )
{
  _arena[x*_L+y] = state;
}


#endif /* defined(__TP3_3BIM_2016__DLA__) */
