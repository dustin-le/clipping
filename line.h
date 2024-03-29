// Le, Dustin E.
// dxl0689
// 2019-11-01

#if !defined( __LINE_H__ )
#define __LINE_H__

//----------------------------------------------------------
#include "view.h"

//----------------------------------------------------------
typedef struct _Line {
  double p1X, p1Y;
  double p2X, p2Y;
} Line;

//----------------------------------------------------------
int  clipLine( View *view, Line *line );
void dumpLine( Line *line );

//----------------------------------------------------------
#endif

