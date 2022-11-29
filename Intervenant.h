#ifndef INTERVENANT_H
#define INTERVENANT_H


#include "Personne.h"
#include <string>
#include <iostream>
using namespace std;


class Intervenant : public Personne
{

protected:
	int numero;
	
public:
	static int numCourant;
	virtual string Tuple()=0;// fct virtuelle pure
	virtual string ToString()=0;// fct virtuelle pure
	/*constructeur par defaut*/
	Intervenant();
	

	/* contructeur d'initialisation | parametre*/
	Intervenant(const string n, const string pren/*,const int num*/); 


	/*Constructeur de copie*/
	Intervenant(const Intervenant &i);

	/*destructeur*/
	~Intervenant();

	void setNumero(const int n);


	int getNumero()const;


	Intervenant& operator=(const Intervenant& interv);




};
#endif