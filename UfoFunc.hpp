#include <vector>

// So many declarations
void displaymisses(int misses);
std::string setup();
std::vector <char> StringToVector(std::string passcode);
void printoutput(std::vector <char> phrase);
char P2inp();
std::vector <char> GuessesUpdate(char guess, std::vector <char> guesses);
bool guesscorrect(char guess, std::string passcode, std::vector <char> output);
std::vector <char> update(char guess, std::string passcode, std::vector <char> output);
bool endtest(int misses, std::string passcode, std::vector <char> output);
std::string SPSetup();
