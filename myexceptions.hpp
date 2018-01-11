#ifndef MYEXCEPTIONS_HPP
#define MYEXCEPTIONS_HPP

struct wrong_sign : public std::exception {
  wrong_sign();
  ~wrong_sign() throw();
  const char* what() const throw() {
    return "Wrong sign has been entered";
  }
};

struct too_big : public std::exception{
  too_big();
  ~too_big() throw();
  const char* what() const throw() {
    return "Too big number has been entered";
  }
};

struct empty_input : public std::exception{
  empty_input();
  ~empty_input() throw();
  const char* what() const throw() {
    return "Empty input has been entered.";
  }
};

struct too_many_signs : public std::exception{
  too_many_signs();
  ~too_many_signs() throw();
  const char* what() const throw() {
    return "Too many sign have been entered";
  }
};

struct is_negative : public std::exception{
  is_negative();
  ~is_negative() throw();
  const char* what() const throw() {
    return "Given number is negative.";
  }
};

struct input_starts_with_wspc : public std::exception{
  input_starts_with_wspc();
  ~input_starts_with_wspc() throw();
  const char* what() const throw() {
    return "Given input starts with whitespace.";
  }
};

struct train_with_name_already_exists : public std::exception{
  train_with_name_already_exists();
  ~train_with_name_already_exists() throw();
  const char* what() const throw() {
    return "Train_with_name_already_exists.";
  }
};

#endif
