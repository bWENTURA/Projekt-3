#ifndef MATERIAL_WAGON_HPP
#define MATERIAL_WAGON_HPP

class material_wagon : public wagon{
  std::string material;
  bool empty;
  int weight;
  public:
  material_wagon(bool empty = true, int weight = 0);
  ~material_wagon();
  void print(std::ostream& out) const;
  void get(std::istream& in);
};

std::istream& operator>>(std::istream& in, material_wagon& this_material_wagon);
std::ostream& operator<<(std::ostream& out, const material_wagon& this_material_wagon);

#endif
