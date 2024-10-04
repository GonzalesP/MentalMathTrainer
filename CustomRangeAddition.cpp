#include <iostream>
#include <random>
#include <string>

int main() {
  int minRange = 0, maxRange = 0;
  std::cout << "Enter the range of numbers you want to practice with:" << std::endl;

  std::cout << "Smallest value: ";
  if (!(std::cin >> minRange)) {
    std::cout << "Invalid value. Exiting program." << std::endl;
    return -1;
  }

  std::cout << std::endl << "Largest value: ";
  if (!(std::cin >> maxRange)) {
    std::cout << "Invalid value. Exiting program." << std::endl;
    return -1;
  }

  std::default_random_engine generator;
  std::uniform_int_distribution<int> distribution(minRange, maxRange);
  int userAnswer = 0, leftVar = 0, rightVar = 0;

  leftVar = distribution(generator);
  rightVar = distribution(generator);

  std::cout << "What is " << leftVar << " + " << rightVar << "?" << std::endl;
  while(std::cin >> userAnswer) {
    if (userAnswer == leftVar + rightVar) {
      std::cout << "That is correct!" << std::endl;
    }
    else {
      std::cout << "Incorrect. The answer was " << leftVar + rightVar << "." << std::endl;
    }
    
    leftVar = distribution(generator);
    rightVar = distribution(generator);
    std::cout << "What is " << leftVar << " + " << rightVar << "?" << std::endl;
  }

  std::cout << "Goodbye." << std::endl;

  return 0;
}