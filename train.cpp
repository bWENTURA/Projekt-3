#include "header.hpp"
#include "input_functions.hpp"
#include "wagon.hpp"
#include "train.hpp"

train::train(unsigned int number_person, unsigned int number_wagon) : number_of_personnel(number_person), number_of_wagons(number_wagon) {}

train::~train(){
  for(wagon * iterator: this->lwagons){
    delete iterator;
  }
}

void train::increase_number(){
  this->number_of_wagons++;
}

void train::decrease_number(){
  this->number_of_wagons--;
}

void train::get_number(std::istream& in, unsigned int &number){
  std::string temp;
  while(1){
    try{
      correct_string(in, temp);
      unsigned_int_check(temp);
      number = stoi(temp);
      break;
    }
    catch(std::exception& exception){
      std::cerr << "Exception happened: \"" << exception.what() << "\"" << std::endl;
    }
  }
}

bool train::empty(){
  if(this->number_of_wagons) return false;
  return true;
}

void train::edit_info(){
  std::cin >> *this;
}

void train::edit_wagon_info(){
  unsigned int number, temp_number = 1;
  std::cout << *this;
  std::cout << "Please enter number of wagon you want to edit." << std::endl;
  this->get_number(std::cin, number);
  if(number <= this->number_of_wagons){
    for(std::list<wagon*>::iterator it = this->lwagons.begin(); it != this->lwagons.end(); ++it){
      if(temp_number == number){
        (*it)->get_info(std::cin);
        std::cout << LINE << "\nWagon has been edited.\n" << LINE << std::endl;
        break;
      }
      temp_number++;
    }
  }
  else std::cout << "Wrong number has been entered." << std::endl;
}

std::string train::get_name(){
  return this->name;
}

int train::get_number_of_wagons(){
  return this->number_of_wagons;
}

void train::create_wagon(wagon* new_wagon){
  std::cin >> *new_wagon;
  this->increase_number();
  if(new_wagon->get_class() == "People"){
    int number = 1;
    this->lwagons.push_front(new_wagon);
    for(std::list<wagon*>::iterator it = this->lwagons.begin(); it != this->lwagons.end(); ++it){
      (*it)->set_number(number);
      number++;
    }
  }
  else{
    this->lwagons.push_back(new_wagon);
    new_wagon->set_number(this->number_of_wagons);
  }
}

void train::delete_wagon(){
  unsigned int number, temp_number = 0;
  std::list<wagon*>::iterator it;
  std::cout << *this;
  std::cout << "Enter number of the wagon you want to delete." << std::endl;
  this->get_number(std::cin, number);
  if(number <= this->number_of_wagons){
    for(it = this->lwagons.begin(); it != this->lwagons.end(); ++it){
      temp_number++;
      if(temp_number == number){
        temp_number--;
        for(std::list<wagon*>::iterator other = it; other != this->lwagons.end(); ++other){
          (*other)->set_number(temp_number);
          temp_number++;
        }
        wagon * wagon_ptr = *it;
        this->lwagons.remove(*it);
        delete wagon_ptr;
        this->decrease_number();
        std::cout << LINE << "\nWagon has been deleted.\n" << LINE << std::endl;
        break;
      }
    }
  }
  else std::cout << "Wrong number has been entered." << std::endl;
}

std::istream& operator>>(std::istream& in, train& this_train){
  std::cout << "Please enter name of the train." << std::endl;
  correct_string(in, this_train.name);
  std::cout << "Please enter description of the train." << std::endl;
  correct_string(in, this_train.description);
  std::cout << "Please enter number of personnel in train." << std::endl;
  this_train.get_number(in, this_train.number_of_personnel);
  return in;
}

std::ostream& operator<<(std::ostream& out, const train& this_train){
  out << TRAIN_LINE << "\n";
  out << "Name: " << this_train.name << ".\n";
  out << "Description: " << this_train.description << ".\n";
  out << "Number of personnel: " << this_train.number_of_personnel << ".\n";
  out << "Number of wagons: " << this_train.number_of_wagons << ".\n";
  if(this_train.lwagons.size()){
    for(std::list<wagon*>::const_iterator it = this_train.lwagons.begin(); it != this_train.lwagons.end(); ++it){
      out << **it;
    }
  }
  out << TRAIN_LINE << std::endl;
  return out;
}
