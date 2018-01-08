#include "header.hpp"
#include "input_functions.hpp"
#include "wagon.hpp"
#include "material_wagon.hpp"
#include "wagon_for_people.hpp"
#include "train.hpp"
#include "main_functions.hpp"

void add_wagon(train * train_ptr){
  bool exit = false;
  char operation;
  while(!exit){
    std::cout << LINE << "\n1. Add wagon for materials.\n" <<"2. Add wagon for people to created train.\n" << "Type 'q' to exit.\n" << LINE << std::endl;
    operation = correct_character_input('2', 'q');
    switch(operation){
      case '1':{
        try{
          wagon * wagon_ptr = new material_wagon();
          train_ptr->create_wagon(wagon_ptr);
        }
        catch(const std::bad_alloc & excp){
          std::cerr << "Exception, bad alloc: \"" << excp.what() << "\"" << std::endl;
        }
        break;
      }
      case '2':{
        try{
          wagon * wagon_ptr = new wagon_for_people();
          train_ptr->create_wagon(wagon_ptr);
        }
        catch(const std::bad_alloc & excp){
          std::cerr << "Exception, bad alloc: \"" << excp.what() << "\"" << std::endl;
        }
        break;
      }
      case 'q':{
        exit = true;
        break;
      }
    }
  }
}

void add_train(std::vector<train*> &train_contener){
  try{
    train * train_ptr = new train();
    std::cin >> *train_ptr;
    add_wagon(train_ptr);
    train_contener.push_back(train_ptr);
  }
  catch(const std::bad_alloc & excp){
    std::cerr << "Exception, bad alloc: \"" << excp.what() << "\"" << std::endl;
  }
}

bool find_train(std::vector<train*> &train_contener, train ** train_ptr, std::vector<train*>::iterator &train_itr){
  std::string name;
  std::vector<train*>::iterator it;
  std::cout << LINE << "\nEnter name of the train you are looking for.\n" << LINE << std::endl;
  getline(std::cin, name);
  for(it = train_contener.begin(); it != train_contener.end(); ++it){
    if((*it)->get_name() == name){
      *train_ptr = *it;
      if(train_itr != train_contener.end()) train_itr = it;
      return true;
    }
  }
  std::cout << LINE << "\nProgram couldn't find train with name \"" << name << "\".\n" << LINE << std::endl;
  return false;
}

void show_trains(const std::vector<train*> &train_contener){
  for(std::vector<train*>::const_iterator it = train_contener.begin(); it != train_contener.end(); ++it){
    std::cout << **it;
  }
}

void delete_train_wagon(std::vector<train*> &train_contener){
  bool exit = false;
  char operation;
  while(!exit){
    std::cout << LINE << "\n1. Delete train.\n" << "2. Delete wagon.\n" << "Type 'q' to exit.\n" << LINE << std::endl;
    operation = correct_character_input('2', 'q');
    switch(operation){
      case '1':{
        train * train_ptr = NULL;
        std::vector<train*>::iterator train_itr = train_contener.begin();
        if(find_train(train_contener, &train_ptr, train_itr)){
          train_contener.erase(train_itr);
          std::cout << LINE << "\nTrain \"" << train_ptr->get_name() << "\" was deleted.\n" << LINE << std::endl;
          delete train_ptr;
          break;
        }
        break;
      }
      case '2':{
        train * train_ptr = NULL;
        std::vector<train*>::iterator train_itr = train_contener.end();
        if(find_train(train_contener, &train_ptr, train_itr)){
          std::cout << *train_ptr;
          train_ptr->delete_wagon();
        }
        break;
      }
      case 'q':{
        exit = true;
        break;
      }
    }
  }
}
