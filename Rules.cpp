#include "Rules.h"
#include "Grid.h"
#include <iostream>

Grid *matrix = grid;

int rulePopulation(int x, int y, int neighbors[], int state){
    if(state>0){
        int count=0;
        for(int z=0; z<8;z++){
            if(neighbors[z]>=1){
                count+=1;
            }
        }
        if(count>=3){
            matrix->insertState(x,y,0);
            return 0;
        }
        else{
            return state;
        }
    }
    else{
        return 0;
    }
    
}


int ruleLoneliness(int x, int y, int neighbors[], int state){
    if(state>0){
        int count =0;
        for(int z=0; z<8; z++){
            if(neighbors[z]>=1){
                count++;
            }
        }
        if(count<=2){
            matrix->insertState(x,y,0);
            return 0;
        }
        else{
            return state;
        }
    }
    else{
        return 0;
    }
}

int ruleRevive(int x, int y, int neighbors[], int state){
    if(state==0){
        int count = 0;
        for(int z=0; z<8; z++){
            if(neighbors[z]>=1){
                count+=1;
            }
        }
        if(count==3){
            matrix->insertState(x,y,1);
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        return 0;
    }
}

int ruleEld(int x, int y, int neighbors[], int state){
    if(state>25){
        grid->insertState(x,y,0);
        return 0;
    }
    else{
        return state;
    }
}

int ruleHistoric(int x, int y, int neighbors[], int state){
    if(state>0){
        int count =0;
        for(int x=0; x<8; x++){
            if(neighbors[x]>10){
                count++;
            }
        }
        if(count>4){
            return state;
        }else{
            grid->insertState(x,y,0);
            return 0;
        }
        
    }else{
        return 0;
    }
}

int ruleTime(int x, int y, int neighbors[], int state){
    if(state>=10){
        int count =0;
        for(int x=0; x<8; x++){
            if(neighbors[x] <10 && neighbors[x]>1){
                count++;
            }
        }
        if(count>=3){
            grid->insertState(x,y,state+5);
            return state+5;
        }else{
            return state;
        }
    }else{
        return state;
    }
}

/*
 * Ressurrection armaggedon
 * Cells (with 3 neighbors) reborn with the nearest maximum period of their neighbors
 * Cells (with 2 neighbors) reborn with the nearest minimum period of their neighbors
 */
int ruleDev(int x, int y, int neighbors[], int state){
    if(state==0){
        int nearest =0;
        int nearestMin =0;
        int count =0;
        for(int z=0; z<8; z++){
            if(neighbors[z]>0){
                if(neighbors[z]>nearest){
                    nearest = neighbors[z];
                }
                if(neighbors[z]<nearestMin){
                    nearestMin = neighbors[z];
                }
                count++;
            }
        }
        if(count==3){
            grid->insertState(x,y,nearest);
            return nearest;   
        }
        else if(count==2){
            grid->insertState(x,y,nearestMin);
            return nearestMin;
        }
        else{
            return state;
        } 
    }
    else{
        if(state>10){
            grid->insertState(x,y,0);
            return 0;
        }else{
            return state;
        }
    }
}