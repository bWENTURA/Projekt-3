#include "header.hpp"
#include "wagon.hpp"
#include "material_wagon.hpp"

material_wagon::material_wagon(bool empty, int weight) : empty(empty), weight(weight) {}

material_wagon::~material_wagon(){
  std::cout << "Wagon destructor!" << std::endl;
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
    std::cout << "Please enter weight of the material." << std::endl;
    in >> this->weight;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n' );
  }
}

void material_wagon::print(std::ostream& out) const{
  out << LINE << "\n";
  out << "Material: " << this->material << ".\n";
  if(this->empty){
    out << "Wagon is empty." << std::endl;
  }
  else{
    out << "Weight: " << this->weight << " kg." << std::endl;
  }
  out << LINE << std::endl;
}
