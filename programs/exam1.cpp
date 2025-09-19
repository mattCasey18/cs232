#include <iostream>
using namespace std;

//create a program that prompts the user for a distance and a time, then calculates and displays the speed in miles per hour
/* Parameters:
    distancePar (double) – represents miles entered by the user
    timePar (double) -represents hours entered by the user
    returns a double
    returns the result of distancePar divided by timePar
    no formatting required
*/

double findSpeed(double distancePar, double timePar) {
    return distancePar / timePar;
}

int main() {
    double distance = 0.0;
    double time = 0.0;
    double speed = 0.0;

    cout << "Enter distance in miles: ";
    cin >> distance;

    cout << "Enter time in hours: ";
    cin >> time;

    speed = findSpeed(distance, time);

    cout << "Speed is " << speed << " miles per hour." << endl;

    return 0;
}