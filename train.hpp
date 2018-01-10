#ifndef TRAIN_HPP
#define TRAIN_HPP

class train{
  std::string name;
  std::string description;
  unsigned int number_of_personnel;
  unsigned int number_of_wagons;
  std::list<wagon*> lwagons;
  public:
  train(unsigned int number_person = 0, unsigned int number_waggon = 0);// Konstruktor
  ~train();// Destruktor
  std::string get_name();// Metoda zwracająca ciąg znaków name
  int get_number_of_wagons();// Metoda zwracająca wartość pola number_of_wagons
  void edit_info();// Metoda edytująca informacje o obkcie typu train
  void edit_wagon_info();// Metoda edytująca informacje o obiekcie typu wagon z listy obiektu typu train
  void create_wagon(wagon* new_wagon);// Metoda tworząca obiekt wagon w liście obiektu train
  void delete_wagon();// Metoda usuwająca obiekt wagonz  listy obiektu train
  friend std::istream& operator>>(std::istream& in, train& this_train);// Przeciążony operator wejścia
  friend std::ostream& operator<<(std::ostream& out, const train& this_train);// Przeciążony operator wyjścia
};

#endif
