
#include <iostream>
#include "DLA.h"
#include "CellularAutomaton.h"


int main( int argc, const char * argv[] )
{
  /*-----------------------*/
  /* 1) DLA                */
  /*-----------------------*/
  DLA* dla = new DLA(100);
  dla->run_DLA();
  dla->save_picture("DLA.ppm");
  delete dla;
  dla = nullptr;
  
  /*-----------------------*/
  /* 2) Cellular automaton */
  /*-----------------------*/
  CellularAutomaton* automaton = new CellularAutomaton(400, 400);
  automaton->run();
  automaton->save_picture("automaton.ppm");
  delete automaton;
  automaton = nullptr;
  
  return EXIT_SUCCESS;
}
