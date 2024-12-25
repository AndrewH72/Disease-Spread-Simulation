#include "singlyLinkedList.h"
SinglyLinkedList::SinglyLinkedList(){
  headCity = nullptr;
  itemCount = 0;
}

SinglyLinkedList::SinglyLinkedList(const SinglyLinkedList& otherList){
  itemCount = otherList.itemCount;
  if(otherList.headCity == nullptr){
    return;
  }
  CityNode* temp = otherList.headCity;
  headCity = new CityNode;

  headCity->setCityName(temp->getCityName()); 
  headCity->setTotalPopulation(temp->getTotalPopulation()); 
  headCity->setSusceptiblePopulation(temp->getSusceptiblePopulation()); 
  headCity->setInfectedPopulation(temp->getInfectedPopulation()); 
  headCity->setRecoveredPopulation(temp->getRecoveredPopulation()); 
  headCity->setNextCity(nullptr);
  temp = temp->getNextCity();
  
  while(temp != nullptr){
    headCity->setNextCity(temp);
    temp = temp->getNextCity();
  }
}

CityNode* SinglyLinkedList::getNodeAt(int position) const{
  if(position >= 1 && position <= itemCount){
    CityNode* curCity = headCity;
    for(int i = 1; i < position; i++){
      curCity = curCity->getNextCity();
    }
    return curCity;
  }
  return nullptr;
}

bool SinglyLinkedList::isEmpty(){
  return itemCount == 0;
}

int SinglyLinkedList::getLength(){
  return itemCount;
}

bool SinglyLinkedList::insert(int newPosition, const CityNode& newCity){
  bool canInsert = newPosition >= 1 && newPosition <= itemCount + 1;
  if(canInsert){
    CityNode* cityToInsert = new CityNode(newCity);
    if(newPosition == 1){
      cityToInsert->setNextCity(headCity);
      headCity = cityToInsert;
    }
    else{
      CityNode* prevCity = getNodeAt(newPosition - 1);
      cityToInsert->setNextCity(prevCity->getNextCity());
      prevCity->setNextCity(cityToInsert);
    }
  itemCount++;
  }
  return canInsert;
}

bool SinglyLinkedList::append(const CityNode& newCity){
  CityNode* cityToAppend = new CityNode(newCity);
  if(itemCount == 0){
    headCity = cityToAppend;
  }
  else{
    CityNode* currCity = getNodeAt(itemCount);
    currCity->setNextCity(cityToAppend);
  }
  itemCount++;
  return true;
}

bool SinglyLinkedList::remove(int position){
  bool canRemove = position >= 1 && position <= itemCount;
  if(canRemove){
    CityNode* cityToRemove = nullptr;
    if(position == 1){
      cityToRemove = headCity;
      headCity = headCity->getNextCity();
    }
    else{
      CityNode* prevCity = getNodeAt(position - 1);
      cityToRemove = prevCity->getNextCity();
      prevCity->setNextCity(cityToRemove->getNextCity());
    }
    cityToRemove->setNextCity(nullptr);
    delete cityToRemove;
    cityToRemove = nullptr;
    itemCount--;
  }
  return canRemove;
}

void SinglyLinkedList::clear(){
  CityNode* curCity = headCity;
  CityNode* cityToRemove = nullptr;
  while(curCity != nullptr){
    cityToRemove = curCity;
    curCity = curCity->getNextCity();
    delete cityToRemove;
  }
  headCity = nullptr;
  itemCount = 0;
}

CityNode* SinglyLinkedList::getEntry(int position) const{
  bool canGet = position >= 1 && position <= itemCount;
  if(canGet){
    CityNode* curCity = getNodeAt(position);
    return curCity;
  }
  return nullptr;
}

CityNode* SinglyLinkedList::replace(int position, CityNode& newCity){
  bool canReplace = position >= 1 && position <= itemCount;
  CityNode* oldCity = nullptr;
  if(canReplace){
    CityNode* cityToReplace = getNodeAt(position);

    cityToReplace->setCityName(newCity.getCityName());
    cityToReplace->setTotalPopulation(newCity.getTotalPopulation());
    cityToReplace->setSusceptiblePopulation(newCity.getSusceptiblePopulation());
    cityToReplace->setInfectedPopulation(newCity.getInfectedPopulation());
    cityToReplace->setRecoveredPopulation(newCity.getRecoveredPopulation());
    cityToReplace->setNextCity(newCity.getNextCity());

    oldCity = cityToReplace;
    return oldCity;
  }
  return nullptr;
}

SinglyLinkedList::~SinglyLinkedList(){
  clear();
}
