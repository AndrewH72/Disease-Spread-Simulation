#ifndef LIST_INTERFACE
#define LIST_INTERFACE
#include "cityNode.h"

class IList{
  public:
    virtual bool isEmpty() = 0;
    virtual int getLength() = 0;
    virtual bool insert(int, const CityNode&) = 0;
    virtual bool append(const CityNode&) = 0;
    virtual bool remove(int) = 0;
    virtual void clear() = 0;
    virtual CityNode* getEntry(int) const = 0;
    virtual CityNode* replace(int, CityNode&) = 0;
    virtual ~IList(){}
};
#endif
