#ifndef OPTION_H
#define OPTION_H

#include <iostream>
#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
#include "OptionException.h"
using namespace std;




class Option
{
private:
        string code;
        string intitule;
        float prix;
public:



        Option();//constructeur par defaut

	/* contructeur d'initialisation | parametre*/
        Option(const string optCode, const string intitul, const float money);

        /*Construction copie*/
        Option(const Option &opt);
	string getCode()const;
	string getIntitule()const;
	float getPrix()const;

	void setCode (const string optCode);
       	void setIntitule(const string intitul);
      	void setPrix(const float money);

	~Option();//destructeur
	void Affiche(void)const;


	friend ostream& operator<<(ostream& s, const Option& opt);
	friend istream& operator>>(istream& s, Option& opt);

	Option operator--();//pre-incrementation ex: ++D

	Option operator--(int);//post-incrementation ex: D++

	void Save(ofstream& fichier)const;
	void Load(ifstream& fichier);

};
#endif
