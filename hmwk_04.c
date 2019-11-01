// Le, Dustin E.
// dxl0689
// 2019-11-01
//----------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

#include "line.h"
#include "model.h"
#include "projection.h"
#include "view.h"

//----------------------------------------------------------
int main( int argc, char *argv[] )
{
  if ( argc != 3 ) {
    fprintf( stderr, "Usage: %s <modelFileName> <viewFileName>\n", argv[0] );
    exit( 1 );
  }

  //--------------------------------------
  // Load the model and view.
  Model *m = loadModel( argv[1] );
  dumpModel( m, 0 );

  View *v = loadView( argv[2] );
  dumpView( v );

  // Print the canvas side for the SDF file.
  printf( "c %4d %4d\n", v->m_width, v->m_height );

  // Rotate the vertices according to the Euler angles
  // specified in the view.
  rotateVertexList( v, m->m_vertex, m->m_numVertices, m->m_center );

  // Compute the projecion according to the parameters given
  // in the view.
  Projection *p = computeProjection( v );
  dumpProjection( p );

  // Project the rotated vertices according to the just-computed
  // projection.
  projectVertexList( p, m->m_vertex, m->m_numVertices );

  //--------------------------------------
  // Draw lines corresponding to the viewport region.
  Line line;

  line.p1X = v->m_portalXMin;
  line.p1Y = v->m_portalYMin;
  line.p2X = v->m_portalXMin;
  line.p2Y = v->m_portalYMax;
  dumpLine(&line);

  line.p1X = v->m_portalXMin;
  line.p1Y = v->m_portalYMax;
  line.p2X = v->m_portalXMax;
  line.p2Y = v->m_portalYMax;
  dumpLine(&line);

  line.p1X = v->m_portalXMax;
  line.p1Y = v->m_portalYMax;
  line.p2X = v->m_portalXMax;
  line.p2Y = v->m_portalYMin;
  dumpLine(&line);

  line.p1X = v->m_portalXMax;
  line.p1Y = v->m_portalYMin;
  line.p2X = v->m_portalXMin;
  line.p2Y = v->m_portalYMin;
  dumpLine(&line);

  //--------------------------------------
  // Check each line of each triangle.
  // Display it (in clipped form if necesssary).

  for ( int i=0; i<m->m_numFaces; i++ ) {

    Line line1, line2, line3;
    double v1pX = m->m_vertex[m->m_face[i].v1].x;
    double v1pY = m->m_vertex[m->m_face[i].v1].y;
    double v2pX = m->m_vertex[m->m_face[i].v2].x;
    double v2pY = m->m_vertex[m->m_face[i].v2].y;
    double v3pX = m->m_vertex[m->m_face[i].v3].x;
    double v3pY = m->m_vertex[m->m_face[i].v3].y;

    // Line 1: Vertex 1 to Vertex 2
    line1.p1X = v1pX;
    line1.p1Y = v1pY;
    line1.p2X = v2pX;
    line1.p2Y = v2pY;

    // Line 2: Vertex 2 to Vertex 3
    line2.p1X = v2pX;
    line2.p1Y = v2pY;
    line2.p2X = v3pX;
    line2.p2Y = v3pY;

    // Line 3: Vertex 3 to Vertex 1
    line3.p1X = v3pX;
    line3.p1Y = v3pY;
    line3.p2X = v1pX;
    line3.p2Y = v1pY;

    int test1 = clipLine(v, &line1);
    if (test1)
    {
      dumpLine(&line1);
    }

    int test2 = clipLine(v, &line2);
    if (test2)
    {
      dumpLine(&line2);
    }

    int test3 = clipLine(v, &line3);
    if (test3)
    {
      dumpLine(&line3);
    }
  }

  //--------------------------------------
  // All done!  Free up the allocated strucures.
  freeModel( m );
  freeView( v );
  freeProjection( p );
}

//----------------------------------------------------------

