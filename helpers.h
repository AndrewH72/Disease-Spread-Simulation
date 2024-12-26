#include "singlyLinkedList.h"
#include "adjMatrixGraph.h"
#include "adjListGraph.h"
#include "disease.h"

void readData(ifstream&, ifstream&, AdjListGraph&);
void calculatePopulations(Disease, CityNode&);
void collectData(ofstream&, Disease, CityNode&, int);
