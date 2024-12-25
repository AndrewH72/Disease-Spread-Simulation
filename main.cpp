#include <iostream>
#include "singlyLinkedList.h"
#include "adjMatrixGraph.h"
#include "adjListGraph.h"
using namespace std;

int main(){
  AdjMatrixGraph testMatrix;
  AdjListGraph testList;
  SinglyLinkedList test;
  SinglyLinkedList testtest;
  CityNode test1 = CityNode("test1", 1, 1, 0, 0, nullptr);
  CityNode test2 = CityNode("test2", 1, 1, 0, 0, nullptr);
  CityNode test3 = CityNode("test3", 1, 1, 0, 0, nullptr);
  CityNode test4 = CityNode("test4", 1, 1, 0, 0, nullptr);
  
  CityNode test5 = CityNode("test5", 1, 1, 0, 0, nullptr);
  CityNode test6 = CityNode("test6", 1, 1, 0, 0, nullptr);
  CityNode test7 = CityNode("test7", 1, 1, 0, 0, nullptr);
  CityNode test8 = CityNode("test8", 1, 1, 0, 0, nullptr);

  test.append(test1);
  test.append(test2);
  test.append(test3);
  test.append(test4);

  testtest.append(test5);
  testtest.append(test6);
  testtest.append(test7);
  testtest.append(test8);

  testList.addVertex(0, test1);
  testList.addVertex(1, test2);
  testList.addEdge(0, 1, 10);
  cout << testList.isAdjacent(0, 1);
}
