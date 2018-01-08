#ifndef INPUT_FUNCTIONS_HPP
#define INPUT_FUNCTIONS_HPP

char character_input();

char correct_character_input(char maximum, char exception = '1');

void correct_string(std::istream &in, std::string & str_ref);

#endif
