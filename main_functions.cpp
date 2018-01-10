#include "header.hpp"
#include "myexceptions.hpp"
#include "input_functions.hpp"
#include "wagon.hpp"
#include "material_wagon.hpp"
#include "wagon_for_people.hpp"
#include "train.hpp"
#include "main_functions.hpp"

bool compare_alpha(train * ptr_1, train * ptr_2){
  return (ptr_1->get_name() < ptr_2->get_name());
}

bool compare_front(train * ptr_1, train * ptr_2){
  return (ptr_1->get_number_of_wagons() > ptr_2->get_number_of_wagons());
}

bool compare_back(train * ptr_1, train * ptr_2){
  return (ptr_1->get_number_of_wagons() < ptr_2->get_number_of_wagons());
}

void add_wagon(train * train_ptr){
  // Zmienna pomocnicza określająca możliwość wyjścia z pętli
  bool exit = false;
  // Zmienna, w której przechowywany jest znak odpowiadający numerowi operacji, którą użytkownik będzie chciał wywołać
  // Wartość zmiennej jest ustawiana za pomocą funkcji correct_character_input, której kod znajduje się w pliku input_functions.cpp
  char operation;
  while(!exit){
    std::cout << LINE << "\n1. Add wagon for materials.\n" <<"2. Add wagon for people.\n" << "Type 'q' to exit.\n" << LINE << std::endl;
    operation = correct_character_input('2', 'q');
    switch(operation){
      case '1':{
        try{
          // W  case '1' i '2' tworzone są odpowiednie, wybrane przez użytkownika obiekty, a następnie wywoływana jest metoda klasy train
          // dodająca obiekt wagon do listy obiektu train
          wagon * wagon_ptr = new material_wagon();
          train_ptr->create_wagon(wagon_ptr);
        }// Blok catch aby wyłapać wyjątki związane ze złą alokacją pamięci dla obiektu typu wagon
        catch(const std::bad_alloc & excp){
          std::cerr << "Exception, bad alloc: \"" << excp.what() << "\"" << std::endl;
        }
        break;
      }
      case '2':{
        try{
          wagon * wagon_ptr = new wagon_for_people();
          train_ptr->create_wagon(wagon_ptr);
        }
        catch(const std::bad_alloc & excp){
          std::cerr << "Exception, bad alloc: \"" << excp.what() << "\"" << std::endl;
        }
        break;
      }
      case 'q':{
        exit = true;
        break;
      }
    }
  }
}

void add_train(std::vector<train*> &train_contener){
  try{
    train * train_ptr = new train();
    // Wywołanie operatora >> dla obiektu typu train, w celu wprowadzenia do niego danych
    // Kod przeciążenia operatora znajduje się w train.cpp
    std::cin >> *train_ptr;
    // Sprawdzenie czy nie istnieje już obiekt o takiej nazwie jaką posiada nowo utworzony biekt typu train
    for(std::vector<train*>::iterator it = train_contener.begin(); it != train_contener.end(); ++it){
      if((*it)->get_name() == train_ptr->get_name()){
        delete train_ptr;
        throw train_with_name_already_exists();
      }
    }
    // Wywołanie funkcji add_wagon, tak aby od razu można było dodać obiekty typu wagon do nowo stworzonego obiektu typu train
    add_wagon(train_ptr);
    train_contener.push_back(train_ptr);
  }// Blok catch aby wyłapać wyjątki związane ze złą alokacją pamięci dla obiektu typu wagon
  catch(const std::exception & excp){
    std::cerr << LINE << "\nException: \"" << excp.what() << "\"\n" << LINE << std::endl;
  }
}

bool find_train(std::vector<train*> &train_contener, train ** train_ptr, std::vector<train*>::iterator &train_itr){
  std::string name;
  std::cout << LINE << "\nEnter name of the train you are looking for.\n" << LINE << std::endl;
  // Funkcja correct_string sprawdzająca poprawność wprowadzanego ciągu znaków, której kod znajduje się w input_functions.cpp
  correct_string(std::cin, name);
  for(std::vector<train*>::iterator it = train_contener.begin(); it != train_contener.end(); ++it){
    // Sprawdzenie czy nazwa obiektu zwrócona przez metodę get_name klasy train jest szukaną przez użytkownika nazwą
    if((*it)->get_name() == name){
      // Zapisanie potrzebnych informacji w argumentach
      *train_ptr = *it;
      if(train_itr != train_contener.end()) train_itr = it;
      return true;
    }
  }
  std::cout << LINE << "\nProgram couldn't find train with name \"" << name << "\"." << std::endl;
  return false;
}

