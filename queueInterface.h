#ifndef QUEUEINTERFACE_H
#define QUEUEINTERFACE_H

template <class ItemType>
class IQueue{
  public:
    virtual bool isEmpty() = 0;
    virtual int getSize() = 0;
    virtual bool enqueue(ItemType) = 0;
    virtual bool dequeue() = 0;
    virtual ItemType getFront() = 0;
    virtual ItemType getBack() = 0;
};
#endif
