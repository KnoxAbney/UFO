#include <iostream>
#include "ufo_functions.hpp"

int main() {
  // initialize necessary vairables
  std::string passcode = setup();
  int misses = 0;
  bool end = false;
  std::vector <char> output = P1input(passcode);
  

  // Performs main task using functions defined in "UfoFunc.cpp" and declared in UfoFunc.hpp ~~~~~~~~~~~~~~~~~
  while(end != true){
    testoutput(output);
    char guess = P2inp();
    bool correct = guesscorrect(guess, passcode, output);
    system("clear");
    if(correct == true){
      output = update(guess, passcode, output);
    } 
    else{
      misses++;
      displaymisses(misses);
    }
    end = endtest(misses, passcode, output);
  }
}
