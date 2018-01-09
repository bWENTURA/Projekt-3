#ifndef MATERIAL_WAGON_HPP
#define MATERIAL_WAGON_HPP

class material_wagon : public wagon{
  unsigned int number;
  std::string material;
  bool empty;
  unsigned int weight;
  public:
  material_wagon(unsigned int number = 0, bool empty = true, unsigned int weight = 0);
  ~material_wagon();
  void set_number(unsigned int number);// Metoda do ustawiania wartości pola number
  void get_info(std::istream& in);// Metoda wywoływana w przeciążonym operatorze wejścia dla klasy bazowej
  void print_info(std::ostream& out) const; //Metoda wywoływana w przeciążonym operatorze wyjścia dla klasy bazowej
  std::string get_class();// Metoda zwracająca nazwę klasy
};

#endif
