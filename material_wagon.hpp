#ifndef MATERIAL_WAGON_HPP
#define MATERIAL_WAGON_HPP

class material_wagon : public wagon{
  unsigned int number;
  std::string material;
  bool empty;
  unsigned int weight;
  void get_weight(std::istream& in, unsigned int & number);
  public:
  material_wagon(unsigned int number = 0, bool empty = true, unsigned int weight = 0);
  ~material_wagon();
  void set_number(unsigned int number);
  void print(std::ostream& out) const;
  void get(std::istream& in);
};

#endif
