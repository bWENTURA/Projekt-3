#include "header.hpp"
#include "input_functions.hpp"
#include "wagon.hpp"
#include "train.hpp"

train::train(unsigned int number_person, unsigned int number_wagon) : number_of_personnel(number_person), number_of_wagons(number_wagon) {}

train::~train(){
  // Pętla wywołująca destruktor dla każdego elementu listy obiektu train przechowującej wskaźniki na obiekty typu wagon
  for(std::list<wagon*>::iterator it = this->lwagons.begin(); it != this->lwagons.end(); ++it){
    delete *it;
  }
}

std::string train::get_name(){
  return this->name;
}

int train::get_number_of_wagons(){
  return this->number_of_wagons;
}

void train::edit_info(){
  // Wywołanie przeciążonego operatora >> aby ponownie wprowadzić dane do obiektu
  std::cin >> *this;
}

void train::edit_wagon_info(){
  unsigned int number;
  std::cout << *this;
  std::cout << "Please enter number of wagon you want to edit." << std::endl;
  // Wywołanie funkcji pozyskującej poprawny unsigned int ze strumienia
  get_number(std::cin, number);
  if(number <= this->number_of_wagons){
    // Ustawienie iteratora it na początek listy obiektów typu wagon, a następnie przesunięcie go o odpowiednią ilość mniejsc za pomocą std::advance
    std::list<wagon*>::iterator it = this->lwagons.begin();
    std::advance(it, number - 1);
    // Wywołanie przeciążonego strumienia wejścia dla klasy wagon
    std::cin >> **it;
  }
  else std::cout << "Wrong number has been entered." << std::endl;
}

void train::create_wagon(wagon * new_wagon){
  std::cin >> *new_wagon;
  this->number_of_wagons++;
  // Sprawdzenie na obiekt jakiej podklasy wskazuje wskaźnik klasy bazowej new_wagon
  if(new_wagon->get_class() == "People"){
    int number = 1;
    this->lwagons.push_front(new_wagon);
    // Zaktualizowanie numerów obiektów typu wagon, ponieważ nowy obiekt klasy wagon_for_people został umieszczony na początku
    for(std::list<wagon*>::iterator it = this->lwagons.begin(); it != this->lwagons.end(); ++it){
      (*it)->set_number(number);
      number++;
    }
  }
  else{
    // Umieszczenie na końcu obiektu klasy material_wagon
    this->lwagons.push_back(new_wagon);
    new_wagon->set_number(this->number_of_wagons);
  }
}

void train::delete_wagon(){
  unsigned int number, temp_number = 0;
  std::list<wagon*>::iterator it;
  // Wyświetlenie zawartości obiektu pod wskaźnikiem train_ptr za pomocą przeciążonego operatora <<
  std::cout << *this;
  std::cout << "Enter number of the wagon you want to delete." << std::endl;
  get_number(std::cin, number);
  if(number <= this->number_of_wagons){
    std::list<wagon*>::iterator it = this->lwagons.begin();
    std::advance(it, number - 1);
    temp_number = number - 1;
    for(std::list<wagon*>::iterator other = it; other != this->lwagons.end(); ++other){
      (*other)->set_number(temp_number);
      temp_number++;
    }
    wagon * wagon_ptr = *it;
    // Użycie remove ponieważ korzystam z iteratora it
    this->lwagons.remove(*it);
    delete wagon_ptr;
    this->number_of_wagons--;
    std::cout << LINE << "\nWagon has been deleted.\n" << LINE << std::endl;
  }
  else std::cout << LINE << "\nWrong number has been entered.\n" << LINE << std::endl;
}

std::istream& operator>>(std::istream& in, train& this_train){
  std::cout << "Please enter name of the train." << std::endl;
  // Sprawdzenie poprawności wprowadzonego ciągu znaków przez correct_string i get_number
  correct_string(in, this_train.name);
  std::cout << "Please enter description of the train." << std::endl;
  correct_string(in, this_train.description);
  std::cout << "Please enter number of personnel in train." << std::endl;
  get_number(in, this_train.number_of_personnel);
  return in;
}

std::ostream& operator<<(std::ostream& out, const train& this_train){
  out << TRAIN_LINE << "\n";
  out << "Name: " << this_train.name << ".\n";
  out << "Description: " << this_train.description << ".\n";
  out << "Number of personnel: " << this_train.number_of_personnel << ".\n";
  out << "Number of wagons: " << this_train.number_of_wagons << ".\n";
  if(this_train.lwagons.size()){
    for(std::list<wagon*>::const_iterator it = this_train.lwagons.begin(); it != this_train.lwagons.end(); ++it){
      out << **it;
    }
  }
  out << TRAIN_LINE << std::endl;
  return out;
}
