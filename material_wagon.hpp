#ifndef MATERIAL_WAGON_HPP
#define MATERIAL_WAGON_HPP

class material_wagon : public wagon{
  int number;
  std::string material;
  bool empty;
  int weight;
  bool get_weight(std::istream& in);
  public:
  material_wagon(int number = 0, bool empty = true, int weight = 0);
  ~material_wagon();
  void set_number(int number);
  void print(std::ostream& out) const;
  void get(std::istream& in);
};

#endif
