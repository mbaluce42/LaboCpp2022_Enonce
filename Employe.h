#ifndef EMPLOYE_H
#define EMPLOYE_H

#include "Intervenant.h"

#include "PasswordException.h"

#include <iostream>
#include <cstring>
#include <string>
using namespace std;


class Employe: public Intervenant
{
protected:
	string login;
	string* motDePasse;
	string fonction;

public:
	static const string ADMINISTRATIF;
	static const string VENDEUR;

	/*constructeur par defaut*/
	Employe();

	/* contructeur d'initialisation | parametre*/
	Employe(const string n, const string pren,const int num,const string l,const string fct);

	/*Constructeur de copie*/
	Employe(const Employe &empl);

	/*destructeur*/
	~Employe();

	string Tuple();// fct virtuelle pure Intervenant
	string ToString();// fct virtuelle pure Intervenant


	void setLogin(const string l);
	string getLogin()const;

	void setMotDePasse(const string mdp);
	string getMotDePasse()const;
	void ResetMotDePasse();

	void setFonction(const string fct);
	string getFonction()const;


	Employe& operator=(const Employe& empl);

	friend ostream& operator<<(ostream& s, const Employe& empl);

};
#endif