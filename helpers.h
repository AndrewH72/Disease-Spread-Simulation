#include "singlyLinkedList.h"
#include "adjMatrixGraph.h"
#include "adjListGraph.h"
#include "disease.h"

void readData(ifstream&, ifstream&, AdjListGraph&);
bool shouldInfect(float);
void runSimulation(Disease, AdjListGraph&, int);
