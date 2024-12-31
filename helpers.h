#include "singlyLinkedList.h"
#include "adjMatrixGraph.h"
#include "adjListGraph.h"
#include "disease.h"

void readData(ifstream&, ifstream&, AdjListGraph&);
bool shouldInfect(float);
bool shouldRecover(float);
void collectData(ofstream&, CityNode**, int);
void runSimulation(Disease, AdjListGraph&, int);
