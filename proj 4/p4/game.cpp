//
// Created by DELL on 2019/7/6.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>

#include "player.h"

using namespace std;
int main(int argc, char *argv[]){

    try{
        Pool pool=Pool();
        Pool *pool_ptr=&pool;
        Board board=Board();
        Board *board_ptr=&board;
        Piece *sel_piece;
        Square *sel_square;
        string compare=argv[1];//find the first player
        string h_str="h";
        string m_str="m";
        Player *player_1=getHumanPlayer(board_ptr,pool_ptr);
        Player *player_2=getHumanPlayer(board_ptr,pool_ptr);
//cout<<"1="<<argv[1]<<endl<<"2="<<argv[2]<<endl<<"3="<<argv[3]<<endl;
        if(compare==h_str){
            player_1=getHumanPlayer(board_ptr,pool_ptr);
        }else if(compare==m_str){
            player_1=getMyopicPlayer(board_ptr,pool_ptr,(unsigned int)atoi(argv[3]));
        }else{
            cout<<"invalid player 1"<<endl;
        }

        compare=argv[2];//find the second player
        if(compare==h_str){
            player_2=getHumanPlayer(board_ptr,pool_ptr);
        }else if(compare==m_str){
            player_2=getMyopicPlayer(board_ptr,pool_ptr,(unsigned int)atoi(argv[3]));
        }else{
            cout<<"invalid player 2"<<endl;
        }
        int round=0;
        cout<<board.toString()<<endl;
        cout<<pool.toString()<<endl;
        for(round=0;round<8;round++){
            cout<<"Player 1's turn to select a piece:"<<endl;
            sel_piece=&player_1->selectPiece();
            cout<<sel_piece->toString()<<" selected.\n"<<endl;
            cout<<"Player 2's turn to select a square:"<<endl;
            sel_square=&player_2->selectSquare(*sel_piece);
            cout<<sel_square->toString()<<" selected.\n"<<endl;
            board.place(*sel_piece,*sel_square);
            cout<<board.toString()<<endl;
            cout<<pool.toString()<<endl;
            if(board.isWinning(*sel_piece,*sel_square)){
                cout<<"Player 2 has won!"<<endl;
                break;
            }
            cout<<"Player 2's turn to select a piece:"<<endl;
            sel_piece=&player_2->selectPiece();
            cout<<sel_piece->toString()<<" selected.\n"<<endl;
            cout<<"Player 1's turn to select a square:"<<endl;
            sel_square=&player_1->selectSquare(*sel_piece);
            cout<<sel_square->toString()<<" selected.\n"<<endl;
            board.place(*sel_piece,*sel_square);
            cout<<board.toString()<<endl;
            cout<<pool.toString()<<endl;
            if(board.isWinning(*sel_piece,*sel_square)){
                cout<<"Player 1 has won!"<<endl;
                break;
            }

            if(round==7){
                cout<<"It is a draw."<<endl;
                break;
            }
        }


    }
    catch (UsedPieceException &error){
        cout<<"UsedPieceException "<<endl;
        //cout<<error.what()<<endl;

    }
    catch (SquareException &error){
        cout<<"SquareException catched "<<endl;
        //cout<<error.what()<<endl;
    }
}/*Player *h_p=getHumanPlayer(board_ptr,pool_ptr);
        Player *m_p=getMyopicPlayer(board_ptr,pool_ptr,(unsigned int)atoi(argv[3]));
        string hm="h";
        string compare=argv[1];
        int round=0;
        if(compare==hm){
            cout<<board.toString()<<endl;
            cout<<pool.toString()<<endl;
            for(round=0;round<8;round++){
                cout<<"Player 1's turn to select a piece:"<<endl;
                sel_piece=&h_p->selectPiece();
                cout<<sel_piece->toString()<<" selected."<<endl;
                cout<<"Player 2's turn to select a square:"<<endl;
                sel_square=&m_p->selectSquare(*sel_piece);
                cout<<sel_square->toString()<<" selected."<<endl;
                board.place(*sel_piece,*sel_square);
                cout<<board.toString()<<endl;
                cout<<pool.toString()<<endl;
                if(board.isWinning(*sel_piece,*sel_square)){
                    cout<<"Player 2 has won!"<<endl;
                    break;
                }
                cout<<"Player 2's turn to select a piece:"<<endl;
                sel_piece=&m_p->selectPiece();
                cout<<sel_piece->toString()<<" selected."<<endl;
                cout<<"Player 1's turn to select a square:"<<endl;
                sel_square=&h_p->selectSquare(*sel_piece);
                cout<<sel_square->toString()<<" selected."<<endl;
                board.place(*sel_piece,*sel_square);
                cout<<board.toString()<<endl;
                cout<<pool.toString()<<endl;
                if(board.isWinning(*sel_piece,*sel_square)){
                    cout<<"Player 1 has won!"<<endl;
                    break;
                }

                if(round==7){
                    cout<<"It is a draw."<<endl;
                    break;
                }
            }

        }else{
            cout<<board.toString()<<endl;
            cout<<pool.toString()<<endl;
            for(round=0;round<8;round++){
                cout<<"Player 1's turn to select a piece:"<<endl;
                sel_piece=&m_p->selectPiece();
                cout<<sel_piece->toString()<<" selected."<<endl;
                cout<<"Player 2's turn to select a square:"<<endl;
                sel_square=&h_p->selectSquare(*sel_piece);
                cout<<sel_square->toString()<<" selected."<<endl;
                board.place(*sel_piece,*sel_square);
                cout<<board.toString()<<endl;
                cout<<pool.toString()<<endl;
                if(board.isWinning(*sel_piece,*sel_square)){
                    cout<<"Player 2 has won!"<<endl;
                    break;
                }
                cout<<"Player 2's turn to select a piece:"<<endl;
                sel_piece=&h_p->selectPiece();
                cout<<sel_piece->toString()<<" selected."<<endl;
                cout<<"Player 1's turn to select a square:"<<endl;
                sel_square=&m_p->selectSquare(*sel_piece);
                cout<<sel_square->toString()<<" selected."<<endl;
                board.place(*sel_piece,*sel_square);
                cout<<board.toString()<<endl;
                cout<<pool.toString()<<endl;
                if(board.isWinning(*sel_piece,*sel_square)){
                    cout<<"Player 1 has won!"<<endl;
                    break;
                }

                if(round==7){
                    cout<<"It is a draw."<<endl;
                    break;
                }
            }
        }*/