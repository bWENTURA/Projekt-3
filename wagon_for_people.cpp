#include "header.hpp"
#include "input_functions.hpp"
#include "wagon.hpp"
#include "wagon_for_people.hpp"

wagon_for_people::wagon_for_people(int number, int number_of_sitting_places, bool place_for_bikes, bool restaurant) : number(number), number_of_sitting_places(number_of_sitting_places), place_for_bikes(place_for_bikes), restaurant(restaurant) {}

wagon_for_people::~wagon_for_people() {}

bool wagon_for_people::get_number_of_sitting_places(std::istream& in){
  in.exceptions(in.failbit);
  try{
    in >> this->number_of_sitting_places;
  }
  catch(std::exception& exception){
    std::cerr << "Exception happened: \"" << exception.what() << "\"" << std::endl;
    in.clear();
    in.ignore(std::numeric_limits<std::streamsize >::max(), '\n');
    return false;
  }
  in.clear();
  in.ignore(std::numeric_limits<std::streamsize >::max(), '\n');
  return true;
}

void wagon_for_people::set_number(int number){
  this->number = number;
}

void wagon_for_people::get(std::istream& in){
  char operation;
  std::cout << "Please enter number of sitting places." << std::endl;
  while(!this->get_number_of_sitting_places(in)){
    std::cout << "Please enter number of sitting places again." << std::endl;
  }
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

void wagon_for_people::print(std::ostream& out) const{
  out << LINE << "\n";
  out << "Number of wagon: " << this->number << ".\n";
  out << "Number of sitting places: " << this->number_of_sitting_places << ".\n";
  if(this->place_for_bikes) out << "Wagon has place for bikes." << "\n";
  else out << "Wagon hasn't got place for bikes." << "\n";
  if(this->restaurant) out << "Wagon has restaurant." << std::endl;
  else out << "Wagon hasn't got restaurant." << std::endl;
  out << LINE << std::endl;
}
