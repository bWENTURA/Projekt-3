#include "header.hpp"
#include "wagon_for_people.hpp"

wagon_for_people::wagon_for_people(int number_of_sitting_places, bool place_for_bikes, bool restaurant) : number_of_sitting_places(number_of_sitting_places), place_for_bikes(place_for_bikes), restaurant(restaurant) {}

wagon_for_people::~wagon_for_people(){
  std::cout << "Wagon for people destruktor!" << std::endl;
}

void wagon_for_people::get(std::istream& in){
  std::string temp;
  std::cout << "Please enter number of sitting places." << std::endl;
  getline(in, this->number_of_sitting_places);
  std::cout << "Please write \"true\" if wagon has place for bikes, otherwise type \"false\"." << std::endl;
  getline(in, temp);
  if(temp == "true") this->empty = true;
  else this->empty = false;
  std::cout << "Please write \"true\" if wagon has restaurant, otherwise type \"false\"." << std::endl;
  getline(in, temp);
  if(temp == "true") this->restaurant = true;
  else this->restaurant = false;
}

void wagon_for_people::print(std::ostream& out) const{
  out << LINE << "\n";
  out << "Number of sitting places: " << this->number_of_sitting_places << ".\n";
  if(this->place_for_bikes) out << "Wagon has place for bikes." << "\n";
  else out << "Wagon hasn't got place for bikes." << "\n";
  if(this->restaurant) out << "Wagon has restaurant." << std::endl;
  else out << "Wagon hasn't got restaurant." << std::endl;
  out << LINE << std::endl;
}
