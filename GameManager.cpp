#include <synchapi.h>
#include "GameManager.h"


GameManager::GameManager (const int& width, const int&height , const int& amountOfShips): playerBoard(width, height), opponentBoard(width, height){
    gameOver=false;
    this->amountOfShips=amountOfShips;
    opponentShips.resize(amountOfShips);
    playerShips.resize(amountOfShips);
}

//koordynaty od gracza
void  GameManager::getCoordinates(Ship&ship, const int& length){
    short xPlayerChoice=1;
    short yPlayerChoice=1;
    short planePlayerChoice=true;
    std::cout<<" Ship length: "<<length<<std::endl;//[min=1,max=4,default=1]: ";
    std::cout<<"Starting point: ";
    std::cout<<"\n X: ";
    std::cin>>xPlayerChoice;
    if ((xPlayerChoice>playerBoard.getWidth())||(xPlayerChoice<1)){
        xPlayerChoice=1;
    }
    std::cout<<"Y: ";
    std::cin>>yPlayerChoice;
    if ((yPlayerChoice>playerBoard.getHeight())||(yPlayerChoice<1)){
        yPlayerChoice=1;
    }
    std::cout<<"Plane [0-horizontal,1- vertical]: ";
    std::cin>>planePlayerChoice;
    if (planePlayerChoice!=0) {
        planePlayerChoice=1;
    }
    ship.setProperties(length,xPlayerChoice,yPlayerChoice,planePlayerChoice);
}

void GameManager:: setPlayerShip(const int&length) {
    Ship ship(1, 1, 1, true);
    int counter=0;
    do {
        if (counter>0)
            std::cout<<"Error! Wrong coordinates! Try again: "<<std::endl;
        getCoordinates(ship,length);
        setShipCoordinates(ship,playerBoard);
        counter++;
    }
    while (!checkShip(ship, playerBoard));
    setShip(ship,playerBoard);
    playerShips.push_back(&ship)
            ;
}


//ustawienie statku na planszy
void GameManager:: setShipCoordinates (Ship& ship, const Board&board) {
    if ((ship.getLength()<1)||(ship.getLength()>4))
        ship.setLength(1);
    if((ship.getXCoordinates()[0]<1)||(ship.getXCoordinates()[0] > board.getWidth()))
        ship.getXCoordinates()[0]=1;
    if((ship.getYCoordinates()[0]<1)||(ship.getYCoordinates()[0] > board.getHeight()))
        ship.getYCoordinates()[0]=1;
    if((ship.getPlane()==1)&&(ship.getYCoordinates()[0]+ship.getLength() > board.getHeight()))
        ship.setYCoordinate(0, board.getHeight() - ship.getLength()+1);
    if((ship.getPlane()==0)&&(ship.getXCoordinates()[0]+ship.getLength() > board.getWidth())){
        ship.setXCoordinate(0, board.getWidth() - ship.getLength() + 1);
    }
    ship.setProperties(ship.getLength(),ship.getXCoordinates()[0],ship.getYCoordinates()[0],ship.getPlane());
}



void GameManager:: setShip(Ship&ship,Board& board){
    if (ship.getPlane()){
        setShipVertical(ship,board);
    }
    else setShipHorizontal(ship, board);
}

void GameManager::setComputerShip(const int& length) {
    Ship ship=setRandomShip(length,opponentBoard);
    std::cout<<ship.isFinished();
    setShip(ship,opponentBoard);
    opponentShips.push_back(&ship);
}

//ustalenie obu plansz do gry (dla gracza i komputera)
void GameManager:: setGameArena () {
    for (int i=4;i>0;i--){
        if (i==4) {
            for (int k=0;k<amountOfShips/10;k++){
                setComputerShip(i);
//                setPlayerShip(i);
                std::cout<<std::endl;
                playerBoard.drawArea(true);
            }
        }
        if (i==3){
            for (int k=0;k<amountOfShips/5;k++){
                setComputerShip(i);
//                setPlayerShip(i);
                std::cout<<std::endl;
                playerBoard.drawArea(true);
            }
        }
        if (i==2){
            for (int j=0;j<amountOfShips*3/10;j++){
                setComputerShip(i);
//                setPlayerShip(i);
                std::cout<<std::endl;
                playerBoard.drawArea(true);
            }
        }
        if(i==1) {
            for (int j=0;j<amountOfShips*2/5;j++) {
                setComputerShip(i);
//                setPlayerShip(i);
                std::cout<<std::endl;
                playerBoard.drawArea(true);
            }
        }

    }

    for (int i = 1;i<=this->playerBoard.getHeight();i++){
        for (int j=1;j<=this->playerBoard.getWidth();j++){
            if (this->playerBoard.getField(i,j)!=1){
                playerBoard.setField(i,j,0);
            }
            if (this->opponentBoard.getField(i,j)!=1)
                opponentBoard.setField(i,j,0);
        }
    }
    Sleep(2000);
//    system("cls");
    std::cout << "Player: " << std::endl;
    std::cout << "Ships: " << amountOfShips << std::endl;
    this->playerBoard.drawArea(true);
    std::cout << "\nComputer: " << std::endl;
    std::cout << "Ships: " << amountOfShips << std::endl;
    this->opponentBoard.drawArea(true);
}

