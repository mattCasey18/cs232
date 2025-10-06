/*
    Prompt: Write a program that prompts the user for the length of a cube's sides (an integer value) and then displays a cube made of * characters. The cube should have 
            equal width, height, and depth matching the entered side length.

    Restrictions: 
        No hardcoding output. Your cube must adjust according to the side value entered by the user. 
        You must implement a class to represent the cube.
    
    Validation:
        Ensure the value entered is greater than 0. 
        If the input is invalid, display an error message and prompt the user to enter a value greater than 0.

*/


#include <iostream>
#include "Cube.h"
using namespace std;

int main() {
    int side;

    cout << "Enter a cube side value: ";
    cin >> side;

    while (side <= 0) {
        cout << "Please enter a value greater than 0: ";
        cin >> side;
    }

    Cube myCube(side);
    myCube.draw();

    return 0;
}