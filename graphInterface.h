#ifndef GRAPHINTERFACE_H
#define GRAPHINTERFACE_H
#include "cityNode.h"

class IGraph{
  public:
    virtual bool isAdjacent(int, int) = 0;
    virtual CityNode** getNeighbors(int) = 0;
    virtual bool addVertex(int, const CityNode&) = 0;
    virtual bool removeVertex(int) = 0;
    virtual bool addEdge(int, int, int) = 0;
    virtual bool removeEdge(int, int) = 0;
    virtual ~IGraph(){}
};
#endif
