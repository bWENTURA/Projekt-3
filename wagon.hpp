#ifndef WAGON_HPP
#define WAGON_HPP

class wagon{
  public:
  wagon(){};
  virtual ~wagon(){};
  virtual void set_number(unsigned int number) = 0;
  virtual void print_info(std::ostream& out) const = 0;
  virtual void get_info(std::istream& in) = 0;
  virtual std::string get_class() = 0;
};

std::istream& operator>>(std::istream& in, wagon& this_wagon);// Przeciążony operator wejścia wywołuje funkcje wirtualną get_info
std::ostream& operator<<(std::ostream& out, const wagon& this_wagon);// Przeciążony operator wyjścia wywołuje funkcje wirtualną print_info

#endif
