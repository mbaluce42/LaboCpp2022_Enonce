#ifndef OPTIONEXCEPTION_H
#define OPTIONEXCEPTION_H

#include <string>
#include <iostream>
#include <cstring>
#include "Exception.h"
using namespace std;


class OptionException : public Exception
{

public:
  OptionException();
  OptionException(const string msg);
  OptionException(const OptionException& m);

  ~OptionException();
};
#endif