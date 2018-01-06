#include "header.hpp"
#include "wagon.hpp"
#include "material_wagon.hpp"
#include "train.hpp"

void test(std::vector<train*> &train_contener){
  train * train_ptr;
  wagon * wagon_ptr;
  std::string input = "noexit";
  while(input != "exit"){
    train_ptr = new train;
    std::cin >> *train_ptr;
    while(input != "exit"){
      std::cout << "1. Wagon for materials." << "\n";
      std::cout << "2. Wagon for people." << std::endl;
      int number;
      std::cin >> number;
      std::cin.clear();
      std::cin.ignore( std::numeric_limits < std::streamsize >::max(), '\n' );
      switch(number){
        case 1:{
          wagon_ptr = new material_wagon;
          std::cin >> *wagon_ptr;
          std::cout << *wagon_ptr;
          train_ptr->add_wagon(wagon_ptr);
          break;
        }
        case 2:{

          break;
        }
      }
      std::cout << "Type \"exit\" to exit loop of creating wagons." << std::endl;
      getline(std::cin, input);
    }
    std::cout << *train_ptr;
    std::cout << "Type \"exit\" to exit loop of creating trains." << std::endl;
    getline(std::cin, input);
    train_contener.push_back(train_ptr);
  }

  for(train * iterator: train_contener){
    std::cout << *iterator;
    delete iterator;
  }
}
