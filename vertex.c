// Le, Dustin E.
// dxl0689
// 2019-11-01
//----------------------------------------------------------
#include <stdio.h>

#include "vertex.h"

//----------------------------------------------------------
void dumpVertexList( Vertex *vertex, int numVertices )
{
  for ( int i=0; i<numVertices; i++ ) {
    printf( "  [%5d]  ", i );
    dumpVertex( &vertex[i] );
    putc( '\n', stdout );
  }
}
//----------------------------------------------------------
void dumpVertex( Vertex *vertex )
{
  printf( "%13.6f, %13.6f, %13.6f", vertex->x, vertex->y, vertex->z );
}

//----------------------------------------------------------

