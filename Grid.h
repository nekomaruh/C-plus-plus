#ifndef WORKSHOP1_GRID_H
#define WORKSHOP1_GRID_H

class Grid {
private:
    int matrix[30][30];
    int period;
public:
    Grid(int x, int y);
    ~Grid();
    int getCellState(int x, int y);
    int * getNeighbors(int x, int y);
    void insertState(int x, int y, int state);
    void addPeriod();
    void printMatrix();
    int getPeriod();
    void setStartingPeriod(int x);
};
extern Grid *grid;

#endif //WORKSHOP1_GRID_H