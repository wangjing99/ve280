//
// Created by DELL on 2019/7/6.
//
#include "pool.h"
#include <iostream>
using namespace std;
Pool::Pool(){
    int h_i,c_i,s_i,t_i,piece_i;
    for(h_i=0;h_i<=1;h_i++){
        for(c_i=0;c_i<=1;c_i++){
            for(s_i=0;s_i<=1;s_i++){
                for(t_i=0;t_i<=1;t_i++){
                    piece_i=h_i*8+c_i*4+s_i*2+t_i*1;
                    this->pieces[piece_i]=Piece((Height)h_i,(Color)c_i,(Shape)s_i,(Top)t_i);
                    //cout<<"piece number="<<piece_i<<endl;
                    //cout<<this->pieces[piece_i].toString()<<endl;
                }
            }
        }
    }
}
Piece & Pool::getUnusedPiece(Height h, Color c, Shape s, Top t){
    int piece_id;
    piece_id=(int)h*8+(int)c*4+(int)s*2+(int)t;
    if(!this->pieces[piece_id].isUsed()){
        //cout<<"isused"<<endl;
        return this->pieces[piece_id];
    }else{
        //cout<<"throw"<<endl;
        throw UsedPieceException(this->pieces[piece_id]);
    }
}
Piece & Pool::getUnusedPiece(int index){
    if(!this->pieces[index].isUsed()){
        return this->pieces[index];
    }else{
        cout<<"throw"<<endl;
        throw UsedPieceException(this->pieces[index]);
    }
}
Piece & Pool::getUnusedPiece(const std::string &in){
    int piece_id=0;
    int h_i,c_i,s_i,t_i;
    /*const char compare_1=in[0];
    const char s_compare[]="S";
    if(compare_1==s_compare[0]){
        //cout<<"S"<<endl;
        h_i=0;
    }else{
        //cout<<"T"<<endl;
        h_i=1;
    }
    const char compare_2=in[1];
    const char b_compare[]="B";
    if(compare_2==b_compare[0]){
        //cout<<"B"<<endl;
        c_i=0;
    }else{
        //cout<<"E"<<endl;
        c_i=1;
    }
    const char compare_3=in[2];
    const char c_compare[]="C";
    if(compare_3==c_compare[0]){
        //cout<<"C"<<endl;
        s_i=0;
    }else{
        //cout<<"Q"<<endl;
        s_i=1;
    }
    const char compare_4=in[3];
    const char h_compare[]="H";
    if(compare_4==h_compare[0]){
        //cout<<"H"<<endl;
        t_i=0;
    }else{
        //cout<<"O"<<endl;
        t_i=1;
    }
    piece_id=h_i*8+c_i*4+s_i*2+t_i;
    cout<<"piece="<<piece_id<<endl;
    if(!this->pieces[piece_id].isUsed()){
        return this->pieces[piece_id];
    }else{
        cout<<"throw"<<endl;
        throw UsedPieceException(this->pieces[piece_id]);
    }*/
    if(in.size()>4){
        throw UsedPieceException(this->pieces[piece_id]);
    }
    const string sbch="SBCH";
    const string teqo="TEQO";
    if(in[0]==sbch[0]){
        h_i=0;
    }else if(in[0]==teqo[0]){
        h_i=1;
    }else{
        throw UsedPieceException(this->pieces[piece_id]);
    }

    if(in[1]==sbch[1]){
        c_i=0;
    }else if(in[1]==teqo[1]){
        c_i=1;
    }else{
        throw UsedPieceException(this->pieces[piece_id]);
    }

    if(in[2]==sbch[2]){
        s_i=0;
    }else if(in[2]==teqo[2]){
        s_i=1;
    }else{
        throw UsedPieceException(this->pieces[piece_id]);
    }

    if(in[3]==sbch[3]){
        t_i=0;
    }else if(in[3]==teqo[3]){
        t_i=1;
    }else{
        throw UsedPieceException(this->pieces[piece_id]);
    }

    piece_id=h_i*8+c_i*4+s_i*2+t_i;
    if(!this->pieces[piece_id].isUsed()){
        return this->pieces[piece_id];
    }else{
        //cout<<"throw"<<endl;
        throw UsedPieceException(this->pieces[piece_id]);
    }

}

std::string Pool::toString() const{
    string output="Available:\n";
    int i;
    int used=0;
    //first roll
    for(i=0;i<16;i++){
        if(!this->pieces[i].isUsed()){
            used++;
            //S or T
            if(i<=7){
                output+="S";
            }else{
                output+="T";
            }
            //B or E
            if(i<=3||(i>=8&&i<=11)){
                output+="B ";
            }else{
                output+="E ";
            }
        }
    }
    output+="\n";
    string empty="";
    if(used==0){
        return empty;
    }
    //second roll
    for(i=0;i<16;i++){
        if(!this->pieces[i].isUsed()){
            //C or Q
            if(i%4==0||i%4==1){
                output+="C";
            }else{
                output+="Q";
            }
            //H or O
            if(i%2==0){
                output+="H ";
            }else{
                output+="O ";
            }
        }
    }
    output+="\n";
    return output;
}
