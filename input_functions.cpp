#include "header.hpp"
#include "myexceptions.hpp"
#include "input_functions.hpp"

void character_input(char &operation){
  std::string temp;
  // Użycie innej funkcji by sprawdzić poprawność ciągu znaków
  correct_string(std::cin, temp);
  if(temp.size() == 1){
    // Zapisanie pod argumentem podtrzebne informacji
    operation = temp[0];
  }
  // Rzucenie wyjątku informującego o za dużej ilości znaków
  else throw too_many_signs();
}

char correct_character_input(char maximum, char exception){
  char sign;
  while(1){
    try{
      // Skorzystanie z funkcji sprawdzającej poprawność wprowadzonego ciągu znaków
      character_input(sign);
      // Rzucenie wyjątku jeżeli ciąg znaków nie spełnia podanych wymagań
      if(!(sign == exception || (sign <= maximum && sign >= '1'))) throw wrong_sign();
      else break;
    }
    catch(std::exception & myexcp){
      std::cerr << "Exception : \"" << myexcp.what() << "\"" << std::endl;;
    }
  }
  return sign;
}

void correct_string(std::istream &in, std::string & str_ref){
  while(1){
    try{
      // Wczytanie ciągu znaków
      getline(in, str_ref);
      // Sprawdzenie czy ciąg nie jest pusty
      if(str_ref.size()){
        // Rzucenie wyjątku jeżeli ciąg zaczyna się od whitespace
        if(str_ref[0] == ' ') throw input_starts_with_wspc();
        break;
      }
      throw empty_input();
    }
    catch(std::exception & myexcp){
      std::cerr << "Exception : \"" << myexcp.what() << "\"" << std::endl;
    }
  }
}

void unsigned_int_check(std::string temp){
  // Rzucenie wyjątku jeżeli ciąg znaków zaczyna się od znaku minus
  if(temp[0] == '-') throw is_negative();
  for(std::string::iterator it = temp.begin(); it != temp.end(); ++it){
    // Rzucenie wyjątku jeżeli, któryś znak w ciągu znaków nie jest liczbą
    if(!isdigit(*it)) throw wrong_sign();
  }
}
