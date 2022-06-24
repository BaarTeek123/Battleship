//
// Created by user on 24.06.2022.
//

#include "Board.h"

#include "Board.h"

Board::Board (): width(10),height(10) {
    area.resize(height);
    for (int i = 0; i < height; i++)
        area[i].resize(width);
    for (int i=0;i<height;i++){
        for (int j=0;j<width;j++){
            area[i][j]=0;
        }
    }
}

Board::Board (const int& width,const int& height): width(width),height(height) {
    area.resize(height);
    for (int i=0;i<height;i++)
        area[i].resize(width);
    for (int i=0;i<height;i++) {
        for (int j = 0; j < width; j++) {
            area[i][j] = 0;
        }
    }
}

int Board:: getHeight() const{
    return height;
}
int Board:: getWidth() const{
    return width;
}

void Board::drawArea(const bool& isSettingShips) const {
    for (int i=0;i<=height;i++){
        for (int j=0;j<=width;j++){
            if ((i==0)&&(j==0))
                std::cout<<"   ";
            if ((i>0)&&(i<10)&&(j==0)){
                std::cout<<" "<<i<<" ";
            }
            if ((i>=10)&&(j==0)){
                std::cout<<i<<" ";
            }
            if ((i==0)&&(j>0))
                std::cout<<j<<" ";
            if ((i>0)&&(j<10)) {
                if (area[i-1][j]==1){
                    std::cout << /*area[i-1][j]<<*/"X ";}
                else if (area[i-1][j]==3)
                    std::cout<<"O ";
                else if (area[i-1][j]==4)
                    std::cout<<"* ";
                else if ((area[i-1][j]==2) && isSettingShips)
                    std::cout<<"* ";
                else std::cout<<". ";
            }
            if ((i>0)&&(j>=10)&&(j<width)){
                if (area[i-1][j]==2)
                    std::cout<<"  X"/*<<area[i-1][j]*/;
                else if (area[i-1][j]==3)
                    std::cout<<"  |";
                else if (area[i-1][j]==4)
                    std::cout<<"  O";
                else if ((area[i-1][j]==2) && isSettingShips)
                    std::cout<<"  *";
                else std::cout<<"  .";
            }
        }
        std::cout<<std::endl;
    }
}
// 0- empty
// 1- ship
// 2- empty space near a ship
// 3- hit
// 4- missed


void Board::clear(){
    for (int i=0;i<=height;i++){
        for (int j=0;j<=width;j++){
            if ((i==0)&&(j==0))
                std::cout<<"   ";
            if ((i>0)&&(i<10)&&(j==0)){
                std::cout<<" "<<i<<" ";
            }
            if ((i>=10)&&(j==0)){
                std::cout<<i<<" ";
            }
            if ((i==0)&&(j>0))
                std::cout<<j<<" ";
            if ((i>0)&&(j<10)) {
                if (area[i-1][j]==1){
                    std::cout << /*area[i-1][j]<<*/"X ";}
//                else if (area[i-1][j]==2)
//                    std::cout<<"O ";
                else std::cout<<". ";
            }
            if ((i>0)&&(j>=10)&&(j<width)){
                if (area[i-1][j]==1)
                    std::cout<<"  X"/*<<area[i-1][j]*/;
//                else if (area[i-1][j]==2)
//                    std::cout<<"  O";
                else std::cout<<"  .";
            }
        }
        std::cout<<std::endl;
    }

}

int Board:: getField(const int&x, const int&y) const{
    return area[y-1][x-1];
}

void Board:: setField(const int&x, const int&y, const int&field){
    area[y-1][x-1]=field;
}




