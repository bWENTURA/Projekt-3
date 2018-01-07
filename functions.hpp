#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

bool character_input(char *operation);

char correct_character_input(char maximum, char exception = '1');

void add_wagon(train * train_ptr);

void add_train(std::vector<train*> &train_contener);

void find_train(std::vector<train*> &train_contener);

void show_trains(const std::vector<train*> &train_contener);

#endif
