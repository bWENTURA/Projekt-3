#include "header.hpp"
#include "wagon.hpp"

std::istream& operator>>(std::istream& in, wagon& this_wagon){
  this_wagon.get_info(in);
  return in;
}

std::ostream& operator<<(std::ostream& out, const wagon& this_wagon){
  this_wagon.print_info(out);
  return out;
}
