/*
    Create a program that stores baseball player information into a vector
    User Requirements
        Ask the user how many baseball players you want to obtain data.
    Software Requirements
        Use Vectors to store the player's name, jersey number and playing status. 
            create an integer vector called playerNumbers to store the player's jersey numbe
            create a string vector called playerNames to store the player's name
            create a Boolean vector called playerAbsent to store the player's attendance status
        Retrieve the player's data from each vector and display it on the screen as seen in the figure above
*/
#include<vector> 
#include<string>
#include<iostream>
using namespace std;

int main() {
    //create necessary variables
    int playerCount;
    vector<int>playerNumbers;
    vector<string>playerNames;
    vector<bool>playerAbsent;

    // establish number of players
    cout<<"How many players are on the team: ";
    cin >> playerCount;

    //loop to get each players name, number, and participation in game
    for(int i = 1; i <= playerCount; i++ ) {
        
        int number;
        char playing;
        string name;
        
        cout << "What is player " << i << "'s name: ";
        cin >> name;
        playerNames.push_back(name);
        
        cout << "What is " << name << "'s jersey number: ";
        cin >> number;
        playerNumbers.push_back(number);
        
        cout << "Is " << name << " playing today (Y/N): ";
        cin >> playing;
            if (playing == 'Y') {
                playerAbsent.push_back(true);
            }
            else {
                playerAbsent.push_back(false);
            }
    }

    //output each players info
    for(int i = 0; i <= playerCount-1; i++){
        if (playerAbsent[i] == true){
            cout << playerNames[i] << "'s jersey number is " << playerNumbers[i] << " and is playing today." << endl;
        }
        else {
            cout << playerNames[i] << "'s jersey number is " << playerNumbers[i] << " and is not playing today." << endl;
        }
    }
    return 0;
};