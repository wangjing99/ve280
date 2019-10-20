//
// Created by DELL on 2019/7/6.
//
#include "square.h"
#include <iostream>
using namespace std;
Square::Square(Vaxis v, Haxis h){
    this->v=v;
    this->h=h;
    this->p=NULL;
}
Vaxis Square::getV() const{
    return this->v;
}
void Square::setV(Vaxis v){
    this->v=v;
}
Haxis Square::getH() const{
    return this->h;
}
void Square::setH(Haxis h){
    this->h=h;
}
const Piece & Square::getPiece() const {///////zhe shi cuo de
    if(this->p==NULL){
        const string empty="empty";
        throw SquareException(*this,empty);
    }else{
        return *this->p;
    }
}
void Square::setPiece(const Piece *p){
    this->p=p;
    //this->p.setUsed(true);
}
bool Square::isEmpty() const{
    if(this->p==NULL){
        return true;
    }
    else{
        return false;
    }
}
bool Square::isOnFirstDiagonal() const{
    /*if((int)this->h==(int)this->p){
        return true;
    }else{
        return false;}*/
    const Vaxis A_=A;
    const Vaxis B_=B;
    const Vaxis C_=C;
    const Vaxis D_=D;
    const Haxis H1_=H1;
    const Haxis H2_=H2;
    const Haxis H3_=H3;
    const Haxis H4_=H4;
    if((this->h==H1_&&this->v==A_)||(this->h==H2_&&this->v==B_)||(this->h==H3_&&this->v==C_)||(this->h==H4_&&this->v==D_)){
        return true;
    }else{
        return false;
    }
}
bool Square::isOnSecondDiagonal() const{
    const Vaxis A_=A;
    const Vaxis B_=B;
    const Vaxis C_=C;
    const Vaxis D_=D;
    const Haxis H1_=H1;
    const Haxis H2_=H2;
    const Haxis H3_=H3;
    const Haxis H4_=H4;
    if((this->h==H1_&&this->v==D_)||(this->h==H2_&&this->v==C_)||(this->h==H3_&&this->v==B_)||(this->h==H4_&&this->v==A_)){
        return true;
    }else{
        return false;}
}
std::string Square::toString() const{
    const Vaxis A_=A;
    const Vaxis B_=B;
    const Vaxis C_=C;
    const Vaxis D_=D;
    const Haxis H1_=H1;
    const Haxis H2_=H2;
    const Haxis H3_=H3;
    const Haxis H4_=H4;

    string output="";
    if(this->v==A_){
        output+="A";
    }else if(this->v==B_){
        output+="B";
    }else if(this->v==C_){
        output+="C";
    }else if(this->v==D_){
        output+="D";
    }

    if(this->h==H1_){
        output+="1";
    }else if(this->h==H2_){
        output+="2";
    }else if(this->h==H3_){
        output+="3";
    }else if(this->h==H4_){
        output+="4";
    }
    return output;
}