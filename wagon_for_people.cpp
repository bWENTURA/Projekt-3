#include "header.hpp"
#include "input_functions.hpp"
#include "wagon.hpp"
#include "wagon_for_people.hpp"

wagon_for_people::wagon_for_people(unsigned int number, unsigned int number_of_sitting_places, bool place_for_bikes, bool restaurant) : number(number), number_of_sitting_places(number_of_sitting_places), place_for_bikes(place_for_bikes), restaurant(restaurant) {}

wagon_for_people::~wagon_for_people() {}

void wagon_for_people::get_number_of_sitting_places(std::istream& in, unsigned int & number){
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

void wagon_for_people::set_number(unsigned int number){
  this->number = number;
}

void wagon_for_people::get_info(std::istream& in){
  char operation;
  std::cout << "Please enter number of sitting places." << std::endl;
  this->get_number_of_sitting_places(in, this->number_of_sitting_places);
  std::cout << "1. Wagon has space for bikes.\n" << "2. Wagon hasn't got space for bikes." << std::endl;
  operation = correct_character_input('2');
  switch(operation){
    case '1':{
      this->place_for_bikes = true;
      break;
    }
    case '2':{
      this->place_for_bikes = false;
      break;
    }
  }
  std::cout << "1. Wagon has restaurant.\n" << "2. Wagon hasn't got restaurant." << std::endl;
  operation = correct_character_input('2');
  switch(operation){
    case '1':{
      this->restaurant = true;
      break;
    }
    case '2':{
      this->restaurant = false;
      break;
    }
  }
}

void wagon_for_people::print_info(std::ostream& out) const{
  out << LINE << "\n";
  out << "Number of wagon: " << this->number << ".\n";
  out << "Number of sitting places: " << this->number_of_sitting_places << ".\n";
  if(this->place_for_bikes) out << "Wagon has place for bikes." << "\n";
  else out << "Wagon hasn't got place for bikes." << "\n";
  if(this->restaurant) out << "Wagon has restaurant." << std::endl;
  else out << "Wagon hasn't got restaurant." << std::endl;
}

std::string wagon_for_people::get_class(){
  std::string class_name = "People";
  return class_name;
}