Ship GameManager::setRandomShip(const int& shipLength,Board& board){
    Ship ship(shipLength,1,1,true);
    int randomXCoordinate=1;
    int randomYCoordinate=1;
    int randomPlane=1;
    do{
        randomXCoordinate=rand() % board.getWidth()+1;
        randomYCoordinate=rand() % board.getHeight()+1;
        randomPlane=rand()%2;
        ship.setProperties(shipLength,randomXCoordinate,randomYCoordinate,randomPlane);
        setShipCoordinates(ship,board);
    }
    while(!checkShip(ship,board));
    return ship;
}

bool GameManager::checkShip(const Ship&ship, const Board&board) {
    for (int i=0;i<ship.getYCoordinates().size();i++){
        for (int j=0;j<ship.getXCoordinates().size();j++){
            if (board.getField(ship.getXCoordinates()[i],ship.getYCoordinates()[j])!=0){
                return false;
            }
        }
    }
    return true;
}

void GameManager::setShipHorizontal(const Ship &ship, Board&board) {
    for (int i = 0; i < ship.getLength(); i++) {
        board.setField(ship.getXCoordinates()[i], ship.getYCoordinates()[0], 1);
        if (ship.getYCoordinates()[0] == 1) {
            board.setField(ship.getXCoordinates()[i], ship.getYCoordinates()[0] + 1, 2);
            if (ship.getXCoordinates()[0] == 1) {
                board.setField(ship.getXCoordinates()[ship.getLength() - 1] + 1, ship.getYCoordinates()[0], 2);
                board.setField(ship.getXCoordinates()[ship.getLength() - 1] + 1, ship.getYCoordinates()[i] + 1, 2);
            }
            else if (ship.getXCoordinates()[ship.getLength() - 1] == 10) {
                board.setField(ship.getXCoordinates()[0] - 1, ship.getYCoordinates()[0] + 1, 2);
                board.setField(ship.getXCoordinates()[0] - 1, ship.getYCoordinates()[0], 2);
            } else
            {
                board.setField(ship.getXCoordinates()[ship.getLength() - 1] + 1, ship.getYCoordinates()[0] + 1, 2);
                board.setField(ship.getXCoordinates()[0] - 1, ship.getYCoordinates()[0] + 1, 2);
                board.setField(ship.getXCoordinates()[ship.getLength() - 1] + 1, ship.getYCoordinates()[0], 2);
                board.setField(ship.getXCoordinates()[0] - 1, ship.getYCoordinates()[0]  , 2);
            }
        }
        else if (ship.getYCoordinates()[0] == 10) {
            board.setField(ship.getXCoordinates()[i] , ship.getYCoordinates()[0] - 1, 2);
            if (ship.getXCoordinates()[0] == 1) {
                board.setField(ship.getXCoordinates()[ship.getLength() - 1] + 1, ship.getYCoordinates()[0], 2);
                board.setField(ship.getXCoordinates()[ship.getLength() - 1] + 1, ship.getYCoordinates()[0] - 1 , 2);
            } else if (ship.getXCoordinates()[ship.getLength() - 1] == 10) {
                board.setField(ship.getXCoordinates()[0] - 1, ship.getYCoordinates()[0] - 1, 2);
                board.setField(ship.getXCoordinates()[0] - 1, ship.getYCoordinates()[0], 2);
            } else {
                board.setField(ship.getXCoordinates()[ship.getLength() - 1] + 1, ship.getYCoordinates()[0] - 1, 2);
                board.setField(ship.getXCoordinates()[ship.getLength() - 1] + 1, ship.getYCoordinates()[0], 2);
                board.setField(ship.getXCoordinates()[0] - 1, ship.getYCoordinates()[0] - 1 , 2);
                board.setField(ship.getXCoordinates()[0] - 1, ship.getYCoordinates()[0], 2);
            }
        }
        else {
            board.setField(ship.getXCoordinates()[i], ship.getYCoordinates()[0] + 1, 2);
            board.setField(ship.getXCoordinates()[i] , ship.getYCoordinates()[0] - 1, 2);
            if (ship.getXCoordinates()[0] == 1) {
                board.setField(ship.getXCoordinates()[ship.getLength() - 1] + 1, ship.getYCoordinates()[0] + 1, 2);
                board.setField(ship.getXCoordinates()[ship.getLength() - 1] + 1, ship.getYCoordinates()[0] - 1, 2);
                board.setField(ship.getXCoordinates()[ship.getLength() - 1] + 1, ship.getYCoordinates()[0], 2);

            } else if (ship.getXCoordinates()[ship.getLength() - 1] == 10) {
                board.setField(ship.getXCoordinates()[0] - 1, ship.getYCoordinates()[0] + 1, 2);
                board.setField(ship.getXCoordinates()[0] - 1, ship.getYCoordinates()[0] - 1, 2);
                board.setField(ship.getXCoordinates()[0] - 1, ship.getYCoordinates()[0], 2);

            } else {
                board.setField(ship.getXCoordinates()[0] - 1, ship.getYCoordinates()[0] - 1, 2);
                board.setField(ship.getXCoordinates()[0] - 1, ship.getYCoordinates()[0] + 1, 2);
                board.setField(ship.getXCoordinates()[0] - 1, ship.getYCoordinates()[0], 2);
                board.setField(ship.getXCoordinates()[ship.getLength() - 1] + 1, ship.getYCoordinates()[0] - 1, 2);
                board.setField(ship.getXCoordinates()[ship.getLength() - 1] + 1, ship.getYCoordinates()[0] + 1, 2);
                board.setField(ship.getXCoordinates()[ship.getLength() - 1] + 1, ship.getYCoordinates()[0], 2);
            }
        }
    }
}

