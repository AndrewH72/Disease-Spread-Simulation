#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H
#include "listInterface.h"

class SinglyLinkedList: public IList{
  private:
    CityNode* headCity;
    int itemCount;
    CityNode* getNodeAt(int) const;
  public:
    SinglyLinkedList();
    SinglyLinkedList(CityNode*, int);
    SinglyLinkedList(const SinglyLinkedList&);

    bool isEmpty();
    int getLength();
    bool insert(int, const CityNode&);
    bool append(const CityNode&);
    bool remove(int);
    void clear();
    CityNode* getEntry(int) const;
    CityNode* replace(int, CityNode&);
    ~SinglyLinkedList();
};
#endif
