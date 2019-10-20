//
// Created by DELL on 2019/7/6.
//
#include "piece.h"
#include <iostream>
using namespace std;

Piece::Piece(Height h, Color c, Shape s, Top t){
    this->used=false;//should be false
    this->h=h;
    this->c=c;
    this->s=s;
    this->t=t;
}
bool Piece::compareHeight(const Piece &p) const{
    if(this->h==p.h){
        return true;
    }
    else{
        return false;
    }
}
bool Piece::compareColor(const Piece &p) const{
    if(this->c==p.c){
        return true;
    }
    else{
        return false;
    }
}
bool Piece::compareShape(const Piece &p) const{
    if(this->s==p.s){
        return true;
    }
    else{
        return false;
    }
}
bool Piece::compareTop(const Piece &p) const{
    if(this->t==p.t){
        return true;
    }
    else{
        return false;
    }
}
bool Piece::isUsed() const{
    return this->used;
}

void Piece::setUsed(bool u){
    this->used=u;
}
std::string Piece::toString() const{
   string name="";
   if(h==0){
       name+="S";
   }else{
       name+="T";
   }

   if(c==0){
       name+="B";
   }
   else{
       name+="E";
   }

    if(s==0){
        name+="C";
    }
    else{
        name+="Q";
    }

    if(t==0){
        name+="H";
    }
    else{
        name+="O";
    }
    return name;
}

