
#include "DLA.h"


/**
 * \brief    Constructor
 * \details  --
 * \param    int L
 * \return   \e void
 */
DLA::DLA( int L )
{
  _L = L;
  _arena = new bool[_L*_L];
  for (int i = 0; i < _L*_L; i++)
  {
    _arena[i] = false;
  }
  set_state(3*_L/4, 3*_L/4, true);
  _img = nullptr;
}

/**
 * \brief    Destructor
 * \details  --
 * \param    void
 * \return   \e void
 */
DLA::~DLA( void )
{
  delete[] _arena;
  _arena = nullptr;
}

/**
 * \brief    run DLA
 * \details  --
 * \param    void
 * \return   \e void
 */
void DLA::run_DLA( void )
{
  bool stop_DLA = false;
  while (!stop_DLA)
  {
    stop_DLA = simulate_one_particle();
  }
}

/**
 * \brief    Save a picture of the DLA
 * \details  --
 * \param    std::string picture_name
 * \return   \e void
 */
void DLA::save_picture( std::string picture_name )
{
  _img = new Image(_L, _L, 255);
  for (int x = 0; x < _L; x++)
  {
    for (int y = 0; y < _L; y++)
    {
      if (get_state(x, y))
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
 * \brief    Simulate one particle
 * \details  --
 * \param    bool
 * \return   \e void
 */
bool DLA::simulate_one_particle( void )
{
  int x         = _L/4;
  int y         = _L/4;
  bool stop_DLA = true;
  while (!toFreeze(x, y) && !toRemove(x, y))
  {
    x += rand()%3-1;
    y += rand()%3-1;
    stop_DLA = false;
  }
  if (toFreeze(x, y))
  {
    set_state(x, y, true);
  }
  return stop_DLA;
}

/**
 * \brief    Check if the particle (x,y) should be freezed
 * \details  --
 * \param    bool
 * \return   \e void
 */
bool DLA::toFreeze( int x, int y )
{
  for (int i = -1; i < 2; i++)
  {
    for (int j = -1; j < 2; j++)
    {
      int xi = (x+i+_L)%_L;
      int yi = (y+j+_L)%_L;
      if (get_state(xi, yi))
      {
        return true;
      }
    }
  }
  return false;
}

/**
 * \brief    Check if the particle (x,y) should be removed
 * \details  --
 * \param    bool
 * \return   \e void
 */
bool DLA::toRemove( int x, int y )
{
  if (x < 0 || x >= _L || y < 0 || y >= _L)
  {
    return true;
  }
  return false;
}

