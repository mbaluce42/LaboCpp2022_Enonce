#include "Modele.h"

#include <iostream>
#include <cstring>
#include <string>
using namespace std;


Modele::Modele()//constructeur par defaut
{

  nom= NULL;
  setNom("");
  setPuissance(100);
  //moteur= Essence;
  setMoteur(moteur);
  setPrixDeBase(prixDeBase);
  //prixDeBase=445.97;
  cout << "Je suis le contructeur par defaut" << endl<<endl;
}

/* contructeur d'initialisation | parametre*/
Modele::Modele(const char* name, int p, Moteur m,float prix)
{
  nom= NULL;
  setNom(name);
  setPuissance(p);
  setMoteur(m);
  setPrixDeBase(prix);

  /*comme le contructeur par defaut sauf qu'il est parametre*/
  cout << "Je suis le contructeur d'initialisation" << endl<<endl;
}

/*contructeur de copie*/
/*Syntaxe fonction--> nomClasse (const nomClasse & autre_objet); */
Modele::Modele(const Modele &modl)
{
  nom= NULL;
  setNom(modl.nom);
  setPuissance(modl.puissance);
  //moteur=modl.moteur;
  //prixDeBase=modl.prixDeBase;
  setMoteur(modl.moteur);
  setPrixDeBase(prixDeBase);

   cout << "Je suis le constructeur par copie " << endl<<endl;
}


Modele::~Modele()//destructeur
{

  delete[] nom;
  cout << "Je suis le destructeur" << endl<<endl;
}

void Modele::Affiche (void)const
{
  cout << "Modele: " <<endl;
  cout << "Nom: " <<nom<<endl;
  cout << "Puissance: " <<puissance<<endl;
  cout << "Moteur: " <<moteur<<endl;
  cout << "Prix de base: " <<prixDeBase<<endl<<endl;
}

void Modele::setNom(const char* n)
{
  if(nom!=NULL)
  {
    delete nom;
  }
  nom= new char[strlen(n)+1];
  strcpy(nom,n);
}

char* Modele::getNom ()const
{
  return nom;
}
//-----------------------------
void Modele::setMoteur(Moteur m)
{
 	moteur= m;
}

int Modele::getMoteur()const
{
  return moteur;
}

//---------------------------------

void Modele::setPuissance(int p)
{
  if(p>0)
  {
    puissance=p;
  }
}

int Modele::getPuissance ()const
{
  return puissance;
 }
 //---------------------------------------
void Modele::setPrixDeBase(float prix)
{
  if(prix>0)
  {
    prixDeBase=prix;
  }

}

float Modele::getPrixDeBase ()const
{
 return prixDeBase;
}