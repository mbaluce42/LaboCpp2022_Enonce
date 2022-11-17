#include "Personne.h"
#define DEBUG


/*constructeur par defaut*/
Personne::Personne()
{
    setNom("Mbaya");
    setPrenom("Luce");
    #ifdef DEBUG
    cout << "Je suis le contructeur par defaut Personne" << endl<<endl;
    #endif
}


/* contructeur d'initialisation | parametre*/
Personne::Personne(const string n, const string pren)
{
  setNom(n);
  setPrenom(pren);

    #ifdef DEBUG
    /*comme le contructeur par defaut sauf qu'il est parametre*/
    cout << "Je suis le contructeur d'initialisation Personne" << endl<<endl;
    #endif
}

/*Constructeur de copie*/
Personne::Personne(const Personne &pers)
{
    setNom(pers.getNom());
    setPrenom(pers.getPrenom());

    #ifdef DEBUG
    /*comme le contructeur par defaut sauf qu'il est parametre*/
    cout << "Je suis le contructeur de copie Personne" << endl<<endl;
    #endif
}

void Personne::setNom(const string PersNom)
{
  nom=PersNom;

}
string Personne::getNom()const
{
  return nom;
}

void Personne::setPrenom(const string PersPrenom)
{
  prenom=PersPrenom;
}

string Personne::getPrenom()const
{
  return prenom;

}

/*destructeur*/
Personne::~Personne()
{
  #ifdef DEBUG
  cout << "Je suis le destructeur Personne" << endl<<endl;
  #endif
}


void Personne::Affiche(void)const
{
  //cout << "Personne: " <<endl;
  cout <<endl << "Nom: " <<nom<<endl;
  cout << "Prenom: " <<prenom<<endl;

}



ostream& operator<<(ostream& s, const Personne& p)
{
  s<<"Personne: "<<endl;
  s<< endl <<"Nom: " <<p.nom<< endl;
  s<< "Prenom: " <<p.prenom<<endl;
  return s;
}



istream& operator>>(istream& s, Personne& p)
{
  string tmpNom, tmpPrenom;


  cout<<"Saisissez les infos d'une Personne: "<<endl;
  
  cout<<"Nom: ";
  //s.ignore();
  
  getline(s,tmpNom);
  //s.ignore();

  cout<<endl<<"Prenom: ";
  getline(s,tmpPrenom);
  //s.ignore();


  p.setNom(tmpNom);
  p.setPrenom(tmpPrenom);

  return s;

}


Personne& Personne::operator=(const Personne& p)
{
      setNom(p.nom);
      setPrenom(p.prenom);

      return (*this);
}

