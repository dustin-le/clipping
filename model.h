// Le, Dustin E.
// dxl0689
// 2019-11-01

#if !defined( __MODEL_H__ )
#define __MODEL_H__

//----------------------------------------------------------
#include "vertex.h"

//----------------------------------------------------------
typedef struct _Face {
  int v1;
  int v2;
  int v3;
} Face;

//----------------------------------------------------------
typedef struct _Model {
  int     m_numVertices;
  Vertex  m_minimum;
  Vertex  m_maximum;
  Vertex  m_center;
  int     m_numFaces;
  Vertex *m_vertex;
  Face   *m_face;
} Model;

//----------------------------------------------------------
Model *allocModel( int numVertices, int numFaces );
void   dumpFace( Face *face );
void   dumpModel( Model *model, int doLists );
void   freeModel( Model *m );
Model *loadModel( char *fName );

//----------------------------------------------------------

#endif

