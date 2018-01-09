#ifndef WAGON_FOR_PEOPLE_HPP
#define WAGON_FOR_PEOPLE_HPP

class wagon_for_people : public wagon{
  unsigned int number;
  unsigned int number_of_sitting_places;
  bool place_for_bikes;
  bool restaurant;
  public:
  wagon_for_people(unsigned int number = 0, unsigned int number_of_sitting_places = 0, bool place_for_bikes = false, bool restaurant = false);
  ~wagon_for_people();
  void set_number(unsigned int number);// Metoda do ustawiania wartości pola number
  void get_info(std::istream& in);// Metoda wywoływana w przeciążonym operatorze wejścia dla klasy bazowej
  void print_info(std::ostream& out) const;//Metoda wywoływana w przeciążonym operatorze wyjścia dla klasy bazowej
  std::string get_class();// Metoda zwracająca nazwę klasy
};

#endif
