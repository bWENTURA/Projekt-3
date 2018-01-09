#ifndef TRAIN_HPP
#define TRAIN_HPP

class train{
  std::string name;
  std::string description;
  unsigned int number_of_personnel;
  unsigned int number_of_wagons;
  std::list<wagon*> lwagons;
  void increase_number();
  void decrease_number();
  void get_number(std::istream& in, unsigned int &number);
  public:
  train(unsigned int number_person = 0, unsigned int number_waggon = 0);
  ~train();
  std::string get_name();
  int get_number_of_wagons();
  bool empty();
  void edit_info();
  void edit_wagon_info();
  void create_wagon(wagon* new_wagon);
  void delete_wagon();
  friend std::istream& operator>>(std::istream& in, train& this_train);
  friend std::ostream& operator<<(std::ostream& out, const train& this_train);
};

#endif
