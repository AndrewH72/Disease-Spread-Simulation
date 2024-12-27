#include "AdjMatrixGraph.h"
#include <iostream>
using namespace std;

AdjMatrixGraph::AdjMatrixGraph(){
  numVertices = 0;
  for(int i = 0; i < maxVertices; i++){
    for(int j = 0; j < maxVertices; j++){
      adjMatrix[i][j] = 0;
    }
  }
}

bool AdjMatrixGraph::isAdjacent(int vertex1, int vertex2){
  return adjMatrix[vertex1][vertex2] != 0;
}

void AdjMatrixGraph::getNeighbors(int vertex){
  for(int i = 0; i < numVertices; i++){
    if(adjMatrix[vertex][i] != 0){
      cout << i << " ";
    }
    cout << endl;
  }
}

bool AdjMatrixGraph::addVertex(int vertex, const CityNode& newVertex){
  bool canAdd = vertex >= 0 && vertex < maxVertices;
  if(canAdd){
    numVertices++;
  }
  return canAdd;
}

bool AdjMatrixGraph::removeVertex(int vertex){
  bool canRemove = vertex >= 0 && vertex <= maxVertices;
  if(canRemove){
    numVertices--;
  }
  return canRemove;
}

bool AdjMatrixGraph::addEdge(int vertex1, int vertex2, int weight){
  bool canAdd = vertex1 >= 0 && vertex1 <= maxVertices && vertex2 >= 0 && vertex2 <= maxVertices;
  if(canAdd){
    adjMatrix[vertex1][vertex2] = weight;
    adjMatrix[vertex2][vertex1] = weight;
  }
  return canAdd;
}

bool AdjMatrixGraph::removeEdge(int vertex1, int vertex2){
  bool canRemove = vertex1 >= 0 && vertex1 <= maxVertices && vertex2 >= 0 && vertex2 <= maxVertices;
  if(canRemove){
    adjMatrix[vertex1][vertex2] = 0;
    adjMatrix[vertex2][vertex1] = 0;
  }
  return canRemove;
}
void AdjMatrixGraph::depthFirstTraversal(int startingPosition, bool visited[]){
  ArrayStack<int> arrStack;
  visited[startingPosition] = true;

  arrStack.push(startingPosition);
  while(!arrStack.isEmpty()){
    int currentItem = arrStack.getTop();
    bool foundUnvisited = false;

    if(!visited[currentItem]){
      visited[currentItem] = true;
    }
    
    for(int i = numVertices - 1; i >= 0; i--){
      if(adjMatrix[currentItem][i] != 0 && !visited[i]){
        arrStack.push(i);
        foundUnvisited = true;
      }
    }
  }
}

void AdjMatrixGraph::breadthFirstTraversal(int startingPosition, bool visited[]){
  ArrayQueue<int> arrQueue;
  visited[startingPosition] = true;

  arrQueue.enqueue(startingPosition);
  while(!arrQueue.isEmpty()){
    int currentItem = arrQueue.getFront();
    bool foundUnvisited = false;

    if(!visited[currentItem]){
      visited[currentItem] = true;
    }
    
    for(int i = numVertices - 1; i >= 0; i--){
      if(adjMatrix[currentItem][i] != 0 && !visited[i]){
        arrQueue.enqueue(i);
        foundUnvisited = true;
      }
    }
  }
}
