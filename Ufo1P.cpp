#include <iostream>
#include "UfoFunc.hpp"

int main() {
  // initialize necessary vairables
  
  int misses = 0;
  bool end = false;
  std::vector <std::string> guesses = {" "};

  // Chooses random passcode from prewritten set of 100 options ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  std::string passcode = SPSetup();

  // Changes passcode to vector that can be rewritten ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  std::vector <char> output = StringToVector(passcode);
  

  // Performs main task using functions defined in "UfoFunc.cpp" and declared in UfoFunc.hpp ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  while(end != true){
    printoutput1(output);

    // Asks for next guess, adds to guess list, and checks for correctness ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    std::string guess = P2inp();
    guesses = GuessesUpdate(guess, guesses);
    bool correct = guesscorrect(guess, passcode, output);

    // Allows for guesses of entire phrase ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    if((guess.size() != 1) && (correct == true)){
      system("clear");
      std::cout << passcode << "\n";
      std::cout << "The humans win!";
      break;
    }

    //clears and resets previous guess printout for next guess ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    system("clear");
    std::cout << "Guesses so far:";
    printoutput2(guesses);

    // checks for correctness and updates output or misses counter accordingly ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    if(correct == true){
      output = update(guess, passcode, output);
    } 
    else{
      misses++;
      displaymisses(misses);
    }
    
    // checks for a win condition and ends the program if one is met ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    end = endtest(misses, passcode, output);
  }
}
