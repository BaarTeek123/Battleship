//
// Created by user on 24.06.2022.
//

#ifndef BATTLESHIP_BOARD_H
#define BATTLESHIP_BOARD_H

#include <iostream>
#include <vector>

class Board {

    int width{10};
    int height{10};
    std::vector<std::vector<int>>area;
    // 0- empty
    // 1- ship
    // 2- empty space near a ship
    // 3- hit
    // 4- missed

public:
    Board();
    Board(const int&, const int&);
    int getField(const int&, const int&) const ;
    void setField(const int&, const int&, const int&);
    int getHeight() const;
    int getWidth() const;
    void drawArea(const bool&) const;
    void clear();


};


#endif //BATTLESHIP_BOARD_H
