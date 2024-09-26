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

std::string intToChoice(int input) {
  if (input == 0)
    return "rock";
  else if (input == 1)
    return "paper";
  return "scissors";
}

int main() {
  std::default_random_engine generator;
  std::uniform_int_distribution<int> distribution(0,2);

  // userInput (rows) vs. botInput (columns)
  // indices: rock - paper - scissors
  int resultMatrix[3][3] = {{0, -1, 1},
                            {1, 0, -1},
                            {-1, 1, 0}};

  std::string userInput = "";
  
  while (stringToLowercase(userInput) != "exit") {
    std::cout << "Enter your choice:" << std::endl;
    std::cin >> userInput;

    if (stringToLowercase(userInput) == "exit") {
      std::cout << "See ya!" << std::endl;
    }
    else {
      int userChoice = choiceToInt(userInput);
      if (userChoice == -1) {
        std::cout << userInput << " is not a valid choice!" << std::endl << std::endl;
      }
      else {
        int botChoice = distribution(generator);
        std::cout << "The bot chose " << intToChoice(botChoice) << "." << std::endl;

        int result = resultMatrix[userChoice][botChoice];
        if (result == -1) {
          std::cout << "DEFEAT" << std::endl;
        }
        else if (result == 0) {
          std::cout << "TIE" << std::endl;
        }
        else {
          std::cout << "VICTORY" << std::endl;
        }
        std::cout << std::endl;
      }
    }
  }


  return 0;
}