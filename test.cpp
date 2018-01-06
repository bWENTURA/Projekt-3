#include "header.hpp"
#include "train.hpp"

void test(std::vector<train*> &train_contener){
  train * train_ptr;
  std::string input = "noexit";
  while(input != "exit"){
    train_ptr = new train;
    std::cin >> *train_ptr;
    std::cout << *train_ptr;
    getline(std::cin, input);
    train_contener.push_back(train_ptr);
  }
  for(train * iterator: train_contener){
    delete iterator;
  }
}
