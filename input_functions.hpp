#ifndef INPUT_FUNCTIONS_HPP
#define INPUT_FUNCTIONS_HPP

//Funkcja sprawdzająca czy został poprawnie wprowadzony pojedynczy znak
char character_input();

//Funkcja sprawdzająca czy wprowadzony poprawnie pojedynczy znak mieści się w wymaganym zakresie
//Funkcja używana wyłącznie do wyboru liczb z zakresu [1, maximum], ewentualnie pojedynczego znaku exception
//Funkcja mająca głównie zastosowanie w wyborze opcji z menu
char correct_character_input(char maximum, char exception = '1');

// Funkcja sprawdzająca czy został wprowadzony poprawny ciąg znaków
void correct_string(std::istream &in, std::string & str_ref);

// Funkcja sprawdzająca czy podana liczba jest typu unsigned int
void unsigned_int_check(std::string);

#endif
