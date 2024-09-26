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

int main() {
  std::default_random_engine generator;
  std::uniform_int_distribution<int> distribution(0,2);

  // std::string userInput = "";
  // std::cin >> userInput;
  // std::cout << choiceToInt(userInput) << std::endl;

  for (int i = 0; i < 20; i++) {
    int choice = distribution(generator);
    std::cout << choice << std::endl;
  }

  return 0;
}