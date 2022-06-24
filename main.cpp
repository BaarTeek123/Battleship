#include <iostream>
#include "GameManager.h"
#include "Board.h"
#include "Ship.h"
#include <cstdlib>
#include <windows.h>

int main() {
    srand(time(nullptr));
    GameManager gamer (10,10,10);
    gamer.setGameArena();
//    gamer.checkShips(gamer.opponentShips);
    for (int i=0;i<10;i++) {
        gamer.playerShooting();
        //gamer.setAreaNearHitShip(gamer.opponentShips,gamer.opponentBoard);
        std::cout<<"Computer's board: "<<std::endl;
        gamer.opponentBoard.drawArea(true);
        gamer.computerShooting();
        std::cout<<"Player's board: "<<std::endl;
////        gamer.setAreaNearHitShip(gamer.playerShips,gamer.playerBoard);
        gamer.playerBoard.drawArea(true);
    }

    Board B1(10,10);
//    B1.drawArea();
    return 0;
}
