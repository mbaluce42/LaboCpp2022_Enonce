#include "Modele.h"
#include "Voiture.h"
#include "Option.h"
#define DEBUG



Voiture::Voiture()//constructeur par defaut
{
  setNom("projet_RRPhantom2022_MrMbaya");
  for(int i=0;i<5;i++)
  {
    option[i]=NULL;
  }
  #ifdef DEBUG
  cout << "Je suis le contructeur par defaut VOITURE" << endl<<endl;
  #endif
}


/* contructeur d'initialisation | parametre*/
Voiture::Voiture(const string name, const Modele &modl)
{
  setNom(name);
  setModele(modl);
  for(int i=0;i<5;i++)
  {
    option[i]=NULL;
  }

  #ifdef DEBUG
  /*comme le contructeur par defaut sauf qu'il est parametre*/
  cout << "Je suis le contructeur d'initialisation VOITURE" << endl<<endl;
  #endif
}



void Voiture::setModele(const Modele &modl)
{
  
  modele.setNom(modl.getNom());
  modele.setPuissance(modl.getPuissance());
  modele.setMoteur(modl.getMoteur());
  modele.setPrixDeBase(modl.getPrixDeBase());
}

Modele Voiture::getModele()const
{
  return modele;
}


void Voiture::setNom(const string n)
{
  nom= n;
}

string Voiture::getNom ()const
{
  return nom;
}

Voiture::~Voiture()//destructeur
{
  for(int i=0;i<5;i++)
  {
    delete option[i];
  }
  #ifdef DEBUG
  cout << "Je suis le destructeur VOITURE" << endl<<endl;
  #endif
}

//contructeur de copie
Voiture::Voiture(const Voiture &voit)
{
    setNom(voit.getNom());
    setModele(voit.getModele()) ;
    for(int i=0; i<5; i++)
  {
    if(voit.option[i]!=NULL)
    {
      option[i] = new Option(*(voit.option[i]));
    }
    else option[i] = NULL;
  }

}

void Voiture::Affiche (void)const
{
  cout << "Voiture: " <<endl;
  cout << "Nom: " <<nom<<endl;

  modele.Affiche();

  for(int i=0; i<5; i++)
  {
    if(option[i]!=NULL)
    {
      option[i]->Affiche();
    }
    else
    {
      cout <<endl << "AUCUNE OPTION !!"<<endl;
    }
  }
}

void Voiture::AjouteOption(const Option &opt)
{
  int add=0, i ;
  Option *newElemOption = newElemOption=new Option(opt);
  //Option *tmpOption=NULL;

for(i=0;i<5 ;i++)
  {
    if(option[i] !=NULL && option[i]->getCode()== newElemOption->getCode())
    {
      //present= 1;
      throw OptionException("!!! Code de l'option deja existant !!!");
    }
  }

  for(i=0;i<5 && add==0 ;i++)
  {
    if(option[i]==NULL)
    {
      option[i]= newElemOption;
      add= 1;
      break;
    }
  }

 if(i>4)
  {
    throw OptionException("!!! Plus de place dans l'options (MAX 5) !!!");
  }
  
          
}

void Voiture::RetireOption(string code)
{
  int retire=0, i;

  for(i=0;i<5 && retire==0;i++)
  {
    if(option[i]!=NULL)
    {
      if(option[i]->getCode() == code)
      {

        delete option[i];
        option[i]=NULL;
        retire=1;
        break;
      }
    }
  }
  if (i>4)
  {
    throw OptionException("!!! Plus rien à retirer dans l'option !!!");
  }

  else if(retire=0)
  {
    throw OptionException("!!! L'Option recherche n’est pas présente !!!");

  }
  

}


float Voiture::getPrix()const
{
  float res=0;
  for(int i=0;i<5;i++)
  {
    if(option[i]!=NULL)
    {
      res= option[i]->getPrix() + res;

    }

  }

  res= res + modele.getPrixDeBase();

  return res;

}


