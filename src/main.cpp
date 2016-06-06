#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
class tictac{
public: int orderPlayer=0; //with this variable we going to save the order of players
public: int orderLetter=0; //with this variable we going to save the letter of the players
public: int again=0; //with this variable we going to ask if the players wants to play again
public: int moved =0; //with this variable we going to save the moved of the player
public: char mark[10] = {'o','1','2','3','4','5','6','7','8','9'}; //mark or position of the moved of player
public: struct Player{//Structure for build the players
    string name="";
    char letter='X';
    int turn=0;
}player1, player2;
void board(){
    cout << "     |     |     " << endl;
    cout << "  " << mark[1] << "  |  " << mark[2] << "  |  " << mark[3] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << mark[4] << "  |  " << mark[5] << "  |  " << mark[6] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << mark[7] << "  |  " << mark[8] << "  |  " << mark[9] << endl;

    cout << "     |     |     " << endl << endl;
}
public: void gettingPlayers(){
    cout<<"\n\n\t \tTic Tac Toe \nLet's Begin... \n"<<endl;//bienvenida
    cout<<"1) Player's Name: "; cin>>player1.name;//jugador uno
    cout<<"2) Player's Name: "; cin>>player2.name;cout<<""<<endl;//jugador dos
}
public: void playersOrdering(){
    cout<<"Choose who will play first"<<endl;
    cout<<"1) "+player1.name<<endl;
    cout<<"2) "+player2.name<<endl;
    cout<<"3) Random"<<endl;
    cin>>orderPlayer;
    if(orderPlayer>3 || orderPlayer<1){
        cout<<"\nWrong choice. Please... \n"<<endl;
        playersOrdering();
    }else if(orderPlayer==3){
        srand(time(NULL));//getting a random value
        orderPlayer= rand() % 2+1;
        if(orderPlayer==1){
            cout<<"1ts Player: "+player1.name<<endl;
            cout<<"2nd Player: "+player2.name<<endl;
        }else{
            cout<<"1ts Player: "+player2.name<<endl;
            cout<<"2nd Player: "+player1.name<<endl;
        }
    }else if(orderPlayer==2){
        cout<<"1ts Player: "+player2.name<<endl;
        cout<<"2nd Player: "+player1.name<<endl;
    } else if(orderPlayer==1){
        cout<<"1ts Player: "+player1.name<<endl;
        cout<<"2nd Player: "+player2.name<<endl;
    }
}
public: void gettingLetter(){
    if(orderPlayer==1){
        cout<< player1.name+" choose your letter"<<endl;
        cout<<"1) X"<<endl;
        cout<<"2) O"<<endl;
        cin>>orderLetter;
        if(orderLetter>2 || orderLetter<1){
            cout<<"\nWrong choice. Please... \n"<<endl;
            gettingLetter();
        }else if(orderLetter==1){
            player1.letter='X';
            player2.letter='O';
        }else if(orderLetter==2){
            player1.letter='O';
            player2.letter='X';
        }
    }else if(orderPlayer==2){
        cout<< player2.name+" choose your letter"<<endl;
        cout<<"1) X"<<endl;
        cout<<"2) O"<<endl;
        cin>>orderLetter;
        if(orderLetter>2 || orderLetter<1){
            cout<<"\nWrong choice. Please... \n"<<endl;
            gettingLetter();
        }else if(orderLetter==1){
            player2.letter='X';
            player1.letter='O';
        }else if(orderLetter==2){
            player2.letter='O';
            player1.letter='X';
        }
    }
}
public: void playing(Player pOne, Player pTwo){
    system("cls");
    if(orderPlayer==1){//checking order of player
        if(pOne.turn==pTwo.turn){//checking how many moments did a player
            cout<<"Player 1: "+pOne.name+"("+pOne.letter+")";
            cout<<"\t VS\t"; cout<<"Player 2: "+pTwo.name+"("+pTwo.letter+")"<<endl;
            board();
            cout<<"Play "+pOne.name+": ";cin>>moved;
            while(moved>9 || moved<1 || mark[moved]=='X' || mark[moved]=='O'){//validating these options
                cout<<"\nWrong choice. Please... \n"<<endl;
                cout<<"Play "+pOne.name+": ";cin>>moved;
                if(moved<=9 && moved>=1 && mark[moved]!='X' && mark[moved]!='O'){
                    break;
                }
            }
            pOne.turn++;
            mark[moved]=pOne.letter;
            if(pOne.turn>2){//cheking how many moments did a player
                system("cls");
                cout<<"Player 1: "+pOne.name+"("+pOne.letter+")";
                cout<<"\t VS\t"; cout<<"Player 2: "+pTwo.name+"("+pTwo.letter+")"<<endl;
                board();
                gotWinner(pOne);
            }
            playing(pOne,pTwo);
        }else if(pOne.turn>pTwo.turn){
            cout<<"Player 1: "+pOne.name+"("+pOne.letter+")";
            cout<<"\t VS\t"; cout<<"Player 2: "+pTwo.name+"("+pTwo.letter+")"<<endl;
            board();
            cout<<"Play "+pTwo.name+": ";cin>>moved;
            while(moved>9 || moved<1 || mark[moved]=='X' || mark[moved]=='O'){
                cout<<"\nWrong choice. Please... \n"<<endl;
                cout<<"Play "+pTwo.name+": ";cin>>moved;
                if(moved<=9 && moved>=1 && mark[moved]!='X' && mark[moved]!='O'){
                    break;
                }
            }
            mark[moved]=pTwo.letter;
            pTwo.turn++;
            if(pTwo.turn>2){
                system("cls");
                cout<<"Player 1: "+pOne.name+"("+pOne.letter+")";
                cout<<"\t VS\t"; cout<<"Player 2: "+pTwo.name+"("+pTwo.letter+")"<<endl;
                board();
                gotWinner(pTwo);
            }
            playing(pOne,pTwo);
        }
    }else{
        if(pTwo.turn==pOne.turn){
            cout<<"Player 1: "+pTwo.name+"("+pTwo.letter+")";
            cout<<"\t VS\t"; cout<<"Player 2: "+pOne.name+"("+pOne.letter+")"<<endl;
            board();
            cout<<"Play "+pTwo.name+": ";cin>>moved;
            while(moved>9 || moved<1 || mark[moved]=='X' || mark[moved]=='O'){
                cout<<"\nWrong choice. Please... \n"<<endl;
                cout<<"Play "+pTwo.name+": ";cin>>moved;
                if(moved<=9 && moved>=1 && mark[moved]!='X' && mark[moved]!='O'){
                   break;
                }
            }

            mark[moved]=pTwo.letter;
            pTwo.turn++;
            if(pTwo.turn>2){
                system("cls");
                cout<<"Player 1: "+pTwo.name+"("+pTwo.letter+")";
                cout<<"\t VS\t"; cout<<"Player 2: "+pOne.name+"("+pOne.letter+")"<<endl;
                board();
                gotWinner(pTwo);
            }
            playing(pOne,pTwo);
        }else if(pTwo.turn>pOne.turn){
            cout<<"Player 1: "+pTwo.name+"("+pTwo.letter+")";
            cout<<"\t VS\t"; cout<<"Player 2: "+pOne.name+"("+pOne.letter+")"<<endl;
            board();
            cout<<"Play "+pOne.name+": ";cin>>moved;
            while(moved>9 || moved<1 || mark[moved]=='X' || mark[moved]=='O'){
                cout<<"\nWrong choice. Please... \n"<<endl;
                cout<<"Play "+pOne.name+": ";cin>>moved;
                if(moved<=9 && moved>=1 && mark[moved]!='X' && mark[moved]!='O'){
                    break;
                }
            }
            mark[moved]=pOne.letter;
            pOne.turn++;
            if(pOne.turn>2){
                system("cls");
                cout<<"Player 1: "+pTwo.name+"("+pTwo.letter+")";
                cout<<"\t VS\t"; cout<<"Player 2: "+pOne.name+"("+pOne.letter+")"<<endl;
                board();
                gotWinner(pOne);
            }
            playing(pOne,pTwo);
        }
    }
}
public: void gotWinner(Player winner){//checking how won
    if(mark[1]==winner.letter && mark[2]==winner.letter && mark[3]==winner.letter){
        cout<<winner.name+" wins!";
        playAgain();
    }
    if(mark[1]==winner.letter && mark[4]==winner.letter && mark[7]==winner.letter){
        cout<<winner.name+" wins!";
        playAgain();
    }
    if(mark[1]==winner.letter && mark[5]==winner.letter && mark[9]==winner.letter){
        cout<<winner.name+" wins!";
        playAgain();
    }
    if(mark[2]==winner.letter && mark[5]==winner.letter && mark[8]==winner.letter){
        cout<<winner.name+" wins!";
        playAgain();
    }
    if(mark[3]==winner.letter && mark[5]==winner.letter && mark[7]==winner.letter){
        cout<<winner.name+" wins!";
        playAgain();
    }
    if(mark[3]==winner.letter && mark[6]==winner.letter && mark[9]==winner.letter){
        cout<<winner.name+" wins!";
       playAgain();
    }
     if(winner.turn>4){
        cout<<"Estan empatados";
       playAgain();
    }

}
public: void playAgain(){
    cout<<"\nDo you want play again?"<<endl;
    cout<<"1) Si"<<endl;
    cout<<"2) No"<<endl;
    cin>>again;
    if(again>2 || again<1){
        cout<<"\nWrong choice. Please... \n"<<endl;
        playAgain();
    }else if(again==2){
        cout<<"Well, see you!!"<<endl;
        exit(0);
    }else if(again==1){
        orderPlayer=0;
        orderLetter=0;
        again=0;
        moved=0;
        player1.name="";
        player1.letter='X';
        player1.turn=0;
        player2.name="";
        player2.letter='X';
        player2.turn=0;
        mark[1]='1';
        mark[2]='2';
        mark[3]='3';
        mark[4]='4';
        mark[5]='5';
        mark[6]='6';
        mark[7]='7';
        mark[8]='8';
        mark[9]='9';
        starting();
    }
}
public: void starting(){
    system("cls");
    gettingPlayers();//getting players to play
    playersOrdering();//getting order to the players
    gettingLetter();//getting letter to the players
    playing(player1, player2);//starting the game
}
};

int main()
{
    tictac t;
    t.starting();//inicializando las variables y llamando los metodos en cadena.
    return 0;
}
