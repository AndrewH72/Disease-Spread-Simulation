#include "disease.h"

Disease::Disease(){
  infectionRate = 0.0;
  recoveryRate = 0.0;
}

Disease::Disease(float iR, float rR){
  infectionRate = iR;
  recoveryRate = rR;
}

Disease::Disease(const Disease& otherDisease){
  infectionRate = otherDisease.infectionRate;
  recoveryRate = otherDisease.recoveryRate;
}

float Disease::getInfectionRate(){
  return infectionRate;
}

float Disease::getRecoveryRate(){
  return recoveryRate;
}

void Disease::setInfectionRate(float iR){
  infectionRate = iR;
}

void Disease::setRecoveryRate(float rR){
  recoveryRate = rR;
}
