#ifndef WAGON_FOR_PEOPLE_HPP
#define WAGON_FOR_PEOPLE_HPP

class wagon_for_people : public wagon{
  unsigned int number;
  unsigned int number_of_sitting_places;
  bool place_for_bikes;
  bool restaurant;
  void get_number_of_sitting_places(std::istream& in, unsigned int & number);
  public:
  wagon_for_people(unsigned int number = 0, unsigned int number_of_sitting_places = 0, bool place_for_bikes = false, bool restaurant = false);
  ~wagon_for_people();
  void set_number(unsigned int number);
  void get_info(std::istream& in);
  void print_info(std::ostream& out) const;
  std::string get_class();
};

#endif
