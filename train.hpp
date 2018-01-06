#ifndef TRAIN_HPP
#define TRAIN_HPP

class train{
  std::string name;
  std::string description;
  int number_of_personnel;
  int number_of_wagons;
  std::list<wagon*> lwagons;
  public:
  train(int number_person = 0, int number_waggon = 0);
  ~train();
  friend std::istream& operator>>(std::istream& in, train& this_train);
  friend std::ostream& operator<<(std::ostream& out, const train& this_train);
};

#endif
