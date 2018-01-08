#include "header.hpp"
#include "wagon.hpp"
#include "material_wagon.hpp"
#include "wagon_for_people.hpp"
#include "train.hpp"
#include "myexceptions.hpp"

//Funkcja sprawdzająca czy został poprawnie wprowadzony pojedynczy znak
bool character_input(char *operation){
  std::string temp;
  // try{
    getline(std::cin, temp);
    switch(temp.size()){
      case 1:{
        (*operation) = temp[0];
        break;
      }
      case 0:{
        throw empty_input();
        break;
      }
      default:{
        throw too_many_signs();
        break;
      }
    }
  // }
  // catch(std::exception & myexcp){
  //   std::cerr << "Exception : \"" << myexcp.what() << "\"" << std::endl;;
  //   // delete myexcp;
  //   return false;
  // }
  return true;
  // switch(temp.size()){
  //   case 1:
  //     (*operation) = temp[0];
  //     return true;
  //   case 0:
  //     std::cout << "Empty line entered." << std::endl;
  //     return false;
  //   default:
  //     std::cout << "More than one sign has been entered." << std::endl;
  //     return false;
  // }
}

//Funkcja sprawdzająca czy wprowadzony poprawnie pojedynczy znak mieści się w wymaganym zakresie
//Funkcja używana wyłącznie do wyboru liczb z zakresu [1, maximum], ewentualnie pojedynczego znaku exception
//Funkcja mająca głównie zastosowanie w wyborze opcji z menu
char correct_character_input(char maximum, char exception){
  char sign;
  bool flag;
  do{
    // flag = character_input(&sign);
    // if(flag){
      try{
        flag = character_input(&sign);
        if(!(sign == exception || (sign <= maximum && sign >= '1'))){
          flag = false;
          throw wrong_sign();
        }
      }
      catch(std::exception & myexcp){
        std::cerr << "Exception : \"" << myexcp.what() << "\"" << std::endl;;
        // delete myexcp;
      }
    // }
  } while(!flag);
  return sign;
}

void add_wagon(train * train_ptr){
  bool exit = false;
  char operation;
  while(!exit){
    std::cout << "1. Add wagon for materials.\n" <<"2. Add wagon for people to created train.\n" << "Type 'q' to exit." << std::endl;
    operation = correct_character_input('2', 'q');
    switch(operation){
      case '1':{
        wagon * wagon_ptr;
        try{
          wagon_ptr = new material_wagon();
        }
        catch(const std::bad_alloc & excp){
          std::cerr << "Exception, bad alloc: \"" << excp.what() << "\"" << std::endl;
          break;
        }
        train_ptr->create_wagon(wagon_ptr);
        break;
      }
      case '2':{
        wagon * wagon_ptr = new wagon_for_people();
        train_ptr->create_wagon(wagon_ptr);
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
  train * train_ptr = new train();
  std::cin >> *train_ptr;
  add_wagon(train_ptr);
  train_contener.push_back(train_ptr);
}

bool find_train(std::vector<train*> &train_contener, train ** train_ptr, std::vector<train*>::iterator &train_itr){
  std::string name;
  std::vector<train*>::iterator it;
  std::cout << "Enter name of the train you are looking for." << std::endl;
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
  std::vector<train*>::const_iterator it = train_contener.begin();
  if(it == train_contener.end()) std::cout << "good    limit: " << train_contener.size() << std::endl;
  for(std::vector<train*>::const_iterator it = train_contener.begin(); it != train_contener.end(); ++it){
    std::cout << **it;
  }
}

void delete_train_wagon(std::vector<train*> &train_contener){
  bool exit = false;
  char operation;
  while(!exit){
    std::cout << "1. Delete train.\n" << "2. Delete wagon.\n" << "Type 'q' to exit." << std::endl;
    operation = correct_character_input('2', 'q');
    switch(operation){
      case '1':{
        train * train_ptr = NULL;
        std::vector<train*>::iterator train_itr = train_contener.begin();
        if(find_train(train_contener, &train_ptr, train_itr)){
          train_contener.erase(train_itr);
          delete train_ptr;
          std::cout << "Train was deleted." << std::endl;
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
