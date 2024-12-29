#include <iostream>
#include <fstream>
#include <map>
#include <cstdlib>
#include <ctime>
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

bool shouldInfect(float tR){
  int scaledRate = tR * 1000;
  int randomNumber = rand() % 1000;
  return randomNumber < scaledRate;
}

bool shouldRecovery(float rR){
  int scaledRate = rR * 100;
  int randomNumber = rand() % 100;
  return randomNumber < scaledRate;
}

void runSimulation(Disease disease, AdjListGraph& graph, int numIterations){
  srand(time(0));

  for(int i = 0; i < numIterations; i++){
    for(int j = 0; j < 5; j++){
      CityNode* currCity = graph.getCityNode(j);

      bool isInfected = shouldInfect(disease.getInfectionRate());
      if(isInfected && currCity.getSusceptiblePopulation() > 0){
        currCity->setInfectedPopulation(currCity->getInfectedPopulation() + 1);
        currCity->setSusceptiblePopulation(currCity->getSusceptiblePopulation() - 1);
      }

      if(currCity->getInfectedPopulation() > 0){
        CityNode** neighborsList = graph.getNeighbors(j);
        int numNeighbors = graph.getNumNeighbors(j);

        for(int k = 0; k < numNeighbors; k++){
          CityNode* neighboringCity = neighborsList[k];
          
          bool isCityInfected = shouldInfect(disease.getInfectionRate());
          if(isCityInfected && neighboringCity->getSusceptiblePopulation() > 0){
            neighboringCity->setInfectedPopulation(neighboringCity->getInfectedPopulation() + 1);
            neighboringCity->setSusceptiblePopulation(neighboringCity->getSusceptiblePopulation() - 1);
          }
        }
      }
      bool isRecovered = shouldRecover(disease.getRecoveryRate());
      if(isRecovered && currCity->getInfectedPopulation() > 0){
        currCity->setRecoveredPopulation(currCity->getRecoveredPopulation() + 1);
        currCity->setInfectedPopulation(currCity->getInfectedPopulation() - 1);
      }
    }
  }
}
