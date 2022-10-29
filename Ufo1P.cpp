#include <iostream>
#include "UfoFunc.hpp"

int main() {
  // initialize necessary vairables
  std::string passcode = SPSetup();
  int misses = 0;
  bool end = false;
  std::vector <char> output = StringToVector(passcode);
  

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
