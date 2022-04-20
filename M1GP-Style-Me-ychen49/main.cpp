/**
 * This project is to get the input from user no matter it's Celsius or Fahenheit
 * user should specify what kind of notation they use
 **/

#include <iostream>
#include "Temp.h"
using namespace std;

/** Declaration of the global function
 * this function should retutn true if the input validated**/
void validateInput(int input);

int main() {
    int choice, temperature;
    cout << "Please enter 1. temperature(integer)   Type Here: ";
    cin >> temperature;
    validateInput(temperature);

    cout << "2. choice number(1 for fahrenheit & 2 for celsius)   Type Here: ";
    cin >> choice;
    validateInput(choice);

    Temp myTemp;
    if (choice == 1) {
        myTemp.setF(temperature);
    } else {
        myTemp.setC(temperature);
    }

    string message;
    if (myTemp.getF() < 32)
        message = "cold";
    else if (myTemp.getF() > 75)
        message = "hot";
    else
        message = "beautiful";
    cout << "Hello, " << message << " World!" << endl;



    return 0;
}

void validateInput(int input) {
    while(!cin) {
        cin.clear();
        cin.ignore(50, '\n');
        cout << "Please enter an integer. " << endl;
        cin >> input;
    }
}