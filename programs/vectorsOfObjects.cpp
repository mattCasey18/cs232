/*
    Create a program that stores baseball player information into a vector

    User Requirements:
        Create a menu system that allows the user to enter, remove and modify a team of baseball players 

    Software Requirements:
    - Create a vector of baseball player objects that gives the user the ability to enter a new player, remove any given
        player, change the players jersey number, change the availability of a player, change the name of a player and
        finally display the team roster (see Figure 1).
    - Create a class called BaseballPlayers as seen in the header file image below
        Figure 2: BaseballPlayers Header File

*/

#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <limits>
using namespace std;

class BaseballPlayers {
    public:
        BaseballPlayers();
        BaseballPlayers(int jerseyNumPar, bool isAvailablePar, string namePar);
        void setJerseyNumber(int jerseyNumPar) {
            jerseyNumber = jerseyNumPar;
        };
        void setIsAvailable(bool isAvailablePar) {
            isAvailable = isAvailablePar;
        };
        void setFirstName(string namePar) {
            firstName = namePar;
        };

        int getJerseyNumber() {
            return jerseyNumber;
        };
        bool getIsAvailable(){
            return isAvailable;
        };
        string getName() {
            return firstName;
        };
    private:

        int jerseyNumber;
        bool isAvailable;
        string firstName;
};

BaseballPlayers::BaseballPlayers() 
    : jerseyNumber(0), isAvailable(false), firstName("Unknown") {}

BaseballPlayers::BaseballPlayers(int jerseyNumPar, bool isAvailablePar, string namePar) 
    : jerseyNumber(jerseyNumPar), isAvailable(isAvailablePar), firstName(namePar) {}

string toLowerCase(const string& str) {
    string lower = str;
    transform(lower.begin(), lower.end(), lower.begin(),
              [](unsigned char c){ return tolower(c); });
    return lower;
}

int searchFunction(string inputName, vector<BaseballPlayers>& inputObj) {
    // receives input of what name they want to change and finds associated object
    string searchName = toLowerCase(inputName);
    for(int i = 0; i < inputObj.size(); i++) {
        if(toLowerCase(inputObj[i].getName()) == searchName) {
            return i;
        }
    }
    return -1;
}

int printMenu() {
    cout << "1 - add player(s) to the team" << endl;
    cout << "2 - remove a player from the team" << endl;
    cout << "3 - change a player's jersey number" << endl;
    cout << "4 - change a player's availability" << endl;
    cout << "5 - change a player's name" << endl;
    cout << "6 - display team" << endl;
    cout << "7 - quit\n";
    cout << "------------------------------------" << endl;
    int response;
    while (true) {
        cout << "Enter your choice: ";

        if (cin >> response) {
            if (response >= 1 && response <= 7) {
                return response; // valid input
            } else {
                cout << "Please enter a number between 1 and 7.\n";
            }
        } else {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear(); // clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard bad input
        }
    }
}

void addPlayers (vector<BaseballPlayers>& players) {
    int playerAdd;
    cout<<"How many players do you want to add: ";
    cin >> playerAdd;

    //loop to get each players name, number, and participation in game
    for(int i = 1; i <= playerAdd; i++ ) {
        
        int number;
        char play;
        string name;
        bool playing;
        
        cout << "What is player " << i << "'s name: ";
        cin >> name;
        
        cout << "What is " << name << "'s jersey number: ";
        cin >> number;
        
        cout << "Is " << name << " playing today (Y/N): ";
        cin >> play;
        if (play == 'y' || play == 'Y'){
            playing = true;
        }
        else {
            playing = false; 
        }
        
        BaseballPlayers obj(number, playing, name);
        players.push_back(obj);
    
    }
}

void removePlayers(vector<BaseballPlayers>& players){
    //after user selects that they want to remove a player, they will enter a name and then that player will be removed
    string inputName;
    cout << "What is the name of the player you want to remove: ";
    cin >> inputName;
    int idx = searchFunction(inputName, players);
    if (idx != -1) {
        players.erase(players.begin() + idx);
        cout << inputName << " has been removed.\n";
    } else {
        cout << "Player not found.\n";
    }

};

