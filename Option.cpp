#include "Option.h"
#define DEBUG


/*constructeur par defaut*/
Option::Option()
{
  setCode("RR22");
  setIntitule("Peinture chrome");
  setPrix(4544);
  #ifdef DEBUG
  cout << "Je suis le contructeur par defaut OPTION" << endl<<endl;
  #endif
}


/* contructeur d'initialisation | parametre*/
Option::Option(const string optCode, const string intitul, const float money)
{
  setCode(optCode);
  setIntitule(intitul);
  setPrix(money);

  #ifdef DEBUG
  /*comme le contructeur par defaut sauf qu'il est parametre*/
  cout << "Je suis le contructeur d'initialisation OPTION" << endl<<endl;
  #endif
}

Option::Option(const Option &opt)
{
    setCode(opt.getCode());
    setIntitule(opt.getIntitule());
    setPrix(opt.getPrix());
}


string Option::getCode ()const
{
  return code;
}
        
string Option::getIntitule ()const
{
  return intitule;
}        

float Option::getPrix()const
{
  return prix;
}


void Option::setCode(const string optCode)
{
  
  if(optCode.size()!=4)
  {
    throw OptionException("!!Erreur!! taille du Code incorrecte (il faut que 4 lettres)");
  }

  code=optCode;

}
        
void Option::setIntitule(const string intitul)
{

  if(intitul.size() == 0)
  {
    throw OptionException("!!Erreur!! il faut au moin 1 lettre");
  }
  intitule=intitul;

}
      
void Option::setPrix(const float money)
{
  if(money<0)
  {
    throw OptionException("!!Erreur!! Prix negatif IMPOSSIBLE");
  }
  prix=money;
}


Option::~Option()//destructeur
{
  #ifdef DEBUG
  cout << "Je suis le destructeur OPTION" << endl<<endl;
  #endif
}


void Option::Affiche(void)const
{
  //cout << "Option: " <<endl;
  cout <<endl << "Code: " <<code<<endl;
  cout << "Intitule: " <<intitule<<endl;
  cout << "Prix: " <<prix<<endl;

}



ostream& operator<<(ostream& s, const Option& opt)
{
  s<<"Otion: "<<endl;
  s<< endl <<"Code: " <<opt.code<< endl;
  s<< "Intitule: " <<opt.intitule<<endl;
  s<< "Prix: "<<opt.prix<<endl;

  return s;
}


istream& operator>>(istream& s, Option& opt)
{
  

  cout<<"Saisissez les infos d'une Option: "<<endl;
  
  fflush(stdin);
  cout<<"Code: ";
  //s.ignore();
  
  getline(s,opt.code);
  opt.setCode(opt.getCode());

  cout<<"\nIntitule: ";
  getline(s,opt.intitule);
  //cin.ignore();
  opt.setIntitule(opt.getIntitule());

 
  cout<<"\nPrix: ";
  s>>opt.prix;
  opt.setPrix(opt.getPrix());


  return s;

}


Option Option::operator--()//pre-incrementation ex: ++D
{
  (*this).prix= ((*this).prix) - 50.0f;
  if( (*this).prix < 0)
  {
    throw OptionException("!!Erreur!! La diminution de prix a entraine un prix negatif");
  }

  return (*this);
}


Option Option::operator--(int)//post-incrementation ex: D++
{
  Option temp(*this); //copie non modifiee de l'objet courant

  (*this).prix= ((*this).prix) - 50.0f ;

  return temp;

}


void Option::Save(ofstream& fichier)const
{
  if(!fichier)
  {
    cout<<"!!! ERREUR D'OUVERTURE FICHIER Option!!!"<<endl;
  }

  else
  {
    int taille= code.size();
    fichier.write((char *)&taille,sizeof(int));
    fichier.write((char *)code.data(),taille*sizeof(char));


    taille=intitule.size();
    fichier.write((char *)&taille,sizeof(int));
    fichier.write((char *)intitule.data(),taille*sizeof(char));

    fichier.write((char *)&prix,sizeof(float));
    cout<< ">>>Option : Save <<<"<<endl;

  }


  
}

void Option::Load(ifstream& fichier)
{
  if(!fichier)
  {
    cout<<"!!! ERREUR D'OUVERTURE FICHIER Option!!!"<<endl;
  }

  else
  {
    
    int t;

    fichier.read((char *)&t, sizeof(int));
    code.resize(t);
    fichier.read((char *)code.data(), t*sizeof(char));
    

    fichier.read((char *)&t, sizeof(int));
    intitule.resize(t);
    fichier.read((char *)intitule.data(), t*sizeof(char));

    fichier.read((char *)&prix, sizeof(float));

    cout<< ">>>Option : Load <<<"<<endl;
  

  }


}





