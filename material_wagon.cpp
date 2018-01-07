#include "header.hpp"
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
  return true;
}

void material_wagon::set_number(int number){
  this->number = number;
}

void material_wagon::get(std::istream& in){
  std::string temp;
  std::cout << "Please enter name of the material in material wagon." << std::endl;
  getline(in, this->material);
  std::cout << "Please write \"true\" if wagon is empty, otherwise type \"false\"." << std::endl;
  getline(in, temp);
  if(temp == "true") this->empty = true;
  else{
    this->empty = false;
    std::cout << "Please enter weight of the material.(in kilograms)" << std::endl;
    while(!this->get_weight(in)){
      std::cout << "Please enter weight again." << std::endl;
    }
    in.clear();
    in.ignore(std::numeric_limits<std::streamsize >::max(), '\n');
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
