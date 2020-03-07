/*
 * Members: Pablo Arias / Johan Ordenes / Cecilia Rojas
 * Workshop nº1: Dynamic Conway's Game of Life
 */

#include <iostream>
#include "Game.h"

using namespace std;

/*
 * Prints a menu with options to choose
 * P1: Game class to get the rules
*/

void printMenu(Game game){
    cout<<"\n   --- Dynamic Conway's Game of Life ---\n\n";
    cout<<"   Add your rules:\n\n";
    cout<<"   1. Overpopulation\n";
    cout<<"   2. Loneliness\n";
    cout<<"   3. Revive\n";
    cout<<"   4. Eld\n";
    cout<<"   5. Historic neighborhood\n";
    cout<<"   6. Time jump\n";
    cout<<"   7. From developer\n";
    cout<<"\n     ";
    cout<<"   Rules: ["<<game.showAddedRules()<<"]\n";
    cout<<"\n              8. Delete Rules\n";
    cout<<"\n   9. Exit                        0.Start\n\n";
}

int main() {
    int option;
    bool exit = false;

    Game game;
    game.loadGridFile();

    while(!exit){
        system("clear");
        printMenu(game);
        cout<<"   Choose one of the options above: ";
        cin>>option;
        switch(option){
            case 0:
                game.start();
                break;
            case 1:
                game.addRule(option);
                break;
            case 2:
                game.addRule(option);
                break;
            case 3:
                game.addRule(option);
                break;
            case 4:
                game.addRule(option);
                break;
            case 5:
                game.addRule(option);
                break;
            case 6:
                game.addRule(option);
                break;
            case 7:
                game.addRule(option);
                break;
            case 8:
                game.deleteRule();
                break;
            case 9:
                exit = true;
                break;
            default:
                break;
        }
    }
    return 0;
}
