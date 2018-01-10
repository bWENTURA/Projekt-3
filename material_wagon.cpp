#include "header.hpp"
#include "input_functions.hpp"
#include "wagon.hpp"
#include "material_wagon.hpp"

material_wagon::material_wagon(unsigned int number, bool empty, unsigned int weight) : number(number), empty(empty), weight(weight) {}

material_wagon::~material_wagon() {}

void material_wagon::set_number(unsigned int number){
  this->number = number;
}

void material_wagon::get_info(std::istream& in){
  // Metoda działająca jak przeciążony operator wejścia dla klasy train
  char operation;
  std::cout << "Please enter name of the material in material wagon." << std::endl;
  correct_string(in, this->material);
  std::cout << "1. Wagon is empty.\n" << "2. Wagon is not empty." << std::endl;
  operation = correct_character_input('2');
  switch(operation){
    case '1':{
      this->empty = true;
      break;
    }
    case '2':{
    this->empty = false;
    std::cout << "Please enter weight of the material.(in kilograms)" << std::endl;
    get_number(in, this->weight);
    break;
    }
  }
}

void material_wagon::print_info(std::ostream& out) const{
  // Metoda działająca jak przeciążony operator wyjścia dla klasy train
  out << LINE << "\n";
  out << "Number of wagon: " << this->number << ".\n";
  out << "Material: " << this->material << ".\n";
  if(this->empty){
    out << "Wagon is empty." << std::endl;
  }
  else{
    out << "Weight: " << this->weight << " kg." << std::endl;
  }
}

std::string material_wagon::get_class(){
  std::string class_name = "Material";
  return class_name;
}
