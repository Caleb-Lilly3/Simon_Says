/*********************************************************
* Summary: Play Simon Says :)
*
* Author:Caleb Lilly
* Created:9/23/26
*
********************************************************/

#include <iostream>                     // for I/O
#include <cstring>                      // for strlen()
#include <cstdlib>                      // for random numbers
#include <unistd.h>                     // for sleep()

using namespace std;

int main(int argc, char **argv) {

   string    end;
	
   while (end != "done"){
	
   const int DEFAULT_NUMBER_OF_ROUNDS = 15;
   int       numRounds = DEFAULT_NUMBER_OF_ROUNDS;

   // if a command line argument is given, use that string to init the
   // "random" sequence and set the number of rounds to play the game
   if (argc == 2) {
      numRounds = strlen(argv[1]);
   }
	   
   string    s;                         // A string used to pause the game
   string    c;                         // The player's typed characters
   char     *seq = new char[numRounds]; // Sequence of numRounds colors to match
   char      colors[] = "RGBY";         // Allowable colors
   bool      lost = false;              // Indicates whether we win or lose
   int       round;                     // Indicates the current round

   // Initialize random number generator
   srand(time(0));

   // Determine the random color sequence using either argv[1] or
   // randomly determined letters from 'R', 'G', 'B', and 'Y'
   for (int j = 0; j < numRounds; j++) {
      seq[j] = (argc == 2) ? argv[1][j] : colors[rand() % 4];
   }

   // Wait until the player is ready
   cout << "Welcome to Simon, press enter to play .... ";
   getline(cin, s, '\n');

	round = 1; //Makes sure round starts at 1
	
	//loops the program for a set number of rounds or untill player loses
	for (int i = 0; (i < numRounds) && (lost != true); ++i){
		s = s + seq[i];                   //creats a string using seq[num]
		system("cls");          //clears screen
		cout << "Simon says: " << flush;
		for(int j = 0; j <= i; ++j){
			cout << seq[j] << flush;
			sleep(1);
			cout << "\010." << flush;      //Backspace and print "."
		}
		cout << endl;
		cout << "Please enter " << round << " characters to match: ";
		cin >> c;
		if( c != s){                      //sets lost to true if player puts in wrong letters
		lost = true;
		}
		++round;                          //Make sure round incress by 1
	}

	//if and else statments for winning or losing the game
	if (lost == false){
	cout << endl << "Congratulations, you win!!" << endl;
	}
	else{
	cout << endl << "Aww, you lost." << endl;
	cout << "The correct sequence was: " << s << endl;
	}

	sleep(1);
	cout << "Type start to play again or type done to close the program" << endl;
	cin >> end;
	}
   return 0;
}
