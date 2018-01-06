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

#endif
