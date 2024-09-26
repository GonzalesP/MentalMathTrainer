#include <cctype>
#include <iostream>
#include <random>
#include <string>

std::string stringToLowercase(std::string str) {
  std::string lowerStr = "";
  for (int charIndex = 0; charIndex < str.length(); charIndex++) {
    lowerStr += std::tolower(str[charIndex]);
  }

  return lowerStr;
}

int choiceToInt(std::string choice) {
  // "clean up" word
  choice = stringToLowercase(choice);

  if (choice == "rock")
    return 0;
  else if (choice == "paper")
    return 1;
  else if (choice == "scissors")
    return 2;
  else
    return -1;
}

// int getRandomChoice() {
//   std::default_random_engine generator;
//   std::uniform_int_distribution<int> distribution(0,2);
//   int choice = distribution(generator);

//   return choice;
// }

int main() {
  std::string userInput = "";

  std::cin >> userInput;
  std::cout << choiceToInt(userInput) << std::endl;

  return 0;
}