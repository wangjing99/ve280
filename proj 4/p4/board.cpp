//
// Created by DELL on 2019/7/6.
//
#include "board.h"
#include <iostream>
using namespace std;
Board::Board() {//tested
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            this->grid[i][j]=Square((Vaxis)i,(Haxis)j);
        }
    }
}
Square &Board::getSquare(Vaxis v, Haxis h){//tested
    return this->grid[(int)v][(int)h];
}
Square &Board::getEmptySquare(Vaxis v, Haxis h){//tested
    if(this->grid[(int)v][(int)h].isEmpty()){
        return this->grid[(int)v][(int)h];
    }else{
        const string notempty="not empty";
        throw SquareException(this->grid[(int)v][(int)h],notempty);
    }
}
Square &Board::getEmptySquare(const std::string &s){//TESTED
    Vaxis v=A;
    Haxis h=H1;
    /*cout<<s[1]-'1'<<endl;
    if(s[0]-'A'==0){
        cout<<"getA"<<endl;
        v=A;
    }else if(s[0]-'A'==1){
        cout<<"getB"<<endl;
        v=B;
    }else if(s[0]-'A'==2){
        cout<<"getC"<<endl;
        v=C;
    }else if(s[0]-'A'==3){
        cout<<s[1]-'A'<<endl;
        cout<<"getD"<<endl;
        v=D;
    }else{
        const string notempty="not empty";
        throw SquareException(this->grid[(int)v][(int)h],notempty);
    }

    if(s[1]-'1'==0){
        cout<<"get1"<<endl;
        h=H1;
    }else if(s[1]-'1'==1){
        cout<<"get2"<<endl;
        h=H2;
    }else if(s[1]-'1'==2){
        cout<<"get3"<<endl;
        h=H3;
    }else if(s[1]-'1'==3){
        cout<<"get4"<<endl;
        h=H4;
    }*/
    if(s.size()>2){
        const string notempty="not empty";
        throw SquareException(this->grid[(int)v][(int)h],notempty);
    }else{
    const string a_1="A1";
    const string b_2="B2";
    const string c_3="C3";
    const string d_4="D4";
    if(s[0]==a_1[0]){
        //cout<<"getA"<<endl;
        v=A;
    }else if(s[0]==b_2[0]){
        //cout<<"getB"<<endl;
        v=B;
    }else if(s[0]==c_3[0]){
        //cout<<"getC"<<endl;
        v=C;
    }else if(s[0]==d_4[0]){
        //cout<<"getD"<<endl;
        v=D;
    }else{
        //cout<<"throwV"<<endl;
        const string notempty="not empty";
        throw SquareException(this->grid[(int)v][(int)h],notempty);
    }

    if(s[1]==a_1[1]){
        //cout<<"get1"<<endl;
        h=H1;
    }else if(s[1]==b_2[1]){
        //cout<<"get2"<<endl;
        h=H2;
    }else if(s[1]==c_3[1]){
        //cout<<"get3"<<endl;
        h=H3;
    }else if(s[1]==d_4[1]){
        //cout<<"get4"<<endl;
        h=H4;
    }else{
        //cout<<"throwH"<<endl;
        const string notempty="not empty";
        throw SquareException(this->grid[(int)v][(int)h],notempty);
    }
    }
    return getEmptySquare(v,h);
}
void Board::place(Piece &p, Square &sq){//tested
    sq.setPiece(&p);
    p.setUsed(true);
}
bool Board::isWinning(const Piece &p, const Square &sq){//tested

    int i;
    int height_same=0,color_same=0,shape_same=0,top_same=0;
    //determine the height
    //check roll
    try{
    for(i=0;i<4;i++){
        if(i==(int)sq.getH()){continue;}
        if(!p.compareHeight(this->grid[(int)sq.getV()][i].getPiece())){
            height_same=-1;
        }
        if(!p.compareColor(this->grid[(int)sq.getV()][i].getPiece())){
            color_same=-1;
        }
        if(!p.compareShape(this->grid[(int)sq.getV()][i].getPiece())){
            shape_same=-1;
        }
        if(!p.compareTop(this->grid[(int)sq.getV()][i].getPiece())){
            top_same=-1;
        }
    }
    if(height_same==0){
        return true;
    }else if(color_same==0){
        return true;
    }else if(shape_same==0){
        return true;
    }else if(top_same==0){
        return true;
    }}
    catch (SquareException &error){
        //cout<<"here roll "<<endl;
        //cout<<error.what()<<endl;
    }

    //check column
    try{
    height_same=0,color_same=0,shape_same=0,top_same=0;
    for(i=0;i<4;i++){
        if(i==(int)sq.getV()){continue;}
        if(!p.compareHeight(this->grid[i][(int)sq.getH()].getPiece())){
            height_same=-1;
        }
        if(!p.compareColor(this->grid[i][(int)sq.getH()].getPiece())){
            color_same=-1;
        }
        if(!p.compareShape(this->grid[i][(int)sq.getH()].getPiece())){
            shape_same=-1;
        }
        if(!p.compareTop(this->grid[i][(int)sq.getH()].getPiece())){
            top_same=-1;
        }
    }
    if(height_same==0){
        return true;
    }else if(color_same==0){
        return true;
    }else if(shape_same==0){
        return true;
    }else if(top_same==0){
        return true;
    }}
    catch (SquareException &error){
        //cout<<"here column"<<endl;
        //cout<<error.what()<<endl;
    }

    //check diag
    try{
    if(sq.isOnFirstDiagonal()){
        height_same=0,color_same=0,shape_same=0,top_same=0;
        for(i=0;i<4;i++){
            if(i==(int)sq.getV()){continue;}
            if(!p.compareHeight(this->grid[i][i].getPiece())){
                height_same=-1;
            }
            if(!p.compareColor(this->grid[i][i].getPiece())){
                color_same=-1;
            }
            if(!p.compareShape(this->grid[i][i].getPiece())){
                shape_same=-1;
            }
            if(!p.compareTop(this->grid[i][i].getPiece())){
                top_same=-1;
            }
        }
        if(height_same==0){
            return true;
        }else if(color_same==0){
            return true;
        }else if(shape_same==0){
            return true;
        }else if(top_same==0){
            return true;
        }
    }}
    catch (SquareException &error){
        //cout<<"here first"<<endl;
        //cout<<error.what()<<endl;
    }
    try{
    if(sq.isOnSecondDiagonal()){
        height_same=0,color_same=0,shape_same=0,top_same=0;
        for(i=0;i<4;i++){
            if(i==(int)sq.getV()){continue;}
            if(!p.compareHeight(this->grid[i][3-i].getPiece())){
                height_same=-1;
            }
            if(!p.compareColor(this->grid[i][3-i].getPiece())){
                color_same=-1;
            }
            if(!p.compareShape(this->grid[i][3-i].getPiece())){
                shape_same=-1;
            }
            if(!p.compareTop(this->grid[i][3-i].getPiece())){
                top_same=-1;
            }
        }
        if(height_same==0){
            return true;
        }else if(color_same==0){
            return true;
        }else if(shape_same==0){
            return true;
        }else if(top_same==0){
            return true;
        }
    }}
    catch (SquareException &error){
        //cout<<"here second "<<endl;
        //cout<<error.what()<<endl;
    }


    return false;
}
std::string Board::toString() const{//tested
    string output;
    Piece compare=Piece();
    Square s;
    output="     1    2    3    4\n";
    int v_i,h_i;
    for(v_i=0;v_i<N;v_i++){
        output+="   +----+----+----+----+\n";
        if(v_i==0){output+=" a |";}
        if(v_i==1){output+=" b |";}
        if(v_i==2){output+=" c |";}
        if(v_i==3){output+=" d |";}
        for(h_i=0;h_i<N;h_i++){
            try{
                s=this->grid[v_i][h_i];
                if(s.getPiece().compareHeight(compare)){
                    output+=" S";
                }else{
                    output+=" T";
                }
                s=this->grid[v_i][h_i];
                if(s.getPiece().compareColor(compare)){
                    output+="B |";
                }
                else{
                    output+="E |";
                }
            }
            catch (SquareException &error){
                output+="    |";
            }
        }
        output+="\n   |";
        for(h_i=0;h_i<N;h_i++){
            try{
                s=this->grid[v_i][h_i];
                if(s.getPiece().compareShape(compare)){
                    output+=" C";
                }else{
                    output+=" Q";
                }
                s=this->grid[v_i][h_i];
                if(s.getPiece().compareTop(compare)){
                    output+="H |";
                }
                else{
                    output+="O |";
                }
            }
            catch (SquareException &error){
                output+="    |";
            }
        }
        output+="\n";
    }
    output+="   +----+----+----+----+\n";
    return output;
}