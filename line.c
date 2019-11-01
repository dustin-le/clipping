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
  // TODO: Clip the line l against the portal limits
  //       in the view using the Cohen-Sutherland
  //       method as described in class.
  //       If p1 or p2 of the line is updated, ensure
  //       that you change it in the Line structure.
  //       Return whether the line should be drawn
  //       at all (0 for no, 1 for yes).
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

