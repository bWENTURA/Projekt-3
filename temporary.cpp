bool train::get_number(std::istream& in){
  in.exceptions(in.failbit);
  try{
    in >> this->number_of_personnel;
  }
  catch(std::exception& exception){
    std::cerr << "Exception happened: \"" << exception.what() << "\"" << std::endl;
    in.clear();
    in.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
    return false;
  }
  return true;
}

void train::add_wagon(wagon* new_wagon){
  this->lwagons.push_back(new_wagon);
  this->increase_number();
}

std::istream& operator>>(std::istream& in, train& this_train){
  std::cout << "Please enter name of the train." << std::endl;
  getline(in, this_train.name);
  std::cout << "Please enter description of the train." << std::endl;
  getline(in, this_train.description);
  std::cout << "Please enter number of personnel in train." << std::endl;
  while(!this_train.get_number(in)){
    std::cout << "Please enter number of personnel again." << std::endl;
  }
  in.clear();
  in.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
  return in;
}
