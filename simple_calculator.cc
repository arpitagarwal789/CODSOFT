#include<iostream>
using namespace std;

int main(){

    double num1, num2 , result;
    char operation;
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;
    cout << "Enter the operation you want to perform: ";
    cin >> operation;

    switch(operation){

        case '+': result = num1 + num2;
        cout << result << endl;
        break;

        case '-': result = num1 - num2;
        cout << result << endl;
        break;

        case '*': result = num1 * num2;
        cout << result << endl;
        break;

        case '/': result = num1 / num2;
        cout << result << endl;
        break;

        default: cout << "Enter the valid operation!" << endl;
        break;
      
    }

}