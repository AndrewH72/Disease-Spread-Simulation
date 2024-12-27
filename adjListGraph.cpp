#include "adjListGraph.h"
#include <iostream>
#include <string>
using namespace std;

AdjListGraph::AdjListGraph(){
  numVertices = 0;
  for(int i = 0; i < maxVertices; i++){
    adjList[i] = nullptr;
  }
}

bool AdjListGraph::isAdjacent(int vertex1, int vertex2){
  CityNode* city1 = adjList[vertex1];
  CityNode* city2 = adjList[vertex2];

  return city1->getDistanceWeight() != 0 && city2->getDistanceWeight() != 0;
}



void AdjListGraph::getNeighbors(int vertex){
  CityNode* currCity = adjList[vertex];
  while(currCity != nullptr){
    cout << currCity->getCityName() << " ";
  }
  cout << endl;
}

bool AdjListGraph::addVertex(int vertex, const CityNode& newVertex){
  bool canAdd = vertex >= 0 && vertex < maxVertices;
  CityNode* vertexToAdd = new CityNode(newVertex);
  if(canAdd){
    adjList[vertex] = vertexToAdd;
    numVertices++;
  }
  return canAdd;
}

bool AdjListGraph::removeVertex(int vertex){
  bool canRemove = vertex >= 0 && vertex <= maxVertices;
  if(canRemove){
    numVertices--;
  }
  return canRemove;
}

bool AdjListGraph::addEdge(int vertex1, int vertex2, int weight){
  bool canAdd = vertex1 >= 0 && vertex1 <= maxVertices && vertex2 >= 0 && vertex2 <= maxVertices;
  CityNode* city1 = adjList[vertex1];
  CityNode* city2 = adjList[vertex2];
  if(canAdd){
    city1->setDistanceWeight(weight);
    city2->setDistanceWeight(weight);
  }
  return canAdd;
}

bool AdjListGraph::removeEdge(int vertex1, int vertex2){
  bool canRemove = vertex1 >= 0 && vertex1 <= maxVertices && vertex2 >= 0 && vertex2 <= maxVertices;
  CityNode* city1 = adjList[vertex1];
  CityNode* city2 = adjList[vertex2];
  if(canRemove){
    city1->setDistanceWeight(0);
    city2->setDistanceWeight(0);
  }
  return canRemove;
}

void AdjListGraph::depthFirstTraversal(int startingPosition, bool visited[]){
  int i = 0;
  CityNode* currCity = adjList[startingPosition];
  ArrayStack<CityNode*> arrStack;
  CityNode* neighborList[numVertices];
  visited[startingPosition] = true;

  arrStack.push(currCity);
  while(!arrStack.isEmpty()){
    CityNode* currentItem = arrStack.getTop();
    bool foundUnvisited = false;

    while(currCity != nullptr){
      neighborList[i] = currCity;
      currCity = currCity->getNextCity();
      i++;
    }

    for(int i = 0; i < numVertices; i++){
      if(!visited[i]){
        arrStack.push(neighborList[i]);
        visited[i] = true;
      }
    }
  }
}
void AdjListGraph::breadthFirstTraversal(int startingPosition, bool visited[]){
  int i = 0;
  CityNode* currCity = adjList[startingPosition];
  ArrayQueue<CityNode*> arrQueue;
  CityNode* neighborList[numVertices];
  visited[startingPosition] = true;

  arrQueue.enqueue(currCity);
  while(!arrQueue.isEmpty()){
    CityNode* currentItem = arrQueue.getFront();
    bool foundUnvisited = false;

    
    while(currCity != nullptr){
      neighborList[i] = currCity;
      currCity = currCity->getNextCity();
      i++;
    }

    for(int i = 0; i < numVertices; i++){
      if(!visited[i]){
        arrQueue.enqueue(neighborList[i]);
        visited[i] = true;
      }
    }
  }
}
