#include<iostream>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char currentPlayer = 'X';

void drawBoard() {
  cout << "-------------" << endl;
  for (int i = 0; i < 3; i++) {
    cout << "| ";
    for (int j = 0; j < 3; j++) {
      cout << board[i][j] << " | ";
    }
    cout << "\n-------------" << endl; 
  }
}

bool playerMove(int slot){
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if(board[row][col] != 'X' && board[row][col] != 'O'){
        board[row][col] = currentPlayer;
        return true;
    }
    else{
        return false;
    }
}

void switchPlayer(){
    if(currentPlayer == 'X'){
        currentPlayer = 'O';
    }
    else{
        currentPlayer = 'X';
    }
}

bool isWin(){
    
    for(int i = 0; i < 3; i++){
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]){
            return true;
        }
        else if(board[0][i] == board[1][i] && board[1][i] == board[2][i]){
            return true;
        }
    }

    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]){
        return true;
    }
    else if(board[0][2] == board[1][1] && board[1][1] == board[2][0]){
        return true;
    }

    return false;
}

bool isDraw(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] != 'X' && board[i][j] != 'O'){
                return false;
            }
        }
    }
    return true;
}


int main(){

    char ans;
    int slot;
    cout << "Tic Tac Toe Game!" << endl;

    do{

        drawBoard();

        while(true){

            
            cout << "Player " << currentPlayer << ", Enter your slot (1 - 9): ";
            cin >> slot;

            if(!playerMove(slot)){
                cout << "Invalid slot as it is already taken! Try Again." <<  endl;
                cin >> slot;
                playerMove(slot);
            }

            drawBoard();

            if(isWin()){
                cout <<  "Congratulations! Player " << currentPlayer << " wins!" << endl;
                break;
            }

            if(isDraw()){
                cout << "Game Draw!" << endl;
                break;
            }

            switchPlayer();

        }

        cout << "Do you want to play again? (Y/N): ";
        cin >> ans;

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                board[i][j] = '0' + i * 3 + j + 1; 
            }
        }

    }while(ans == 'Y' || ans == 'y');

    cout << "Thanks for playing, Have a nice day!" <<  endl;
    return 0;

}