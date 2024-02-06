// tik tak toe started on 06.02.2024, 21:04 by DanielSy
#include <iostream> 
using namespace std; 

// Array masa
char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
//variabile
int choice;
int row,column;
char turn = 'X';
bool draw = false;
int msj;
void display_board(){

    //arata masa

    std::cout<<"JUCATOR - 1 [X] JUCATOR - 2 [O]" << endl;
    std::cout<<"     |     |     "  << endl;
    std::cout<<"  "<<board[0][0]<<"  | "<<board[0][1]<<"  |  "<<board[0][2]<< endl;
    std::cout<<"_____|_____|_____"  << endl;
    std::cout<< "    |     |     "  << endl;
    std::cout<<"  "<<board[1][0]<<"  | "<<board[1][1]<<"  |  "<<board[1][2]<<endl;
    std::cout<<"_____|_____|_____" << endl;
    std::cout<<"     |     |     "  << endl;
    std::cout<<"  "<<board[2][0]<<"  | "<<board[2][1]<<"  |  "<<board[2][2]<<endl;
    std::cout<<"     |     |     "  << endl;
}	

void turn_p(){
    if(turn == 'X'){
        std::cout<<"Jucator - 1 [X] : "  << endl;
    }
    else if(turn == 'O'){
        std::cout<<"Jucator - 2 [O] : "  << endl;
    }
    //citeste de la tastatura
    //updateaza masa


    std::cin>> choice;

    //switch case to get which row and column will be update

    switch(choice){
        case 1: row=0; column=0; break;
        case 2: row=0; column=1; break;
        case 3: row=0; column=2; break;
        case 4: row=1; column=0; break;
        case 5: row=1; column=1; break;
        case 6: row=1; column=2; break;
        case 7: row=2; column=0; break;
        case 8: row=2; column=1; break;
        case 9: row=2; column=2; break;
        default:
            std::cout<<"Invalid Move";
    }

    if(turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O'){
//update
        board[row][column] = 'X';
        turn = 'O';
    }else if(turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O'){
//update
        board[row][column] = 'O';
        turn = 'X';
    }else {
// invalid sign
        std::cout<<"Acest sign a fost selectat deja!";
        turn_p();
    }
    display_board();
}



bool g_over(){
    // check win
    for(int i=0; i<3; i++)
    if(board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
    return false;

    //check diagonala

    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
    return false;

    //continue sau nu
    for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
    if(board[i][j] != 'X' && board[i][j] != 'O')
    return true;

    //if draw == true
    draw = true;
    return false;
}


int main()
{
    std::cout<<"T I C K -- T A C -- T O E -- G A M E"  << endl;
    std::cout<<"2 JUCATORI"  << endl;
    while(g_over()){
        display_board();
        turn_p();
        g_over();
    }
    if(turn == 'X' && draw == false){
        std::cout<<"Felicitari !Jucatorul cu 'O' a castigat jocul!"  << endl;
    }
    else if(turn == 'O' && draw == false){
        std::cout<<"Felicitari !Jucatorul cu 'X' a castigat jocul!"  << endl;
    }
    else
    std::cout<<"Remiza, inca o fisa?"  << endl;

    while(15) {
        std::cout<<"Copyright @ DanielSy gameforplay.ro" << endl;
        msj ++;
        if(msj > 15) return true;
        
    }
    return true;

} 
