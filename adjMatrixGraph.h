#ifndef ADJMATRIXGRAPH_H
#define ADJMATRIXGRAPH_H
#include "graphInterface.h"
#include "arrayStack.h"
#include "arrayQueue.h"

class AdjMatrixGraph: public IGraph{
  private:
    static const int maxVertices = 5;
    int numVertices;
    int adjMatrix[][maxVertices];
  public:
    AdjMatrixGraph();
    
    bool isAdjacent(int, int);
    void getNeighbors(int);
    bool addVertex(int, const CityNode&);
    bool removeVertex(int);
    bool addEdge(int, int, int);
    bool removeEdge(int, int);

    void depthFirstTraversal(int, bool[]);
    void breadthFirstTraversal(int, bool[]);
};
#endif
