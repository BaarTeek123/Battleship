//
// Created by user on 24.06.2022.
//

#ifndef BATTLESHIP_SHIP_H
#define BATTLESHIP_SHIP_H


#include <iostream>
#include <vector>

class Ship {
    int length{1};
//    int xStart{1};
//    int yStart{1};
    std::vector<int>xCoordinates;
    std::vector<int>yCoordinates;
    bool plane;// 0 ---- 1|
    int damage;
    bool isAlive;
public:
    void increaseDamage();
    int getDamage() const;
    Ship (const int&,const int&,const int&,const bool&);
    Ship();
    int getLength() const;
    void setLength(const int&);
    bool getPlane() const;
    std::vector<int> getXCoordinates() const;
    std::vector<int> getYCoordinates() const;
    void setXCoordinate(const int&,const int &);
    void setYCoordinate(const int&,const int &);
//    void turnRight();
//    void turnLeft();
//    void rotate();
//    void moveUp();
//    void moveDown();
//    void moveLeft();
//    void moveRight();
    void info();
    void setProperties(const int&,const int&,const int&,const bool&);
    bool isFinished();
//    void setShip();
};


#endif //BATTLESHIP_SHIP_H
