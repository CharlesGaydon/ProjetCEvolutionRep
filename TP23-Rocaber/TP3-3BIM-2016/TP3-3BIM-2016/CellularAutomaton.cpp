
#include "CellularAutomaton.h"


/**
 * \brief    Constructor
 * \details  --
 * \param    int size
 * \param    int T
 * \return   \e void
 */
CellularAutomaton::CellularAutomaton( int size, int T )
{
  _size = size;
  _T    = T;
  _data = new bool*[_T];
  for (int i = 0; i < _T; i++)
  {
    _data[i] = new bool[_size];
  }
  _img = nullptr;
  
  for (int i = 0; i < _size; i++)
  {
    _data[0][i] = false;
  }
  _data[0][_size/2] = true;
}

/**
 * \brief    Destructor
 * \details  --
 * \param    void
 * \return   \e void
 */
CellularAutomaton::~CellularAutomaton( void )
{
  for (int i = 0; i < _T; i++)
  {
    delete[] _data[i];
    _data[i] = nullptr;
  }
  delete[] _data;
  _data = nullptr;
}

/**
 * \brief    Run the cellular automaton
 * \details  --
 * \param    void
 * \return   \e void
 */
void CellularAutomaton::run( void )
{
  for (int t = 1; t < _T; t++)
  {
    iterate(t);
  }
}

/**
 * \brief    Save a picture of the cellular automaton
 * \details  --
 * \param    std::string picture_name
 * \return   \e void
 */
void CellularAutomaton::save_picture( std::string picture_name )
{
  _img = new Image(_T, _size, 255);
  for (int x = 0; x < _T; x++)
  {
    for (int y = 0; y < _size; y++)
    {
      if (_data[x][y])
      {
        _img->set_color(x, y, 0, 255);
        _img->set_color(x, y, 1, 255);
        _img->set_color(x, y, 2, 255);
      }
    }
  }
  _img->save(picture_name);
  delete _img;
  _img = nullptr;
}

/**
 * \brief    Compute one step from time t-1 to time t
 * \details  --
 * \param    int t
 * \return   \e void
 */
void CellularAutomaton::iterate( int t )
{
  for (int i = 0; i < _size; i++)
  {
    bool a = _data[t-1][(i-1+_size)%_size];
    bool b = _data[t-1][(i+_size)%_size];
    bool c = _data[t-1][(i+1+_size)%_size];
    if (a && b && c)
    {
      _data[t][i] = false;
    }
    else if (a && b && !c)
    {
      _data[t][i] = false;
    }
    else if (a && !b && c)
    {
      _data[t][i] = false;
    }
    else if (a && !b && !c)
    {
      _data[t][i] = true;
    }
    else if (!a && b && c)
    {
      _data[t][i] = true;
    }
    else if (!a && b && !c)
    {
      _data[t][i] = true;
    }
    else if (!a && !b && c)
    {
      _data[t][i] = true;
    }
    else if (!a && !b && !c)
    {
      _data[t][i] = false;
    }
  }
}


