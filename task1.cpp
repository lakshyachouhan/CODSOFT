/*   TASK 1 - GUESSING NUMBER GAME 
Create a program that generates a random number and asks the
 user to guess it. Provide feedback on whether the guess is too
 high or too low until the user guesses the correct number.
*/
/* NAME - LAKSHYA CHOUHAN
   ID: CS07WX75038         */
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

void startprint(){
    cout<<endl ;
    cout<<"         ----------------------------------"<<endl;
    cout<<"         |           GUESSING THE         |"<<endl;
    cout<<"         |              NUMBER            |"<<endl;
    cout<<"         |               GAME             |"<<endl;
    cout<<"         ----------------------------------"<<endl;
}


int main(){
    startprint();   

    srand(static_cast<unsigned>(time(0))); // Seed the random number generator with current time 
    /* time(0) is used to obtain the current time so that each time 
    random number generated should be different */

    int minRange = 1;  // Minimum range
    int maxRange = 100; // Maximum range

    int secretNumber = rand() % (maxRange - minRange + 1) + minRange;
    
    int guess;
    int attempts = 0;

    cout <<"You will be provided a number between "<<minRange<< " and "<<maxRange << "." <<endl ;
    cout <<"Try to guess it " << endl;

    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess < secretNumber) {
            cout << "Too low! Try again." << endl;
        } else if (guess > secretNumber) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congrats! You guessed the number (" << secretNumber << ") in " << attempts << " attempts." << endl;
        }

    } while (guess != secretNumber);    

    return 0;
}