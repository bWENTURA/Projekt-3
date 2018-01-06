#ifndef WAGON_HPP
#define WAGON_HPP

class wagon{
  public:
  wagon(){};
  virtual ~wagon(){};
  virtual void print(std::ostream& out) const = 0;
  virtual void get(std::istream& in) = 0;
};

std::istream& operator>>(std::istream& in, wagon& this_wagon);
std::ostream& operator<<(std::ostream& out, const wagon& this_wagon);

#endif