Voiture& Voiture::operator=(const Voiture& v)
{
      setNom(v.nom);
      setModele(v.getModele());
      
      for(int i=0; i<5;i++)
      {
        if(option[i] != NULL)
        {
          delete option[i];
          option[i]=NULL;
        }

      }

      for(int i=0; i<5;i++)
      {
        if(v.option[i] != NULL)
        {
          option[i] = new Option(*(v.option[i]));
        }
        else option[i] = NULL;

      }


      return (*this);
}

Voiture operator+(const Voiture& v,const Option& o)
{
  Voiture voitCopie(v);
  voitCopie.AjouteOption(o);
  return voitCopie;
}


Voiture operator+(const Option& o, const Voiture& v)
{ 
  return v + o;
}


Voiture operator-(const Voiture& v, const Option& o)
{ 
  Voiture voitCopie(v);
  voitCopie.RetireOption(o.getCode());
  return voitCopie;
}

Voiture operator-(const Voiture& v, const string CodeOpt)
{ 
  Voiture voitCopie(v);
  voitCopie.RetireOption(CodeOpt);
  return voitCopie;
}


int Voiture::operator<(const Voiture& voit)
{
  int r=0;// d'office pas egal
  if((*this).getPrix() < voit.getPrix())
  {
    r=1;

  }
  return r;
}

int Voiture::operator>(const Voiture& voit)
{
  int r=0;// d'office pas egal
  if((*this).getPrix() > voit.getPrix())
  {
    r=1;

  }
  return r;
}

int Voiture::operator==(const Voiture& voit)
{
  int r=0;// d'office pas egal
  if((*this).getPrix()==voit.getPrix())
  {
    r=1;

  }
  return r;
}


ostream& operator<<(ostream& s, const Voiture& voit)
{
  s<<voit.nom;
  s<< voit.modele;

  for(int i=0; i<5; i++)
  {
    if(voit.option[i] != NULL)
    {
      s<< *voit.option[i];


    }
  }

  return s;

}

/*
istream& operator>>(istream& s, Voiture& voit)
{
  Voiture copieVoit;
  Option copieOption;


  cout<<"Saisissez les infos d'une Voiture: "<<endl;
  cout<<"Nom du projet: ";
  s>>copieVoit.nom;

  s>>copieVoit.modele;

  s>>copieOption;
  voit.setNom(copieVoit.getNom());

  voit.setModele(copieVoit.getModele());

  
  voit.AjouteOption(copieOption);

  return s;

}

*/

Option* Voiture::operator[](int i)
{
  return (*this).option[i];
}


void Voiture::Save()const
{
  string namefile= nom +".car";
  ofstream f (namefile, ios::out | ios::binary);

  if(!f)
  {
    cout<<"!!! ERREUR D'OUVERTURE FICHIER Voiture!!!"<<endl;
  }

  else
  {
    
    int taille= nom.size();
    f.write((char *)&taille,sizeof(int));
    f.write((char *)nom.data(),taille*sizeof(char));

    modele.Save(f);

    taille=0;

    for(int i=0; i<5;i++)
    {
      if(option[i] != NULL)
      {
        taille++;
      }
      
    }

    f.write((char *)&taille,sizeof(int));

    for(int i=0; i<5;i++)
    {
      if(option[i] != NULL)
      {
        option[i]->Save(f);
      }
      
    }

    cout<< ">>>Voiture: Save <<<"<<endl;

    

  }

  f.close();

  
}

void Voiture::Load(string nomFichier)
{
  ifstream f (nomFichier, ios::in | ios::binary);

  if(!f)
  {
    cout<<"!!! ERREUR D'OUVERTURE FICHIER "<<nomFichier <<"!!!"<<endl;
  }

  else
  {
    int t;

    f.read((char *)&t, sizeof(int));
    nom.resize(t);
    f.read((char *)nom.data(), t*sizeof(char));

    modele.Load(f);

    Option temp[5];

    
    f.read((char *)&t, sizeof(int));
      for(int i=0; i<t;i++)
      {
  
        temp[i].Load(f);
        AjouteOption(temp[i]);
      }


    cout<< ">>>Voiture: Load <<<"<<endl;

  }

  f.close();


}


