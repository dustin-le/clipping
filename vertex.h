// Le, Dustin E.
// dxl0689
// 2019-11-01

#if !defined( __VERTEX_H__ )
#define __VERTEX_H__

//----------------------------------------------------------
typedef struct _Vertex {
  double x;
  double y;
  double z;
} Vertex;

//----------------------------------------------------------
void dumpVertex( Vertex *vertex );
void dumpVertexList( Vertex *vertex, int numVertices );

//----------------------------------------------------------
#endif

