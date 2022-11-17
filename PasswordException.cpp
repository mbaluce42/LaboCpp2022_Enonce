#include "PasswordException.h"
#define DEBUG



const int PasswordException::INVALID_LENGTH=1;
const int PasswordException::ALPHA_MISSING=2;
const int PasswordException::DIGIT_MISSING=3;
const int PasswordException::NO_PASSWORD=4;


/*constructeur par defaut*/
	PasswordException::PasswordException()
	{
		setPswExcpCode(1);
		#ifdef DEBUG
  		cout << "Je suis le contructeur par defaut PasswordException" << endl<<endl;
  		#endif
	}

	/* contructeur d'initialisation | parametre*/
	PasswordException::PasswordException(const string mess,const int c) : Exception(mess)
	{
		setPswExcpCode(c);
		#ifdef DEBUG
  		cout << "Je suis le contructeur d'initialisation PasswordException" << endl<<endl;
  		#endif

	}
	
	/*Constructeur de copie*/
	PasswordException::PasswordException(const PasswordException &c) : Exception(c)
	{
		setPswExcpCode(c.getPswExcpCode());
		#ifdef DEBUG
  		cout << "Je suis le Constructeur de copie PasswordException" << endl<<endl;
  		#endif

	}

	/*destructeur*/
	PasswordException::~PasswordException()
	{
		#ifdef DEBUG
  		cout << "Je suis le destructeur PasswordException" << endl<<endl;
  		#endif

	}


	void PasswordException::setPswExcpCode(const int c)
	{
		code= c;

	}

	int PasswordException::getPswExcpCode()const
	{
 		return code;
	}
