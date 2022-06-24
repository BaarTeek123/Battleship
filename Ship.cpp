//
// Created by user on 24.06.2022.
//

#include "Ship.h"


#include "Ship.h"

// plane: 0 ---- 1|

Ship:: Ship (const int& length,const int& x,const int& y,const bool&plane) {
    isAlive=true;
    damage=0;
    if (length > 0)
        this->length = length;
    else this->length=1;
    xCoordinates.resize(length);
    yCoordinates.resize(length);
    xCoordinates[0] = x;
    yCoordinates[0] = y;
    this->plane=plane;
    if (!plane) {
        for (int i = 1; i < length; i++) {
            xCoordinates[i] = xCoordinates[0] + i;
            yCoordinates[i] = yCoordinates[0];
        }
    } else if (plane) {
        for (int i = 1; i < length; i++) {
            xCoordinates[i] = xCoordinates[0];
            yCoordinates[i] = yCoordinates[0] + i;
        }
    }
}


int Ship:: getLength() const{
    return this->length;
}

std::vector<int> Ship:: getXCoordinates() const {
    return xCoordinates;
}

std::vector<int> Ship:: getYCoordinates() const {
    return yCoordinates;
}

// plane: 0 ----[horizontal] 1|[vertical]
//void Ship::rotate(){
//    if (plane==1){
//        for (int i=1;i<length;i++){
//            xCoordinates[i]=xCoordinates[0]+i;
//            yCoordinates[i]=yCoordinates[0];
//        }
//        plane=false;
//    }
//
//    else{
//        for (int i=1;i<length;i++){
//            yCoordinates[i]=yCoordinates[0]+i;
//            xCoordinates[i]=xCoordinates[0];
//
//        }
//        plane=true;
//    }
//}
//
//void Ship::moveUp(){
//    for (int & yCoordinate : yCoordinates){
//        yCoordinate--;
//    }
//}
//
//void Ship::moveDown(){
//    for (int & yCoordinate : yCoordinates){
//        yCoordinate++;
//    }
//}
//
//void Ship::moveLeft(){
//    for (int & xCoordinate : xCoordinates){
//        xCoordinate--;
//    }
//}
//
//void Ship::moveRight(){
//    for (int & xCoordinate : xCoordinates){
//        xCoordinate++;
//    }
//}

void Ship::info(){
    std::cout<<"Length: "<<length<<std::endl;
    for (int i=0;i<length;i++) {
        std::cout <<i+1<<". "<<xCoordinates[i]<<" , "<<yCoordinates[i]<<std::endl;
    }
    if (plane){
        std::cout<<"Vertical"<<std::endl;
    }
    else std::cout<<"Horizontal"<<std::endl;
}


//void Ship::turnRight (){
//    if ((plane==1)&&(yCoordinates[0]>yCoordinates[1])){
//        for (int i=1;i<length;i++){
//            xCoordinates[i]=xCoordinates[0]+i;
//            yCoordinates[i]=yCoordinates[0];
//        }
//        this->plane=false;
//    }
//    else if ((plane==1)&&(yCoordinates[0]<yCoordinates[1])){
//        for (int i=1;i<length;i++){
//            xCoordinates[i]=xCoordinates[0]-i;
//            yCoordinates[i]=yCoordinates[0];
//        }
//        this->plane=false;
//    }
//    else if ((plane==0)&&(xCoordinates[0]<xCoordinates[1])){
//        for (int i=1;i<length;i++){
//            xCoordinates[i]=xCoordinates[0];
//            yCoordinates[i]=yCoordinates[0]+i;
//        }
//        this->plane=true;
//    }
//    else if ((plane==0)&&(xCoordinates[0]>xCoordinates[1])){
//        for (int i=1;i<length;i++){
//            yCoordinates[i]=yCoordinates[0]-i;
//            xCoordinates[i]=xCoordinates[0];
//
//        }
//        this->plane=true;
//    }
//}
//
//void Ship::turnLeft() {
//    if ((plane==1)&&(yCoordinates[0]>yCoordinates[1])){
//        for (int i=1;i<length;i++){
//            xCoordinates[i]=xCoordinates[0]-i;
//            yCoordinates[i]=yCoordinates[0];
//        }
//        this->plane=false;
//    }
//    else if ((plane==1)&&(yCoordinates[0]<yCoordinates[1])){
//        for (int i=1;i<length;i++){
//            xCoordinates[i]=xCoordinates[0]+i;
//            yCoordinates[i]=yCoordinates[0];
//        }
//        this->plane=false;
//    }
//    else if ((plane==0)&&(xCoordinates[0]<xCoordinates[1])){
//        for (int i=1;i<length;i++){
//            xCoordinates[i]=xCoordinates[0];
//            yCoordinates[i]=yCoordinates[0]-i;
//        }
//        this->plane=true;
//    }
//    else if ((plane==0)&&(xCoordinates[0]>xCoordinates[1])){
//        for (int i=1;i<length;i++){
//            yCoordinates[i]=yCoordinates[0]+i;
//            xCoordinates[i]=xCoordinates[0];
//
//        }
//        this->plane=true;
//    }
//}

bool Ship::getPlane() const {
    return plane;
}

void Ship::setProperties (const int& length, const int& x, const int& y, const bool&plane) {
    if (length > 0)
        this->length = length;
    else this->length=1;
    xCoordinates[0] = x;
    yCoordinates[0] = y;
    xCoordinates.resize(length);
    yCoordinates.resize(length);
    this->plane=plane;
    if (!plane) {
        for (int i = 1; i < length; i++) {
            xCoordinates[i] = xCoordinates[0] + i;
            yCoordinates[i] = yCoordinates[0];
        }
    }
    else {
        for (int i = 1; i < length; i++) {
            xCoordinates[i] = xCoordinates[0];
            yCoordinates[i] = yCoordinates[0] + i;
        }
    }
}

void Ship::setLength(const int&length) {
    this->length=length;
    if (!plane) {
        for (int i = 1; i < length; i++) {
            xCoordinates[i] = xCoordinates[0] + i;
            yCoordinates[i] = yCoordinates[0];
        }
    }
    else {
        for (int i = 1; i < length; i++) {
            xCoordinates[i] = xCoordinates[0];
            yCoordinates[i] = yCoordinates[0] + i;
        }
    }
}

void Ship::setYCoordinate(const int &idx,const int &value) {
    yCoordinates[idx]=value;
}

void Ship::setXCoordinate(const int &idx,const int &value) {
    xCoordinates[idx]=value;
}

Ship::Ship() {
    isAlive=true;
    damage=0;
    xCoordinates[0]=1;
    yCoordinates[0]=1;
    length=1;
    plane=true;
}

void Ship::increaseDamage() {
    damage++;
    if (damage==length){
        isAlive=false;
    }
}

int Ship::getDamage() const {
    return damage;
}



bool Ship::isFinished() {
    for (int x : xCoordinates){
        if (x==1){
            this->isAlive=true;
            return false;
    }}
    for (int y: yCoordinates){
        if (y==1){
            this->isAlive=true;
            return false;
    }}
    this->isAlive=false;
    return true;

}



