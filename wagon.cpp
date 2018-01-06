#include "header.hpp"
#include "wagon.hpp"

std::istream& operator>>(std::istream& in, wagon& this_wagon){
  this_wagon.get(in);
  return in;
}

std::ostream& operator<<(std::ostream& out, const wagon& this_wagon){
  this_wagon.print(out);
  return out;
}
