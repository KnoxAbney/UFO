#include <iostream>
#include "tttFunc.hpp"

int main() {
  // initialize necessary vairables~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  std::string passcode = SPSetup();
  int misses = 0;
  bool end = false;
  std::vector <char> output = StringToVector(passcode);
  std::vector <char> guesses = {' '};
  

  // Performs main task using functions defined in "UfoFunc.cpp" and declared in UfoFunc.hpp ~~~~~~~~~~~~~~~~~
  while(end != true){
    int i = 0;
    printoutput(output);
    char guess = P2inp();
    guesses = GuessesUpdate(guess, guesses);
    bool correct = guesscorrect(guess, passcode, output);
    system("clear");
    std::cout << "Guesses so far:";
    printoutput(guesses);
    if(correct == true){
      output = update(guess, passcode, output);
    } 
    else{
      misses++;
      displaymisses(misses);
    }
    end = endtest(misses, passcode, output);
    i++;
  }
}
