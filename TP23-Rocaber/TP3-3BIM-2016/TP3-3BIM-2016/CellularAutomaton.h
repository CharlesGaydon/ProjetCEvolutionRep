
#ifndef __TP3_3BIM_2016__CellularAutomaton__
#define __TP3_3BIM_2016__CellularAutomaton__

#include <iostream>
#include "Image.h"


class CellularAutomaton
{
  
public:
  
  CellularAutomaton( void ) = delete;
  CellularAutomaton( int size, int T );
  CellularAutomaton( const CellularAutomaton& automaton) = delete;
  
  ~CellularAutomaton( void );
  
  void run( void );
  void save_picture( std::string picture_name );
  
protected:
  
  void iterate( int t );
  
  int    _size; /*!< 1D automaton size    */
  int    _T;    /*!< Number of iterations */
  bool** _data; /*!< 2D data (1D * time)  */
  Image* _img;  /*!< Image                */
  
};


#endif /* defined(__TP3_3BIM_2016__CellularAutomaton__) */
