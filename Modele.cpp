#include "Modele.h"
#define DEBUG



Modele::Modele()//constructeur par defaut
{

  nom= NULL;
  setNom("");
  setPuissance(100);
  //moteur= Essence;
  setMoteur(moteur);
  setPrixDeBase(prixDeBase);
  //prixDeBase=445.97;
  #ifdef DEBUG
  cout << "Je suis le contructeur par defaut MODELE" << endl<<endl;
  #endif
}

/* contructeur d'initialisation | parametre*/
Modele::Modele(const char* name, int p, Moteur m,float prix)
{
  nom= NULL;
  setNom(name);
  setPuissance(p);
  setMoteur(m);
  setPrixDeBase(prix);

  #ifdef DEBUG
  /*comme le contructeur par defaut sauf qu'il est parametre*/
  cout << "Je suis le contructeur d'initialisation MODELE" << endl<<endl;
  #endif
}

/*contructeur de copie*/
/*Syntaxe fonction--> nomClasse (const nomClasse & autre_objet); */
Modele::Modele(const Modele &modl)
{
  nom= NULL;
  setNom(modl.nom);
  setPuissance(modl.puissance);
  setMoteur(modl.moteur);
  setPrixDeBase(modl.prixDeBase);

  #ifdef DEBUG
   cout << "Je suis le constructeur par copie MODELE " << endl<<endl;
   #endif
}


Modele::~Modele()//destructeur
{
	if(nom !=NULL)
	{
		delete[] nom;
		#ifdef DEBUG
  		cout << "Je suis le destructeur MODELE" << endl<<endl;
  		#endif

	}
}

void Modele::Affiche(void)const
{
  cout << "\nModele: " <<endl;
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

Moteur Modele::getMoteur()const
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


ostream& operator<<(ostream& s, const Modele& mod)
{
  s<<"Modele: "<<endl;
  s<<"Nom: "<<mod.nom<< endl;
  s<< "Puissance "<<mod.puissance<<endl;

  switch(mod.moteur)
  {
    case 0:
    s<<"Moteur: Essence"<< endl;
    break;

    case 1:
    s<<"Moteur: Diesel"<<endl;
    break;

    case 2:
    s<<"Moteur: Electrique"<<endl;
    break;


    case 3:
    s<<"Moteur: Hybride"<<endl;
    break;
  }
  s<<"Prix de Basse: "<<mod.prixDeBase<<endl;

  return s;
}



istream& operator>>(istream& s, Modele& mod)
{
  int checkMoteur=0;
  int err=0;
  cout<<"Saisissez les infos d'un Modele: "<<endl;
  cout<<"Nom: ";
  
  s.getline(mod.nom,25);//istream& getline(char*, int size,/*char='\n*/)
  mod.setNom(mod.getNom());

  cout<< endl <<"Puissance: ";
  s>>mod.puissance;
  mod.setPuissance(mod.getPuissance());

    cout<<endl <<"Moteur (0==Essence || 1==Diesel || 2==Electrique || 3==Hybride) :";
    fflush(stdin);
    s>>checkMoteur;

    switch(checkMoteur)
    {
      case 0:
      cout<<"Moteur==Essence"<< endl ;
      err=0;
      break;

      case 1:
      cout<<"Moteur== Diesel"<< endl;
      err=0;
      break;

      case 2:
      cout<<"Moteur== Electrique"<< endl;
      err=0;
      break;


      case 3:
      cout<<"Moteur== Hybride"<<endl;
      err=0;
      break;

      default:
      err=-1;
      cout<<endl <<"!!! ERREUR !!! AUCUN MOTEUR ASSOCIER AU NUM ENTREE"<<endl;
      break;
    }

  mod.moteur=(Moteur)checkMoteur;
  mod.setMoteur(mod.getMoteur());


  cout<<endl <<"Prix de Basse: ";
  s>>mod.prixDeBase;
  mod.setPrixDeBase(mod.getPrixDeBase());

  return s;


}



void Modele::Save(ofstream& fichier)const
{
  if(!fichier)
  {
    cout<<"!!! ERREUR D'OUVERTURE FICHIER Modele!!!"<<endl;
  }

  else
  {
    int taille= strlen(nom);
    fichier.write((char *)&taille,sizeof(int));
    fichier.write((char *)nom,taille*sizeof(char));

    fichier.write((char *)&puissance,sizeof(int));
    fichier.write((char *)&moteur,sizeof(Moteur));
    fichier.write((char *)&prixDeBase,sizeof(float));
    cout<< ">>>Modele : Save <<<"<<endl;
  }


  
}

void Modele::Load(ifstream& fichier)
{
  if(!fichier)
  {
    cout<<"!!! ERREUR D'OUVERTURE FICHIER Modele!!!"<<endl;
  }

  else
  {
    int t;

    fichier.read((char *)&t, sizeof(int));
    nom= new char[t+1];
    fichier.read((char *)nom, t*sizeof(char));
    
    fichier.read((char *)&puissance,sizeof(int));
    fichier.read((char *)&moteur,sizeof(Moteur));
    fichier.read((char *)&prixDeBase,sizeof(float));
    cout<< ">>>Modele : Load <<<"<<endl;

  }


}
