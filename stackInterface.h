#ifndef STACKINTERFACE_H
#define STACKINTERFACE_H

template <class ItemType>
class IStack{
  public:
    virtual bool isEmpty() = 0;
    virtual int getSize() = 0;
    virtual bool push(ItemType) = 0;
    virtual bool pop() = 0;
    virtual ItemType getTop() = 0;
};
#endif
