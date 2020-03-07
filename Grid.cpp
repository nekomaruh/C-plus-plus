#include "Grid.h"
#include <iostream>

Grid *grid = new Grid(30,30);
/*
 * Builds a grid where data (cells) will be located
 * P1: weight of the grid
 * P2: height of the grid
 */
Grid::Grid(int x, int y) {
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            matrix[i][j]=0;
        }
    }
    period = 0;
}

Grid::~Grid() {

}

/*
 * Returns the current state of a cell in grid
 * P1: Row where the cell is located
 * P2: Col where the cell is located
 */
int Grid::getCellState(int x, int y) {
    return matrix[x][y];
}

/*
 * Returns the neighborhood of a cell given by parameter
 * P1: Row where the cell is located
 * P2: Col where the cell is located
 */
int* Grid::getNeighbors(int x, int y) {
    int neigborsX[8] = {-1,  0,  1, -1, 1, -1, 0, 1};
    int neigborsY[8] = {-1, -1, -1,  0, 0,  1, 1, 1};
    static int neighbors[8];

    for(int i=0; i<8; i++){
        if(neigborsX[i]+x>30 || neigborsX[i]+x<0 || neigborsY[i]+x>30 || neigborsY[i]+y<0){
            neighbors[i] = 0;
        }
        else{
            neighbors[i] = matrix[neigborsX[i]+x][neigborsY[i]+y];
        }
    }
    return neighbors;
}

void Grid::insertState(int x, int y, int state){
    matrix[x][y] = state;
}

void Grid::addPeriod(){
    int state;
    for(int i=0; i<30; i++){
        for(int j=0; j<30; j++){
            state = getCellState(i,j);
            if(state>0){
                insertState(i,j,state+1);
            }
        }
    }
    period+=1;
}

void Grid::printMatrix(){
    for(int i=0; i<30; i++){
        std::cout<<"   ";
        for(int j=0; j<30; j++){
            if(matrix[i][j]>0){
                std::cout<<1<<" ";
            }
            else{
                std::cout<<0<<" ";
            }
        }
        std::cout<<"\n";
    }
}

int Grid::getPeriod(){
    return period;
}

void Grid::setStartingPeriod(int x){
    period = x;
    for(int i=0; i<30; i++){
        for(int j=0; j<30; j++){
            if(matrix[i][j]>0){
                matrix[i][j]=period;
            }
        }
    }
}