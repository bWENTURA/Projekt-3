#ifndef MAIN_FUNCTIONS_HPP
#define MAIN_FUNCTIONS_HPP

void add_wagon(train * train_ptr);

void add_train(std::vector<train*> &train_contener);

bool find_train(std::vector<train*> &train_contener, train ** train_ptr, std::vector<train*>::iterator &train_itr);

void show_trains(const std::vector<train*> &train_contener);

void delete_train_wagon(std::vector<train*> &train_contener);

void edit_train_wagon(std::vector<train*> &train_contener);

bool compare_alpha(train * ptr_1, train * ptr_2);

bool compare_front(train * ptr_1, train * ptr_2);

bool compare_back(train * ptr_1, train * ptr_2);

void sort_trains(std::vector<train*> &train_contener);

#endif
