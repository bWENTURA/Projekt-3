#ifndef MAIN_FUNCTIONS_HPP
#define MAIN_FUNCTIONS_HPP

// Jedna z trzech funkcji compare potrzebnych do wywołania funkcji sort z biblioteki stl
// Ta funkcja porównuje nazwy (typu string) obiektów typu train w sensie alfabetycznym
bool compare_alpha(train * ptr_1, train * ptr_2);

bool compare_front(train * ptr_1, train * ptr_2);

// Ta funkcja (a także ta niżej) porównuje wartości odpowiadające ilości obiektów typu wagon, które typ train zawiera zawiera
bool compare_back(train * ptr_1, train * ptr_2);

// Ta funkcja dodaje wagon do obiektu train, do którego wskaźnik jest podany jako argument
void add_wagon(train * train_ptr);

// Funkcja dodająca wskaźnik na obiekt typu train do kontenera vector train_contener
void add_train(std::vector<train*> &train_contener);

// Funkcja sprawdzająca czy w kontenerze train_contener znajduje się wskaźnik na obiekt typu train o nazwie określonej przez użytkownika
// Jako argumenty funkcja przyjmuje referencje do iteratora(co jest potrzebne w jednym przypadku użycia funkcji) i podwójny wskaźnik do obiektu typu train
// Dzieki temu, w przypadku gdy funkcja zwraca wartość true, za pomocą argumentów zwracane są potrzebne wartości
bool find_train(std::vector<train*> &train_contener, train ** train_ptr, std::vector<train*>::iterator &train_itr);

// Funkcja wyświetlająca zawartość kontenera obiektów typu train
void show_trains(const std::vector<train*> &train_contener);

// Funkcja usuwająca cały obiekt pociąg, bądź pojedynczy obiekt wagon z obiektu typu train
void delete_train_wagon(std::vector<train*> &train_contener);

// Funkcja edytująca informacje opisujące obiekt typu train lub obiekt typu wagon
void edit_train_wagon(std::vector<train*> &train_contener);

// Funkcja sortująca obiekty typu train zawarte w kontenerze vector train_contener
void sort_trains(std::vector<train*> &train_contener);

#endif
