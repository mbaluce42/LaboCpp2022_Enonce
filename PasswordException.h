#ifndef PASSWORDEXCEPTION_H
#define PASSWORDEXCEPTION_H

#include "Exception.h"

#include <iostream>
#include <string>
using namespace std;


class PasswordException : public Exception
{
protected:
	int code;
public:

	static const int INVALID_LENGTH;
	static const int ALPHA_MISSING;
	static const int DIGIT_MISSING;
	static const int NO_PASSWORD;


	/*constructeur par defaut*/
	PasswordException();

	/* contructeur d'initialisation | parametre*/
	PasswordException(const string mess, const int c);

	/*Constructeur de copie*/
	PasswordException(const PasswordException &c);

	/*destructeur*/
	~PasswordException();


	void setPswExcpCode(const int c);

	int getPswExcpCode()const;



};
#endif