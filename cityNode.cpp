#include "cityNode.h"
CityNode::CityNode(){
  cityName = "NA";
  totalPopulation = 0;
  susceptiblePopulation = 0;
  infectedPopulation = 0;
  recoveredPopulation = 0;
  distanceWeight = 0;
  nextCity = nullptr;
}

CityNode::CityNode(string cN, int tP, int iP, int dW, CityNode* nC){
  cityName = cN;
  totalPopulation = tP;
  susceptiblePopulation = tP - iP;
  infectedPopulation = iP;
  recoveredPopulation = 0;
  distanceWeight = dW;
  nextCity = nC;
}

CityNode::CityNode(const CityNode& otherCity){
  cityName = otherCity.cityName;
  totalPopulation = otherCity.totalPopulation;
  susceptiblePopulation = otherCity.susceptiblePopulation;
  infectedPopulation = otherCity.infectedPopulation;
  recoveredPopulation = otherCity.recoveredPopulation;
  distanceWeight = otherCity.distanceWeight;
  nextCity = otherCity.nextCity;
}

string CityNode::getCityName(){
  return cityName;
}

int CityNode::getTotalPopulation(){
  return totalPopulation;
}

int CityNode::getSusceptiblePopulation(){
  return susceptiblePopulation;
}

int CityNode::getInfectedPopulation(){
  return infectedPopulation;
}

int CityNode::getRecoveredPopulation(){
  return recoveredPopulation;
}

int CityNode::getDistanceWeight(){
  return distanceWeight;
}

CityNode* CityNode::getNextCity(){
  return nextCity;
}

void CityNode::setCityName(string cN){
  cityName = cN;
}

void CityNode::setTotalPopulation(int tP){
  totalPopulation = tP;
}

void CityNode::setSusceptiblePopulation(int sP){
  susceptiblePopulation = sP;
}

void CityNode::setInfectedPopulation(int iP){
  infectedPopulation = iP;
}

void CityNode::setRecoveredPopulation(int rP){
  recoveredPopulation = rP;
}

void CityNode::setDistanceWeight(int dW){
  distanceWeight = dW;
}

void CityNode::setNextCity(CityNode* nC){
  nextCity = nC;
}
