#include <iostream>
#include <vector>

// Presents game and prompts and saves P1's passcode ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
std::string setup()
{
  // I don't want to write std 5 times.
  using namespace std;
  string passcode;
  
  // showmanship
  cout << "Welcome to UFO Invasion!\n";
  cout << "In this game, Player 1 will create a passcode for Player 2 to guess letters from.";
  cout << "Each letter Player 2 guesses correctly will be shown in the passcode. For each incorrect guess, Player 2 will get closer to abduction.";
  cout << "Player 1 wins after 6 incorrect guesses. Player 2 wins if they fill in the passcode.";
  system("sleep 8");
  cout << "Player 1, please enter your passcode:\n";

  // Passcode input return
  getline(cin,passcode);
  system("clear");
  return passcode;
}


// Takes P1's input and transforms it into a vector for easy rewriting ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
std::vector <char> P1input(std::string passcode)
{
  //initialize
  std::vector <char> output;

  //take input and convert to vector of characters
  for (int i=0; i < passcode.size(); i++){

    if ((passcode[i]==' ') || (passcode[i]=='-') || (passcode[i]=='\'') || (passcode[i]=='!') || (passcode[i]=='.') || (passcode[i]=='?') || (passcode[i]==',') || (passcode[i]==':'))
    {
      output.push_back(passcode[i]);
    }
    else{
      output.push_back('#');
    }
  }
  return output;
  
}


// Test output of passcode with default value ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void testoutput(std::vector <char> output)
{

  for(int i=0; i<output.size(); i++){
    std::cout << output[i];
  }
  std::cout << "\n";
}


// Prompt and write P2 letter guess ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
char P2inp()
{
  char guess;
  std::cout << "Player 2, please input your guess:\n";
  std::cin >> guess;
  return guess;
}


// Check to see if P2's guess was correct ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool guesscorrect(char guess, std::string passcode, std::vector <char> output)
{
  for(int i=0; i<passcode.size(); i++){
    if(guess == passcode[i]){
      return true;
    }
    else if(i+1 == passcode.size()){
      return false;
    }
    else{
      continue;
    }
  }
}


// If P2's guess was correct, update vector to display letter placement ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
std::vector <char> update(char guess, std::string passcode, std::vector <char> output)
{
  for(int i=0; i<passcode.size(); i++){
    if(guess == passcode[i]){
      output[i] = guess;
    }
    else{
      continue;
    }
  }
  return output;
}


// Test if game has ended. Display victory message ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool endtest(int misses, std::string passcode, std::vector <char> output)
{
  int wins = 0;
  for(int i=0; i<passcode.size(); i++){
    if(passcode[i]==output[i]){
      wins++;
    }
    else{
      continue;
    }
  }
  if(wins == passcode.size()){
    std::cout << passcode << "\n";
    std::cout << "Player 2 Wins!";
    return true;
  }
  else if(misses == 6){
    std::cout << passcode << "\n";
    std::cout << "Player 1 Wins!";
    return true;
  }
  else{
    return false;
  }
}


