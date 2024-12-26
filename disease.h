#ifndef DISEASE_H
#define DISEASE_H

class Disease{
  private:
    float infectionRate;
    float recoveryRate;
  public:
    Disease();
    Disease(float, float);
    Disease(const Disease&);

    float getInfectionRate();
    float getRecoveryRate();

    void setInfectionRate(float);
    void setRecoveryRate(float);
};
#endif
