#include <iostream>
#include <fstream>
#include "helpers.h"
using namespace std;

int main(){
  ofstream dataFile ("dataFile.txt");
  ifstream cityFile ("cityData.txt");
  ifstream distFile ("distanceFile.txt");
  AdjListGraph cityGraph;
  Disease Covid19 = Disease(0.89, 0.982);
  CityNode testCity = CityNode("Test", 100, 20, 0, nullptr);

  readData(cityFile, distFile, cityGraph);
  collectData(dataFile, Covid19, testCity, 100);

  return 0;
}
