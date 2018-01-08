#include "header.hpp"
#include "input_functions.hpp"
#include "wagon.hpp"
#include "material_wagon.hpp"

material_wagon::material_wagon(int number, bool empty, int weight) : number(number), empty(empty), weight(weight) {}

material_wagon::~material_wagon() {}

bool material_wagon::get_weight(std::istream& in){
  in.exceptions(in.failbit);
  try{
    in >> this->weight;
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

void material_wagon::set_number(int number){
  this->number = number;
}

void material_wagon::get(std::istream& in){
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
    while(!this->get_weight(in)){
      std::cout << "Please enter weight again." << std::endl;
    }
    break;
    }
  }
}

void material_wagon::print(std::ostream& out) const{
  out << LINE << "\n";
  out << "Number of wagon: " << this->number << ".\n";
  out << "Material: " << this->material << ".\n";
  if(this->empty){
    out << "Wagon is empty." << std::endl;
  }
  else{
    out << "Weight: " << this->weight << " kg." << std::endl;
  }
  out << LINE << std::endl;
}
