#include "Node.h"
#include <iostream>

Node::Node(int (*rule)(int, int, int *, int), char name[20]) {
    strcpy(this->name, name);
    this->rule = rule;
    this->next = nullptr;
}

int Node::applyRule(int x, int y, int *neighbors, int state) {
    return (*rule)(x,y,neighbors,state);
}

char* Node::getName() {
    return this->name;
}

Node* Node::getNext() {
    return this->next;
}

void Node::setNext(Node* node){
    this->next = node;
}