#ifndef MYEXCEPTIONS_HPP
#define MYEXCEPTIONS_HPP

struct wrong_sign : public std::exception {
  wrong_sign();
  ~wrong_sign();
  const char* what() const throw() {
    return "Wrong sign has been entered";
  }
};

struct too_big : public std::exception{
  too_big();
  ~too_big();
  const char* what() const throw() {
    return "Too big number has been entered";
  }
};

struct empty_input : public std::exception{
  empty_input();
  ~empty_input();
  const char* what() const throw() {
    return "Empty input has been entered.";
  }
};

struct too_many_signs : public std::exception{
  too_many_signs();
  ~too_many_signs();
  const char* what() const throw() {
    return "Too many sign have been entered";
  }
};

#endif