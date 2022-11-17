#ifndef CLIENT_H
#define CLIENT_H

#include "Intervenant.h"

#include <iostream>
#include <cstring>
#include <string>
using namespace std;


class Client : public Intervenant
{
private:
	string gsm;

public:

	/*constructeur par defaut*/
	Client();

	/* contructeur d'initialisation | parametre*/
	Client(const string n, const string pren,const int num, const string phone);

	/*Constructeur de copie*/
	Client(const Client &cli);

	/*destructeur*/
	~Client();

	string Tuple();// fct virtuelle pure Intervenant
	string ToString();// fct virtuelle pure Intervenant


	void setGsm(const string phone);

	string getGsm()const;

	Client& operator=(const Client& cli);

	friend ostream& operator<<(ostream& s, const Client& cli);

};
#endif