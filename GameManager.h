//
// Created by user on 24.06.2022.
//

#ifndef BATTLESHIP_GAMEMANAGER_H
#define BATTLESHIP_GAMEMANAGER_H


#include <cstdlib>
#include<ctime>
#include <array>
#include "Board.h"
#include "Ship.h"

class GameManager {
public:
    Board playerBoard{10, 10};
    Board opponentBoard{10,10};
    short amountOfShips{0};
    std::vector<Ship*>playerShips{10};
    std::vector<Ship*>opponentShips{10};
    bool gameOver{false};
    GameManager (const int&, const int&, const int&);
    void setShipCoordinates(Ship&, const Board&);
    bool attack(const int&,const int&,Board&);
    void setShipHorizontal(const Ship&, Board&);
    void setShipVertical(const Ship&, Board&);
    bool checkShip(const Ship&,const Board&);
    void setGameArena() ;
    Ship setRandomShip(const int&, Board&);
    void setComputerShip(const int&);
    void setPlayerShip(const int&);
    void getCoordinates(Ship&,const int&);
    void setShip( Ship&,Board&);
    void computerShooting();
    void Game();
    void playerShooting();
    bool checkShips(std::vector<Ship*>);
    void setAreaNearHitShip(std::vector<Ship*>ships, Board& board);
};






#endif //BATTLESHIP_GAMEMANAGER_H
