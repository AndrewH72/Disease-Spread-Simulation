#include <iostream>
#include <fstream>
#include <map>
#include "helpers.h"
using namespace std;

void readData(ifstream& pFile, ifstream& dFile, AdjListGraph& graph){
  char junkChar;
  string cityName, cityName2;
  int cityPopulation, distanceWeight, infectedPopulation, vertexIndex = 0;;
  map<string, int> nameConversion = {
    {"Reno", 0},
    {"Salt Lake City", 1},
    {"Las Vegas", 2},
    {"San Francisco", 3},
    {"Seattle", 4},
  };
 
  while(!pFile.eof()){
    getline(pFile, cityName, ',')  >> cityPopulation >> junkChar >> infectedPopulation >> junkChar >> distanceWeight;
    CityNode cityToInsert = CityNode(cityName, cityPopulation, infectedPopulation, distanceWeight, nullptr);

    graph.addVertex(vertexIndex, cityToInsert);
    vertexIndex++;
  }

  while(!dFile.eof()){
    getline(dFile, cityName, ',');
    getline(dFile, cityName2, ',') >> distanceWeight;
    graph.addEdge(nameConversion[cityName], nameConversion[cityName2], distanceWeight);
  }
}
void calculatePopulations(Disease disease, CityNode& city){
  float infectionRate = disease.getInfectionRate();
  float recoveryRate = disease.getRecoveryRate();

  float susceptibleRate = -(infectionRate  * city.getInfectedPopulation() * city.getSusceptiblePopulation()) / city.getTotalPopulation();
  float infectedRate = (infectionRate  * city.getInfectedPopulation() * city.getSusceptiblePopulation()) / city.getTotalPopulation() - (recoveryRate * city.getInfectedPopulation());
  float recoveredRate = recoveryRate * city.getInfectedPopulation() ;
  
  city.setSusceptiblePopulation(city.getSusceptiblePopulation() + susceptibleRate);
  city.setInfectedPopulation(city.getInfectedPopulation() + infectedRate);
  city.setRecoveredPopulation(city.getRecoveredPopulation() + recoveredRate);
}

void collectData(ofstream& outputFile, Disease disease, CityNode& city, int maxIterations){
  for(int i = 0; i < maxIterations; i++){
    outputFile << city.getSusceptiblePopulation() << ", " << city.getInfectedPopulation() << ", " << city.getRecoveredPopulation() << endl;
    calculatePopulations(disease, city);
  }
}
