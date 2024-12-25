ifndef ADJLISTGRAPH_H
#define ADJLISTGRAPH_H
#include "graphInterface.h"

class AdjListGraph: public IGraph{
  private:
    static const int maxVertices = 5;
    int numVertices;
    CityNode* adjList[maxVertices];
  public:
    AdjListGraph();

    bool isAdjacent(int, int);
    void getNeighbors(int);
    bool addVertex(int, const CityNode&);
    bool removeVertex(int);
    bool addEdge(int, int, int);
    bool removeEdge(int, int);
};
#endif