bool isJerseyTaken(int jerseyNumber, vector<BaseballPlayers>& players, int excludeIndex = -1) {
    for (size_t i = 0; i < players.size(); i++) {
        if (i == excludeIndex) continue; // skip the player being updated
        if (players[i].getJerseyNumber() == jerseyNumber) {
            return true;
        }
    }
    return false;
}


void changeNumber (vector<BaseballPlayers>& players) {
    string inputName;
    int newJerseyNumPar;
    cout << "Enter the name of the player who's jersey you want to change: ";
    cin >> inputName;
    int idx = searchFunction(inputName, players);
    if (idx == -1) {
        cout << "Player not found.\n";
        return;
    }

     while (true) {
        cout << "Enter " << inputName << "'s new jersey number (positive integer): ";

        if (cin >> newJerseyNumPar) {
            if (newJerseyNumPar <= 0) {
                cout << "Jersey number must be a positive integer. Try again.\n";
                continue;
            }
            if (isJerseyTaken(newJerseyNumPar, players, idx)) {
                cout << "That jersey number is already taken by another player. Try again.\n";
                continue;
            }

            // valid input
            players[idx].setJerseyNumber(newJerseyNumPar);
            cout << inputName << "'s jersey number is now " << players[idx].getJerseyNumber() << endl;
            break;

        } else {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear(); // clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard bad input
        }
    }
}



void changeAvailability(vector<BaseballPlayers>& players){
    string inputName;
    char newAvailabilityPar;
    cout << "Enter the name of the player who's availability you want to change : ";
    cin >> inputName;
    int idx = searchFunction(inputName, players);
    if (idx != -1) {
        cout << "Is " << inputName << " availabile to play (y/n): ";
        cin >> newAvailabilityPar;
        if (newAvailabilityPar == 'y' || newAvailabilityPar == 'Y'){
            players[idx].setIsAvailable(true);
            cout << inputName << "'s status is now set to available.\n";
        }
        else if (newAvailabilityPar == 'n' || newAvailabilityPar == 'N')
        {
            players[idx].setIsAvailable(false);
            cout << inputName << "'s status is now set to not available.\n";
        }
        else {
            cout <<  "That is not a valid option. Please select either yes or no.\n";
        }
    } else {
        cout << "Player not found.\n";
    }
}

void changeName(vector<BaseballPlayers>& players){
    string inputName;
    string newNamePar;
    cout << "Enter the name of the player who's name you want to change : ";
    cin >> inputName;
    int idx = searchFunction(inputName, players);
    if (idx != -1) {
        cout << "What is the updated replacement name: ";
        cin >> newNamePar;
        players[idx].setFirstName(newNamePar);
        cout << inputName << "'s name has been now updated to " << players[idx].getName() << endl;
    } else {
        cout << "Player not found.\n";
    }
}

void displayTeam (vector<BaseballPlayers>& players) {
    cout << left << setw(10) << "Name"
        << left << setw(10) << "Number"
        << left << setw(10) << "Available\n";
    for(int i = 0; i < players.size(); i++){
        if (players[i].getIsAvailable() == 0) {
            cout << left << setw(10) << players[i].getName()
                << left << setw(10) << players[i].getJerseyNumber()
                << left << setw(10) << "No" << endl;
        }
        else {
            cout << left << setw(10) << players[i].getName()
                << left << setw(10) << players[i].getJerseyNumber()
                << left << setw(10) << "Yes" << endl;
        }
    }
}


int main() {

    //creation of necessary variables
    vector<BaseballPlayers> players;
    int response;
    

    while (true) {
        response = printMenu();

        switch (response) {
            case 1 :
                //add players
                addPlayers(players);
                break;
            case 2 : 
                //remove players
                removePlayers(players);
                break;
            case 3 :
                //change jersey number
                changeNumber(players);
                break;
            case 4 :
                //change availability
                changeAvailability(players);
                break;
            case 5 : 
                //change name
                changeName(players);
                break;
            case 6 : 
                //display team
                displayTeam(players);
                break;
            case 7 :
                //exit program 
                return 0;
            default:
                cout << "That is not a valid choice. Please select a valid option.\n";
                break;
            }
    }
    return 0;
}