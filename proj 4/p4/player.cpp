//
// Created by DELL on 2019/7/6.
//
#include "player.h"
#include <iostream>
using namespace std;
class HumanPlayer : public Player{
    protected:
        Board *humanboard;
        Pool *humanpool;
    public:
        HumanPlayer(Board *board, Pool *pool):Player(board,pool){
            this->humanboard=board;
            this->humanpool=pool;
        };

    virtual Piece & selectPiece(){
        string input;
        string sbch="SBCH";
        string teqo="TEQO";
        //int i;
        do{
            cout<<"Enter a piece:";
            cin>>input;
            //find the index of the piece
            try{
                return humanpool->getUnusedPiece(input);
                //break;
            }
            catch (UsedPieceException &error){
                if(input.size()==4&&(input[0]==sbch[0]||input[0]==teqo[0])&&
                        (input[1]==sbch[1]||input[1]==teqo[1])&&
                        (input[2]==sbch[2]||input[2]==teqo[2])&&
                        (input[3]==sbch[3]||input[3]==teqo[3])){cout<<input<<" is already used."<<endl;

                }else{
                cout<<input<<" is an invalid input."<<endl;}
                continue;
            }
        }while(1);

    };

    virtual Square & selectSquare(const Piece &p){//const
        string input;
        //int i;
        do{
            cout<<"Enter a position:";
            cin>>input;
            //find the index of the piece
            try{
                humanboard->getEmptySquare(input);
                break;
            }
            catch (SquareException &error){
                if(input.size()>2){cout<<input<<" is an invalid input."<<endl;}
                else if(input[0]-'A'>=0&&input[0]-'A'<=3&&input[1]-'1'>=0&&input[1]-'1'<=3){
                    cout<<input<<" is not empty."<<endl;
                }else{
                    cout<<input<<" is an invalid input."<<endl;
                }
                continue;
            }
        }while(1);
        return humanboard->getEmptySquare(input);
        //board->place(p,humanboard->getEmptySquare(input));
    };
};

class MyopicPlayer : public Player{
    protected:
        Board *mboard;
        Pool *mpool;
        int seed;
    public:
        MyopicPlayer(Board *board, Pool *pool,int s):Player(board,pool){
            this->mboard=board;
            this->mpool=pool;
            this->seed=s;
            srand(seed);
        };
    virtual Piece & selectPiece(){
        //find the unused piece
        int h_i,c_i,s_i,t_i;
        int va_i,ha_i;
        string good_name_record[16];
        string bad_name_record[16];
        //int record=0;
        int good_index=0;
        int bad_index=0;
        int winning;
        string piece_name;
        for(h_i=0;h_i<2;h_i++){
            for(c_i=0;c_i<2;c_i++){
                for(s_i=0;s_i<2;s_i++){
                    for(t_i=0;t_i<2;t_i++){
                        //whether used
                        try{
                            piece_name=mpool->getUnusedPiece((Height)h_i,(Color)c_i,(Shape)s_i,(Top)t_i).toString();
                        }
                        catch (UsedPieceException &error){
                            //cout<<piece_name<<"used"<<endl;
                            continue;
                        }
                        bad_name_record[bad_index]=piece_name;
                        bad_index++;
                        //not used, check each position on the board
                        winning=0;
                        for(va_i=0;va_i<4;va_i++){
                            for(ha_i=0;ha_i<4;ha_i++){
                                try{

                                    mboard->getEmptySquare((Vaxis)va_i,(Haxis)ha_i);
                                }
                                catch (SquareException &error){
                                    //cout<<"V="<<va_i<<",H="<<ha_i<<"not empty"<<endl;
                                    continue;
                                }
                                //check if winning

                                if(mboard->isWinning(mpool->getUnusedPiece(piece_name),mboard->getEmptySquare((Vaxis)va_i,(Haxis)ha_i))){

                                    winning=1;
                                }
                            }
                        }
                        if(winning==0){//not bad,record the piece

                            good_name_record[good_index]=piece_name;
                            good_index++;
                        }
                    }
                }
            }
        }
        //check is there any good piece
        if(good_index>0){
            //cout<<"good_index"<<good_index<<endl;
            return mpool->getUnusedPiece(good_name_record[rand()%good_index]);
        }else{
            return mpool->getUnusedPiece(bad_name_record[rand()%bad_index]);
        }

    };


    virtual Square & selectSquare(const Piece &p) {//const
        int ha_i,va_i,index;
        string empty[16];
        string sq_name;
        index=0;

            for(va_i=0;va_i<4;va_i++){for(ha_i=0;ha_i<4;ha_i++){
                //check whether empty
                try{
                    mboard->getEmptySquare((Vaxis)va_i,(Haxis)ha_i);
                }
                catch (SquareException &error){
                    continue;
                }
                //record the empty square
                sq_name=mboard->getEmptySquare((Vaxis)va_i,(Haxis)ha_i).toString();
                empty[index]=sq_name;
                index++;
                //check if winning
                if(mboard->isWinning(p,mboard->getEmptySquare((Vaxis)va_i,(Haxis)ha_i))){
                    return mboard->getEmptySquare((Vaxis)va_i,(Haxis)ha_i);
                }
            }
        }
        return mboard->getEmptySquare(empty[rand()%index]);
    };

};

static HumanPlayer h_p=HumanPlayer(NULL,NULL);
static MyopicPlayer m_p=MyopicPlayer(NULL,NULL,0);

extern Player *getMyopicPlayer(Board *b, Pool *p,unsigned int seed){
    m_p=MyopicPlayer(b,p,(int)seed);
    Player *ptr=&m_p;
    return ptr;
}
extern Player *getHumanPlayer(Board *b,Pool *p){
    h_p=HumanPlayer(b,p);
    Player *ptr=&h_p;
    return ptr;
}