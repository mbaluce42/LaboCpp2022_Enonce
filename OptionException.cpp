#include "OptionException.h"
#define DEBUG



OptionException::OptionException()
{
  setMessage("erreur");
  #ifdef DEBUG
  cout << "Je suis le contructeur par defaut OptionException" << endl;
  #endif
}

OptionException::OptionException(const string msg)
{
  setMessage(msg);
  #ifdef DEBUG
  cout << "Je suis le contructeur d'initialisation " << endl;
  #endif

}

OptionException::OptionException(const OptionException& m)
{
  setMessage(m.getMessage());
  #ifdef DEBUG
  cout << "constructeur de option" << endl;
  #endif
}



OptionException::~OptionException()
{
  #ifdef DEBUG
  cout << "destructeur de option" << endl;
  #endif
}