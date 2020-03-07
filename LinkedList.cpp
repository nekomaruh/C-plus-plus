#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() {
    this->first = nullptr;
}

LinkedList::~LinkedList() {

}

Node* LinkedList::getFirst() {
    return this->first;
}

void LinkedList::insertRule(int (* rule)(int, int, int *, int), char *name) {
    Node *node = new Node(rule,name);
    if(this->first== nullptr){
        this->first = node;
    }
    else{
        Node *current = this->first;
        while(current->getNext()!=nullptr){
            if(strcmp(current->getName(),name)==0){
                delete node;
                return;
            }
            current = current->getNext();
        }
        if(strcmp(current->getName(),name)==0){
            delete node;
            return;
        }
        current->setNext(node);
    }
}

void LinkedList::deleteRule(int number) {
    Node *current = first;
    if(first== nullptr){
        return;
    }
    else{
        Node *prev = current;
        for(int x=1; x<number;x++){
            if(current->getNext()==nullptr){
                return;
            }
            prev = current;
            current = current->getNext();
        }
        if(current==first){
            first= first->getNext();
        }
        else{
            prev->setNext(current->getNext());
        }
        delete current; 
    }
}

void LinkedList::showAddedRules(){
    std::cout<<"\n   -- Rules Added --\n"<<std::endl;
    int count = 1;
    Node *node = first;
    while(node!=nullptr){
        std::cout<<"   "<<count<<". "<<node->getName()<<std::endl;
        count++;
        node = node->getNext();     
    }
    std::cout<<"\n";
}