#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H
#include "queueInterface.h"

template <class ItemType>
class ArrayQueue: public IQueue<ItemType>{
  private:
    static const int maxItems = 25;
    int numItems, frontItem;
    ItemType arrQueue[maxItems];
  public:
    ArrayQueue(){
      numItems = 0;
      frontItem = 0;
    }

    bool isEmpty(){
      return numItems == 0;
    }

    int getSize(){
      return numItems;
    }

    bool enqueue(ItemType newItem){
      bool canEnqueue = numItems < maxItems;
      if(canEnqueue){
        arrQueue[numItems] = newItem;
      }
      return canEnqueue;
    }

    bool dequeue(){
      bool canDequeue = isEmpty();
      if(canDequeue){
        frontItem++;
      }
    return canDequeue;
    }

    ItemType getFront(){
      return arrQueue[frontItem];
    }

    ItemType getBack(){
      return arrQueue[numItems];
    }
};
#endif
