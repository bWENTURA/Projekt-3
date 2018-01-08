#include "header.hpp"
#include "wagon.hpp"
#include "train.hpp"

train::train(int number_person, int number_wagon) : number_of_personnel(number_person), number_of_wagons(number_wagon) {}

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

bool train::get_number(std::istream& in, int &number){
  in.exceptions(in.failbit);
  try{
    in >> number;
  }
  catch(std::exception& exception){
    std::cerr << "Exception happened: \"" << exception.what() << "\"" << std::endl;
    in.clear();
    in.ignore(std::numeric_limits<std::streamsize >::max(), '\n');
    return false;
  }
  return true;
}

std::string train::get_name(){
  return this->name;
}

void train::create_wagon(wagon* new_wagon){
  std::cin >> *new_wagon;
  this->lwagons.push_back(new_wagon);
  this->increase_number();
  new_wagon->set_number(this->number_of_wagons);
  // std::cout << *new_wagon;
}

void train::delete_wagon(){
  int number, temp_number = 0;
  std::list<wagon*>::iterator it;
  std::cout << "Enter number of the wagon you want to delete." << std::endl;
  while(!this->get_number(std::cin, number)){
    std::cout << "Enter the number again." << std::endl;
  }
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
        break;
      }
    }
  }
  else std::cout << "Wrong number has been entered." << std::endl;
}

std::istream& operator>>(std::istream& in, train& this_train){
  std::cout << "Please enter name of the train." << std::endl;
  getline(in, this_train.name);
  std::cout << "Please enter description of the train." << std::endl;
  getline(in, this_train.description);
  std::cout << "Please enter number of personnel in train." << std::endl;
  while(!this_train.get_number(in, this_train.number_of_personnel)){
    std::cout << "Please enter number of personnel again." << std::endl;
  }
  in.clear();
  in.ignore(std::numeric_limits<std::streamsize >::max(), '\n');
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
