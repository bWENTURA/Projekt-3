#ifndef MAIN_FUNCTIONS_HPP
#define MAIN_FUNCTIONS_HPP

void add_wagon(train * train_ptr);

void add_train(std::vector<train*> &train_contener);

bool find_train(std::vector<train*> &train_contener, train ** train_ptr, std::vector<train*>::iterator &train_itr);

void show_trains(const std::vector<train*> &train_contener);

void delete_train_wagon(std::vector<train*> &train_contener);

#endif
