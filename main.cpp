#include "header.hpp"
#include "wagon.hpp"
#include "material_wagon.hpp"
#include "wagon_for_people.hpp"
#include "train.hpp"
#include "functions.hpp"

int main(){
  std::vector<train*> train_contener;
  bool exit = false;
  char operation;
  while(exit != true){
    std::cout << "Please enter the number of the operation you want to execute.\n" << "1. Create train.\n" << "2. Create wagon.\n" << "3. Show trains.\n" << "Type 'q' to exit." << std::endl;
    operation = correct_character_input('3', 'q');
    switch(operation){
      case '1':{
        add_train(train_contener);
        break;
      }
      case '2':{
        find_train(train_contener);
        break;
      }
      case '3':{
        show_trains(train_contener);
        break;
      }
      case 'q':
        exit = true;
        break;
    }
  }
  for(std::vector<train*>::iterator it = train_contener.begin(); it != train_contener.end(); ++it){
    delete *it;
  }
  return 0;
}
