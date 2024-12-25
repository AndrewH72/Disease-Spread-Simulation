#ifndef CITY_NODE
#define CITY_NODE
#include <string>
using namespace std;

class CityNode{
  private:
    string cityName;
    int totalPopulation, susceptiblePopulation, infectedPopulation, recoveredPopulation, distanceWeight;
    CityNode* nextCity;
  public:
    CityNode();
    CityNode(string, int, int, int, int, CityNode*);
    CityNode(const CityNode&);

    string getCityName();
    int getTotalPopulation();
    int getSusceptiblePopulation();
    int getInfectedPopulation();
    int getRecoveredPopulation();
    int getDistanceWeight();
    CityNode* getNextCity();

    void setCityName(string);
    void setTotalPopulation(int);
    void setSusceptiblePopulation(int);
    void setInfectedPopulation(int);
    void setRecoveredPopulation(int);
    void setDistanceWeight(int);
    void setNextCity(CityNode*);
};

#endif
