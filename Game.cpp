#include "Game.h"
#include <fstream>
#include <sstream>
#include <chrono>
#include <thread>
#include <cstring>

using namespace std;

Game::Game() {
    linkedList = new LinkedList();
    board = grid;
}


void Game::loadGridFile() {
    fstream txtFile;
    txtFile.open("matrix1.txt",ios::in|ios::out); // Load file path
    if(txtFile.is_open()){
        string line;
        int x=0;
        while(getline(txtFile,line)){
            stringstream data(line);
            string cell;     
            getline(data,cell);
            int y=0;
            for(int i=0; i<strlen(cell.c_str()); i++){
                if(cell[i]!=' '){
                    int c = cell[i] - 48;
                    board->insertState(x,y,c);
                    y++;
                }
            }
            x++;
        }
    }else{
        cout<<"   Error: Cannot open file 'matrix1.txt'"<<endl;
    }
    
}

void Game::addRule(int number) {
    int (* function)(int, int, int *, int);
    
    string rules[7] = {"Overpopulation","Loneliness","Revive","Eld","Historic neighborhood","Time jump","From developer"};
    char * name;
    name = const_cast<char *>((rules[number-1]).c_str());
    switch(number){
        case 1:
            function = &rulePopulation;
            linkedList->insertRule(function,name);
            break;
        case 2:
            function = &ruleLoneliness;
            linkedList->insertRule(function,name);
            break;
        case 3:
            function = &ruleRevive;
            linkedList->insertRule(function,name);
            break;
        case 4:
            function = &ruleEld;
            linkedList->insertRule(function,name);
            break;
        case 5:
            function = &ruleHistoric;
            linkedList->insertRule(function,name);
            break;
        case 6:
            function = &ruleTime;
            linkedList->insertRule(function,name);
            break;
        case 7:
            function = &ruleDev;
            linkedList->insertRule(function,name);
            break;
        default:
            break;
    }
}

string Game::showAddedRules() {
    Node *aux = linkedList->getFirst();
    string res;
    if(aux==nullptr){
        return "...";
    }
    else{
        while(aux!=nullptr){
            res +=aux->getName();
            if(aux->getNext()!=nullptr){
                res += ",";
            }
            aux = aux->getNext();
        }
        return res;
    } 
}

void Game::deleteRule() {
    system("clear");
    if(linkedList->getFirst()!=nullptr){
        int number;
        linkedList->showAddedRules();
        cout<<"   Insert the number of the rule you want to delete: ";
        cin>>number;
        linkedList->deleteRule(number);
    }else{
        cout<<"   There's no rules selected"<<endl;
    }
}

void Game::start(){
    if(linkedList->getFirst()!=nullptr){
        cout<<"   Enter the amount of periods: ";
        int period;
        cin>>period;
        system("clear");
        for(int x=0; x<period; x++){
            execute();
        }
    }
    else{
        cout<<"   There's no rules selected"<<endl;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

void Game::execute(){
    cout<<"\n   Period: "<<board->getPeriod()<<"\n\n";
    grid->printMatrix();
    for(int x=0; x<30; x++){
        for(int y=0; y<30; y++){
            Node *node = linkedList->getFirst();
            int cell = board->getCellState(x,y);
            int *neighbors = board->getNeighbors(x,y);
            while(node!=nullptr){
                cell = node->applyRule(x,y,&neighbors[0],cell);
                node = node->getNext();
            }
        }
    }
    board->addPeriod();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    system("clear");
}