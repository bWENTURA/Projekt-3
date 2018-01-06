#ifndef WAGON_FOR_PEOPLE_HPP
#define WAGON_FOR_PEOPLE_HPP

class wagon_for_people : public wagon{
  int number_of_sitting_places;
  bool place_for_bikes;
  bool restaurant;
  public:
  wagon_for_people(int number_of_sitting_places = 0, bool place_for_bikes = false, bool restaurant = false);
  ~wagon_for_people();
  void print(std::ostream& out) const;
  void get(std::istream& in);
};

#endif
