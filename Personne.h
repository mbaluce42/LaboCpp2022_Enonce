#ifndef PERSONNE_H
#define PERSONNE_H


#include <iostream>
#include <string>
using namespace std;

class Personne
{
protected:
	string nom;
	string prenom;

public:
	/*constructeur par defaut*/
	Personne();

	/* contructeur d'initialisation | parametre*/
	Personne(const string n, const string pren);

	/*Constructeur de copie*/
	Personne(const Personne &pers);

	/*setter et getter*/
	void setNom(const string PersNom);
	string getNom()const;

	void setPrenom(const string PersPrenom);
	string getPrenom()const;

	/*destructeur*/
	~Personne();

	/*Autre*/
	void Affiche()const;

	friend ostream& operator<<(ostream& s, const Personne& p);
	friend istream& operator>>(istream& s, Personne& p);
	Personne& operator=(const Personne& p);


};

#endif