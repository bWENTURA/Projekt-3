#include "header.hpp"
#include "input_functions.hpp"
#include "wagon.hpp"
#include "material_wagon.hpp"
#include "wagon_for_people.hpp"
#include "train.hpp"
#include "main_functions.hpp"

int main(){
  std::vector<train*> train_contener;
  bool exit = false;
  char operation;
  while(exit != true){
    std::cout << "Please enter the number of the operation you want to execute.\n" << "1. Create train.\n" << "2. Create wagon.\n" << "3. Show trains.\n" << "4. Delete train or wagon.\n" << "5. Edit train or wagon info.\n" << "6. Sort trains.\n" << "Type 'q' to exit.\n" << LINE << std::endl;
    operation = correct_character_input('6', 'q');
    switch(operation){
      case '1':{
        add_train(train_contener);
        break;
      }
      case '2':{
        if(train_contener.size()){
          train * train_ptr = NULL;
          std::vector<train*>::iterator train_itr = train_contener.end();
          if(find_train(train_contener, &train_ptr, train_itr)){
            add_wagon(train_ptr);
          }
        }
        else std::cout << LINE << "\nTrain contener is empty.\n" << LINE << std::endl;
        break;
      }
      case '3':{
        if(train_contener.size()){
          show_trains(train_contener);
        }
        else std::cout << LINE << "\nTrain contener is empty.\n" << LINE << std::endl;
        break;
      }
      case '4':{
        if(train_contener.size()){
          delete_train_wagon(train_contener);
        }
        else std::cout << LINE << "\nTrain contener is empty.\n" << LINE << std::endl;
        break;
      }
      case '5':{
        if(train_contener.size()){
          edit_train_wagon(train_contener);
        }
        else std::cout << LINE << "\nTrain contener is empty.\n" << LINE << std::endl;
        break;
      }
      case '6':{
        if(train_contener.size()){
          sort_trains(train_contener);
        }
        else std::cout << LINE << "\nTrain contener is empty.\n" << LINE << std::endl;
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
