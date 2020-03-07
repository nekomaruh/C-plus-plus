#ifndef WORKSHOP1_NODE_H
#define WORKSHOP1_NODE_H

class Node {
private:
    char name[20];
    int (*rule)(int, int, int *, int);
    Node *next;

public:
    Node(int (*rule)(int, int, int *, int), char name[20]);
    int applyRule(int x, int y, int neighbors[8], int state);
    char* getName();
    Node* getNext();
    void setNext(Node *node);
};


#endif //WORKSHOP1_NODE_H