void GameManager::setShipVertical(const Ship &ship, Board& board) {
    for (int i = 0; i < ship.getLength(); i++) {
        board.setField(ship.getXCoordinates()[0], ship.getYCoordinates()[i], 1);

        if (ship.getXCoordinates()[0] == 1) {
            board.setField(ship.getXCoordinates()[0] + 1, ship.getYCoordinates()[i], 2);
            if (ship.getYCoordinates()[0] == 1) {
                board.setField(ship.getXCoordinates()[0], ship.getYCoordinates()[i] + 1, 2);
                board.setField(ship.getXCoordinates()[0] + 1, ship.getYCoordinates()[i] + 1, 2);
            } else if (ship.getYCoordinates()[ship.getLength() - 1] == 10) {
                board.setField(ship.getXCoordinates()[0], ship.getYCoordinates()[0] - 1, 2);
                board.setField(ship.getXCoordinates()[0] + 1, ship.getYCoordinates()[0] - 1, 2);
            } else {
                board.setField(ship.getXCoordinates()[0], ship.getYCoordinates()[0] - 1, 2);
                board.setField(ship.getXCoordinates()[0], ship.getYCoordinates()[ship.getLength() - 1] + 1, 2);
                board.setField(ship.getXCoordinates()[0] + 1, ship.getYCoordinates()[ship.getLength() - 1] + 1,
                               2);
                board.setField(ship.getXCoordinates()[0] + 1, ship.getYCoordinates()[0] - 1, 2);

            }
        } else if (ship.getXCoordinates()[0] == 10) {
            board.setField(ship.getXCoordinates()[0] - 1, ship.getYCoordinates()[i], 2);
            if (ship.getYCoordinates()[0] == 1) {
                board.setField(ship.getXCoordinates()[0], ship.getYCoordinates()[i] + 1, 2);
                board.setField(ship.getXCoordinates()[0] - 1, ship.getYCoordinates()[i] + 1, 2);
            } else if (ship.getYCoordinates()[ship.getLength() - 1] == 10) {
                board.setField(ship.getXCoordinates()[0], ship.getYCoordinates()[0] - 1, 2);
                board.setField(ship.getXCoordinates()[0] - 1, ship.getYCoordinates()[0] - 1, 2);
            } else {
                board.setField(ship.getXCoordinates()[0], ship.getYCoordinates()[0] - 1, 2);
                board.setField(ship.getXCoordinates()[0], ship.getYCoordinates()[ship.getLength() - 1] + 1, 2);
                board.setField(ship.getXCoordinates()[0] - 1, ship.getYCoordinates()[ship.getLength() - 1] + 1,
                               2);
                board.setField(ship.getXCoordinates()[0] - 1, ship.getYCoordinates()[0] - 1, 2);
            }
        }
        else {
            board.setField(ship.getXCoordinates()[0] - 1, ship.getYCoordinates()[i], 2);
            board.setField(ship.getXCoordinates()[0] + 1, ship.getYCoordinates()[i], 2);
            if (ship.getYCoordinates()[0] == 1) {
                board.setField(ship.getXCoordinates()[0], ship.getYCoordinates()[i] + 1, 2);
                board.setField(ship.getXCoordinates()[0] - 1, ship.getYCoordinates()[i] + 1, 2);
                board.setField(ship.getXCoordinates()[0] + 1, ship.getYCoordinates()[i] + 1, 2);

            } else if (ship.getYCoordinates()[ship.getLength() - 1] == 10) {
                board.setField(ship.getXCoordinates()[0], ship.getYCoordinates()[0] - 1, 2);
                board.setField(ship.getXCoordinates()[0] - 1, ship.getYCoordinates()[0] - 1, 2);
                board.setField(ship.getXCoordinates()[0] + 1, ship.getYCoordinates()[0] - 1, 2);

            } else {
                board.setField(ship.getXCoordinates()[0], ship.getYCoordinates()[0] - 1, 2);
                board.setField(ship.getXCoordinates()[0], ship.getYCoordinates()[ship.getLength() - 1] + 1, 2);
                board.setField(ship.getXCoordinates()[0] - 1, ship.getYCoordinates()[ship.getLength() - 1] + 1,
                               2);
                board.setField(ship.getXCoordinates()[0] - 1, ship.getYCoordinates()[0] - 1, 2);
                board.setField(ship.getXCoordinates()[0] + 1, ship.getYCoordinates()[ship.getLength() - 1] + 1,
                               2);
                board.setField(ship.getXCoordinates()[0] + 1, ship.getYCoordinates()[0] - 1, 2);
            }

        }
    }
}



