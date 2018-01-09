#include "header.hpp"
#include "myexceptions.hpp"
#include "input_functions.hpp"

//Funkcja sprawdzająca czy został poprawnie wprowadzony pojedynczy znak
void character_input(char &operation){
  std::string temp;
  correct_string(std::cin, temp);
  switch(temp.size()){
    case 1:{
      operation = temp[0];
      break;
    }
    case 0:{
      throw empty_input();
      break;
    }
    default:{
      throw too_many_signs();
      break;
    }
  }
}

//Funkcja sprawdzająca czy wprowadzony poprawnie pojedynczy znak mieści się w wymaganym zakresie
//Funkcja używana wyłącznie do wyboru liczb z zakresu [1, maximum], ewentualnie pojedynczego znaku exception
//Funkcja mająca głównie zastosowanie w wyborze opcji z menu
char correct_character_input(char maximum, char exception){
  char sign;
  while(1){
    try{
      character_input(sign);
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
      getline(in, str_ref);
      if(str_ref.size()){
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
  if(temp[0] == '-') throw is_negative();
  for(std::string::iterator it = temp.begin(); it != temp.end(); ++it){
    if(!isdigit(*it)) throw wrong_sign();
  }
}
