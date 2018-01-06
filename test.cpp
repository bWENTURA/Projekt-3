#include "header.hpp"
#include "wagon.hpp"
#include "train.hpp"

void test(std::vector<train*> &train_contener){
  train * train_ptr;
  wagon * wagon_ptr;
  std::string input = "noexit";
  while(input != "exit"){
    train_ptr = new train;
    std::cin >> *train_ptr;
    while(input != "exit"){
      
    }
    std::cout << *train_ptr;
    std::cout << "Type \"exit\" to exit loop of creating trains." << std::endl;
    getline(std::cin, input);
    train_contener.push_back(train_ptr);
  }
  for(train * iterator: train_contener){
    delete iterator;
  }
}
