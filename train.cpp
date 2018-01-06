#include "header.hpp"
#include "train.hpp"

train::train(int number_person, int number_wagon) : number_of_personnel(number_person), number_of_wagons(number_wagon) {};

train::~train(){
  std::cout << "Destructor!" << std::endl;
}

void train::print(std::ostream& out) const{
  out << LINE << "\n";
  out << "Name: " << this->name << ".\n";
  out << "Description: " << this->description << ".\n";
  out << "Number of personnel: " << this->number_of_personnel << ".\n";
  out << "Number of wagons: " << this->number_of_wagons << ".\n";
  out << LINE << std::endl;
}

std::istream& operator>>(std::istream& in, train& this_train){
  std::cout << "Please enter name of the train." << std::endl;
  getline(in, this_train.name);
  std::cout << "Please enter description of the train." << std::endl;
  getline(in, this_train.description);
  std::cout << "Please enter number of personnel in train." << std::endl;
  in >> this_train.number_of_personnel;
  std::cout << "Please enter number of wagoons in train." << std::endl;
  in >> this_train.number_of_wagons;
  std::cin.clear();
  std::cin.ignore( std::numeric_limits < std::streamsize >::max(), '\n' );
  return in;
}

std::ostream& operator<<(std::ostream& out, const train& this_train){
  this_train.print(out);
  return out;
}
