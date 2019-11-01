// Le, Dustin E.
// dxl0689
// 2019-11-01
//----------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

#include "line.h"

//----------------------------------------------------------
#define INSIDE (0)
#define LEFT   (1)
#define RIGHT  (2)
#define BELOW  (4)
#define ABOVE  (8)

#define EPSILON (1e-13)

int _regionCode( double x, double y, View *v );

//----------------------------------------------------------
int clipLine( View *v, Line *l )
{
  int anOutCode, x, y, p1Out, p2Out;

  p1Out = _regionCode(l->p1X, l->p1Y, v);
  p2Out = _regionCode(l->p2X, l->p2Y, v);
  
  if (p1Out == INSIDE)
  {
    anOutCode = p2Out;
  }
  
  else
  {
    anOutCode = p1Out;
  }

  if (anOutCode & ABOVE)
  {
    x = l->p1X + (l->p2X - l->p1X) * (v->m_portalYMax - l->p1Y) / (l->p2Y - l->p1Y);
    y = v->m_portalYMax;
    if (anOutCode == p1Out)
    {
      l->p1X = x;
      l->p1Y = y;
    }
    else if (anOutCode == p2Out)
    {
      l->p2X = x;
      l->p2Y = y;
    }
  }

  else if (anOutCode & BELOW)
  {
    x = l->p1X + (l->p2X - l->p1X) * (v->m_portalYMin - l->p1Y) / (l->p2Y - l->p1Y);
    y = v->m_portalYMin;
    if (anOutCode == p1Out)
    {
      l->p1X = x;
      l->p1Y = y;
    }
    else if (anOutCode == p2Out)
    {
      l->p2X = x;
      l->p2Y = y;
    }
  }

  else if (anOutCode & RIGHT)
  {
    x = v->m_portalXMax;
    y = l->p1Y + (l->p2Y - l->p1Y) * (v->m_portalXMax - l->p1X) / (l->p2X - l->p1X);
    if (anOutCode == p1Out)
    {
      l->p1X = x;
      l->p1Y = y;
    }
    else if (anOutCode == p2Out)
    {
      l->p2X = x;
      l->p2Y = y;
    }
  }

  else if (anOutCode & LEFT)
  {
    x = v->m_portalXMin;
    y = l->p1Y + (l->p2Y - l->p1Y) * (v->m_portalXMin - l->p1X) / (l->p2X - l->p1X);
    if (anOutCode == p1Out)
    {
      l->p1X = x;
      l->p1Y = y;
    }
    else if (anOutCode == p2Out)
    {
      l->p2X = x;
      l->p2Y = y;
    }
  }

  p1Out = _regionCode(l->p1X, l->p1Y, v);
  p2Out = _regionCode(l->p2X, l->p2Y, v);

  if (p1Out == INSIDE && p2Out == INSIDE)
  {
    return 1;
  }

  else
  {
    return 0;
  }
}

//----------------------------------------------------------
void dumpLine( Line *l )
{
  printf( "l %8.1f %8.1f %8.1f %8.1f\n",
    l->p1X, l->p1Y, l->p2X, l->p2Y );
}

//----------------------------------------------------------
int _regionCode( double x, double y, View *v )
{
  int code = INSIDE;

  if ((v->m_portalXMin - x) > EPSILON)
  {
    code = code | LEFT;
  }
  else if ((x - v->m_portalXMax) > EPSILON)
  {
    code = code | RIGHT;
  }
  else if ((v->m_portalYMin - y) > EPSILON)
  {
    code = code | BELOW;
  }
  else if ((y - v->m_portalYMax) > EPSILON)
  {
    code = code | ABOVE;
  }

  return code;
}

//----------------------------------------------------------

