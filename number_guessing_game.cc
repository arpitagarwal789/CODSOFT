#include <iostream>  
#include <cstdlib>  
#include <ctime>  
using namespace std; 

int main(){

    int guessedNum, genNum, attempts = 1;

    cout << "WELCOME TO THE NUMBER GUESSING GAME!" << endl;
    cout << endl; 

    srand(time(0));  
    genNum = (rand() % 100) + 1;


    do{
        cout << "Guess the number between 1 to 100: " << endl;
        cin >> guessedNum; 

        if(guessedNum > genNum){
            cout << "Too High! Try Again." << endl;
        }
        else if(guessedNum < genNum){
            cout << "Too Low! Try Again." << endl;
        }
        else{
            cout << "You guessed in " << attempts << " attempts" << endl;
        }
        attempts++;

    }while(guessedNum != genNum);
 
}