// Displays fun ASCII picture to show UFO progress. Given by codecademy. ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void displaymisses(int misses = 0) {

  if (misses == 0 || misses == 1) {

    std::cout << "                 .                            \n";
    std::cout << "                 |                            \n";
    std::cout << "              .-\"^\"-.                       \n";
    std::cout << "             /_....._\\                       \n";
    std::cout << "         .-\"`         `\"-.                  \n";
    std::cout << "        (  ooo  ooo  ooo  )                   \n";
    std::cout << "         '-.,_________,.-'    ,-----------.   \n";
    std::cout << "              /     \\        (  Send help! ) \n";
    std::cout << "             /   0   \\      / `-----------'  \n";
    std::cout << "            /  --|--  \\    /                 \n";
    std::cout << "           /     |     \\                     \n";
    std::cout << "          /     / \\     \\                   \n";
    std::cout << "         /               \\                   \n";

  }
  else if (misses == 2) {

    std::cout << "                 .                            \n";
    std::cout << "                 |                            \n";
    std::cout << "              .-\"^\"-.                       \n";
    std::cout << "             /_....._\\                       \n";
    std::cout << "         .-\"`         `\"-.                  \n";
    std::cout << "        (  ooo  ooo  ooo  )                   \n";
    std::cout << "         '-.,_________,.-'    ,-----------.   \n";
    std::cout << "              /  0  \\        (  Send help! ) \n";
    std::cout << "             / --|-- \\      / `-----------'  \n";
    std::cout << "            /    |    \\    /                 \n";
    std::cout << "           /    / \\    \\                    \n";
    std::cout << "          /             \\                    \n";
    std::cout << "         /               \\                   \n";

  }
  else if (misses == 3) {

    std::cout << "                 .                            \n";
    std::cout << "                 |                            \n";
    std::cout << "              .-\"^\"-.                       \n";
    std::cout << "             /_....._\\                       \n";
    std::cout << "         .-\"`         `\"-.                  \n";
    std::cout << "        (  ooo  ooo  ooo  )                   \n";
    std::cout << "         '-.,_________,.-'    ,-----------.   \n";
    std::cout << "              /--|--\\        (  Send help! ) \n";
    std::cout << "             /   |   \\      / `-----------'  \n";
    std::cout << "            /   / \\   \\    /                \n";
    std::cout << "           /           \\                     \n";
    std::cout << "          /             \\                    \n";
    std::cout << "         /               \\                   \n";

  }
  else if (misses == 4) {

    std::cout << "                 .                            \n";
    std::cout << "                 |                            \n";
    std::cout << "              .-\"^\"-.                       \n";
    std::cout << "             /_....._\\                       \n";
    std::cout << "         .-\"`         `\"-.                  \n";
    std::cout << "        (  ooo  ooo  ooo  )                   \n";
    std::cout << "         '-.,_________,.-'    ,-----------.   \n";
    std::cout << "              /  |  \\        (  Send help! ) \n";
    std::cout << "             /  / \\  \\      / `-----------' \n";
    std::cout << "            /         \\    /                 \n";
    std::cout << "           /           \\                     \n";
    std::cout << "          /             \\                    \n";
    std::cout << "         /               \\                   \n";

  }
  else if (misses == 5) {

    std::cout << "                 .                            \n";
    std::cout << "                 |                            \n";
    std::cout << "              .-\"^\"-.                       \n";
    std::cout << "             /_....._\\                       \n";
    std::cout << "         .-\"`         `\"-.                  \n";
    std::cout << "        (  ooo  ooo  ooo  )                   \n";
    std::cout << "         '-.,_________,.-'    ,-----------.   \n";
    std::cout << "              / / \\ \\        (  Send help! )\n";
    std::cout << "             /       \\      / `-----------'  \n";
    std::cout << "            /         \\    /                 \n";
    std::cout << "           /           \\                     \n";
    std::cout << "          /             \\                    \n";
    std::cout << "         /               \\                   \n";

  }
  else if (misses == 6) {

    std::cout << "                 .                            \n";
    std::cout << "                 |                            \n";
    std::cout << "              .-\"^\"-.                       \n";
    std::cout << "             /_....._\\                       \n";
    std::cout << "         .-\"`         `\"-.                  \n";
    std::cout << "        (  ooo  ooo  ooo  )                   \n";
    std::cout << "         '-.,_________,.-'    ,-----------.   \n";
    std::cout << "              /     \\        (  Send help! ) \n";
    std::cout << "             /       \\      / `-----------'  \n";
    std::cout << "            /         \\    /                 \n";
    std::cout << "           /           \\                     \n";
    std::cout << "          /             \\                    \n";
    std::cout << "         /               \\                   \n";

  }

}
