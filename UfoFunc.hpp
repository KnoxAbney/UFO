#include <vector>

// So many declarations
void displaymisses(int misses);
std::string setup();
std::vector <char> StringToVector(std::string passcode);
void printoutput1(std::vector <char> output);
void printoutput2(std::vector <std::string> output);
std::string P2inp();
std::vector <std::string> GuessesUpdate(std::string guess, std::vector <std::string> guesses);
bool guesscorrect(std::string guess, std::string passcode, std::vector <char> output);
std::vector <char> update(std::string guess, std::string passcode, std::vector <char> output);
bool endtest(int misses, std::string passcode, std::vector <char> output);
std::string SPSetup();