bool GameManager::attack(const int &x, const int &y,Board& board) {
    // 0- empty
    // 1- ship
    // 2- empty space near a ship
    // 3- hit
    // 4- missed

    if (board.getField(x,y)==1 or board.getField(x,y)==2){
        board.setField(x,y,3);
        return true;
    }
    else
    {
        board.setField(x,y,4);
        return false;
    }
}




void GameManager::computerShooting() {
    int tempX=1;
    int tempY=1;
    while(true) {
        tempX=rand()%playerBoard.getWidth()+1;
        tempY=rand()%playerBoard.getHeight()+1;
        if (playerBoard.getField(tempX,tempY)==0)
            break;
        else if (playerBoard.getField(tempX,tempY)==1)
            break;
        else if (playerBoard.getField(tempX,tempY) ==3)
            break;
    }

    std::cout<<"Computer has already shot: ("<<tempX<<","<<tempY<<"). "<<std::endl;
    if (attack(tempX,tempY,playerBoard)){
//        playerBoard.setField(tempX, tempY, 3);
        std::cout<<"Hit!"<<std::endl;
    }
    else
        std::cout<<"Computer missed"<<std::endl;
//    attack(tempX,tempY,playerBoard);
}

void GameManager::playerShooting(){
    int tempX=1;
    int tempY=1;
    std::cout<<"Captain, it's targeting time! I need coordinates: "<<std::endl;
    while (true){
        std::cout<<"X: ";
        std::cin>>tempX;
        std::cout<<"Y: ";
        std::cin>>tempY;
        if (((tempX>0)&&(tempX<=opponentBoard.getWidth()))&&((tempY>0)&&(tempY<=opponentBoard.getHeight())))
            break;
    }

    if (attack(tempX,tempY,opponentBoard)){
//    if (attack(tempX,tempY,playerBoard)) {
//        playerBoard.setField(tempX, tempY, 3);
        std::cout<<"Hit!"<<std::endl;
    }
    else
        std::cout<<"We missed"<<std::endl;
    attack(tempX,tempY,opponentBoard);

}

void GameManager::Game() {
    setGameArena();
    do {
        computerShooting();
        playerShooting();

    }
    while (!gameOver);
}

bool GameManager::checkShips(std::vector<Ship*>ships) {
    for (Ship* ship: ships){
        if (!(*ship).isFinished()){
            std::cout<<"Not finished\n";
        }
        else {
            std::cout<<"Finished\n";

        }
    }

    return true;
}



