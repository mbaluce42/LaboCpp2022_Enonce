#include "Intervenant.h"
#define DEBUG

int Intervenant::numCourant=1;
/*constructeur par defaut*/
	Intervenant::Intervenant()
	{
		setNumero(1);
		#ifdef DEBUG
  		cout << "Je suis le contructeur par defaut Intervenant" << endl<<endl;
  		#endif
	}

	/* contructeur d'initialisation | parametre*/
	Intervenant::Intervenant(const string n, const string pren/*,const int num*/) : Personne(n,pren)
	{
		setNumero(numCourant);
		numCourant++;
		#ifdef DEBUG
  		cout << "Je suis le contructeur d'initialisation Intervenant" << endl<<endl;
  		#endif

	}

	/*Constructeur de copie*/
	Intervenant::Intervenant(const Intervenant& i) : Personne(i)
	{
		setNumero(/*i.getNumero()*/numCourant);
		#ifdef DEBUG
  		cout << "Je suis le contructeur de copie Intervenant" << endl<<endl;
  		#endif

	}
	
	

	/*destructeur*/
	Intervenant::~Intervenant()
	{
		#ifdef DEBUG
  		cout << "Je suis le destructeur Intervenant" << endl<<endl;
  		#endif

	}


	void Intervenant::setNumero(const int n)
	{
  		if(n>0)
  		{
    		numero=n;
  		}

	}

	int Intervenant::getNumero()const
	{
 		return numero;
	}

	Intervenant& Intervenant::operator=(const Intervenant& interv)
	{
		Personne::operator=(interv);
		setNumero(interv.getNumero());

		return (*this);

	}
