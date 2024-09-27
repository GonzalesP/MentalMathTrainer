#include <iostream>
#include <random>
#include <string>

int main() {
  std::default_random_engine generator;
  std::uniform_int_distribution<int> distribution(0, 9);
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