#ifndef WORKSHOP1_LINKEDLIST_H
#define WORKSHOP1_LINKEDLIST_H

#include "Node.h"

class LinkedList {
private:
    Node *first;
public:
    LinkedList();
    ~LinkedList();
    Node* getFirst();
    void insertRule(int (*rule)(int, int, int [], int), char name[20]);
    void deleteRule(int number);
    void showAddedRules();
};


#endif //WORKSHOP1_LINKEDLIST_H