void show_trains(const std::vector<train*> &train_contener){
  for(std::vector<train*>::const_iterator it = train_contener.begin(); it != train_contener.end(); ++it){
    std::cout << **it;
  }
}

void delete_train_wagon(std::vector<train*> &train_contener){
  bool exit = false;
  char operation;
  while(!exit){
    std::cout << LINE << "\n1. Delete train.\n" << "2. Delete wagon.\n" << "Type 'q' to exit.\n" << LINE << std::endl;
    operation = correct_character_input('2', 'q');
    switch(operation){
      case '1':{
        // Wstępne wartości przekazane jako argumenty do funkcji find_train
        // Jeżeli funkcja zwróci wartośc true, w zmiennych zostaną zapisane odpowiednie informacje
        train * train_ptr = NULL;
        std::vector<train*>::iterator train_itr = train_contener.begin();
        if(find_train(train_contener, &train_ptr, train_itr)){
          // Dzięki uzyskaniu z funkcji find_train wartości train_itr, możemy usunąć obiekt z kontenera zachowując jego spójność
          train_contener.erase(train_itr);
          std::cout << LINE << "\nTrain \"" << train_ptr->get_name() << "\" was deleted.\n" << LINE << std::endl;
          // Dzięki zapisaniu wskaźnika do usuwanego z kontenera obiektu, można teraz wywołać destruktor aby uniknąć wycieków pamięci
          delete train_ptr;
        }
        break;
      }
      case '2':{
        train * train_ptr = NULL;
        std::vector<train*>::iterator train_itr = train_contener.end();
        if(find_train(train_contener, &train_ptr, train_itr)){
          // Sprawdzenie czy wyszukany obiekt typu pociąg posiada jakiekolwiek obiekty typu wagon
          if(!train_ptr->get_number_of_wagons()){
            // Wywołanie funkcji delete_wagon
            train_ptr->delete_wagon();
          }
          else std::cout << LINE << "\nTrain \"" << train_ptr->get_name() << "\" hasn't got wagons.\n" << LINE << std::endl;
        }
        break;
      }
      case 'q':{
        exit = true;
        break;
      }
    }
  }
}

void edit_train_wagon(std::vector<train*> &train_contener){
  bool exit = false;
  char operation;
  while(!exit){
    std::cout << LINE << "\n1. Edit train.\n" << "2. Edit wagon.\n" << "Type 'q' to exit.\n" << LINE << std::endl;
    operation = correct_character_input('2', 'q');
    switch(operation){
      case '1':{
        train * train_ptr = NULL;
        std::vector<train*>::iterator train_itr = train_contener.end();
        if(find_train(train_contener, &train_ptr, train_itr)){
          // Wywołanie metody edit_info edytującej informacje o obiekcie typu train
          train_ptr->edit_info();
          std::cout << LINE << "\nTrain \"" << train_ptr->get_name() << "\" was edited.\n" << LINE << std::endl;
        }
        break;
      }
      case '2':{
        train * train_ptr = NULL;
        std::vector<train*>::iterator train_itr = train_contener.end();
        if(find_train(train_contener, &train_ptr, train_itr)){
          if(!train_ptr->get_number_of_wagons()){
            // Wywołanie metody edit_wagon_info klasy train wyszukującej pożądany obiekt typu wagon i edytującej informacje o obiekcie typu wagon
            train_ptr->edit_wagon_info();
          }
          else std::cout << LINE << "\nTrain \"" << train_ptr->get_name() << "\" hasn't got wagons.\n" << LINE << std::endl;
        }
        break;
      }
      case 'q':{
        exit = true;
        break;
      }
    }
  }
}

void sort_trains(std::vector<train*> &train_contener){
  char operation;
  std::cout << LINE << "\n1. Sort trains alphabetically.\n" << "2. Sort trains so these with more wagons will be on front.\n" << "3. Sort trains so these with more wagons will be on back.\n" << LINE << std::endl;
  operation = correct_character_input('3');
  switch(operation){
    case '1':{
      // Wywołanie algorytmu z biblioteki stl algorithm
      std::sort(train_contener.begin(), train_contener.end(), compare_alpha);
      break;
    }
    case '2':{
      std::sort(train_contener.begin(), train_contener.end(), compare_front);
      break;
    }
    case '3':{
      std::sort(train_contener.begin(), train_contener.end(), compare_back);
      break;
    }
  }
}
