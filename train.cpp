#include "header.hpp"
#include "wagon.hpp"
#include "train.hpp"

train::train(int number_person, int number_wagon) : number_of_personnel(number_person), number_of_wagons(number_wagon) {}

train::~train(){
  std::cout << "Destructor!" << std::endl;
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

void train::add_wagon(wagon* new_wagon){
  this->lwagons.push_back(new_wagon);
  this->increase_number();
}

std::istream& operator>>(std::istream& in, train& this_train){
  std::cout << "Please enter name of the train." << std::endl;
  getline(in, this_train.name);
  std::cout << "Please enter description of the train." << std::endl;
  getline(in, this_train.description);
  in.exceptions(in.failbit);
  do{
    try{
      if(!in){
        std::cout << "Please enter number of personnel again." << std::endl;
        in.clear();
        std::cout << " there it is!" << std::endl;
        in.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
      }
      else std::cout << "Please enter number of personnel in train." << std::endl;
      in >> this_train.number_of_personnel;
    }
    catch(std::exception& exception){
      std::cout << "Exception happened: \"" << exception.what() << "\"" << std::endl;
      std::cout << "Try again." << std::endl;
    }
  } while(!in);
  in.clear();
  in.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
  return in;
}

std::ostream& operator<<(std::ostream& out, const train& this_train){
  out << LINE << "\n";
  out << "Name: " << this_train.name << ".\n";
  out << "Description: " << this_train.description << ".\n";
  out << "Number of personnel: " << this_train.number_of_personnel << ".\n";
  out << "Number of wagons: " << this_train.number_of_wagons << ".\n";
  if(this_train.lwagons.size()){
    for(std::list<wagon*>::const_iterator it = this_train.lwagons.begin(); it != this_train.lwagons.end(); ++it){
      out << **it;
    }
    // for(wagon * iterator : this_train.lwagons){
    //   out << *iterator;
    // }
  }
  else out << LINE << std::endl;
  return out;
}
