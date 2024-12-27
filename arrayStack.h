#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H
#include "stackInterface.h"

template <class ItemType>
class ArrayStack: public IStack<ItemType>{
  private:
    static const int maxItems = 25;
    int numItems;
    int topItem;
    ItemType arrStack[maxItems] ;
  public:
    ArrayStack(){
      numItems = 0;
      topItem = 0;
    }

    bool isEmpty(){
      return numItems == 0;
    }

    int getSize(){
      return numItems;
    }

    bool push(ItemType newItem){
      bool canPush = numItems< maxItems;
      if(canPush){
        arrStack[numItems] = newItem;
      }
      return canPush;
    }

    bool pop(){
      bool canPop = isEmpty();
      if(canPop){
        numItems--;
      }
      return canPop;
    }

    ItemType getTop(){
      return arrStack[0];
    }

};
#endif
