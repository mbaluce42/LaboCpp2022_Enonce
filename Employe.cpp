
#include "Employe.h"
#define DEBUG





const string Employe::ADMINISTRATIF="Administatif";
const string Employe::VENDEUR= "Vendeur";


/*constructeur par defaut*/
Employe::Employe()
{

	setLogin("mbaLuc");
	motDePasse= NULL;

	setFonction("Administratif");
	#ifdef DEBUG
  	cout << "Je suis le contructeur par defaut Employe	" << endl<<endl;
  	#endif
	}

	/* contructeur d'initialisation | parametre*/
Employe::Employe(const string n, const string pren,const int num,const string l,const string fct) : Intervenant(n,pren,num)
{
	motDePasse=NULL;
	setLogin(l);

	setFonction(fct);
	#ifdef DEBUG
  	cout << "Je suis le contructeur d'initialisation Employe " << endl<<endl;
  	#endif
	}

/*Constructeur de copie*/
Employe::Employe(const Employe &empl) : Intervenant(empl)
{
	motDePasse=NULL;
	setLogin(empl.getLogin());
	/*if (empl.motDePasse != NULL) */setMotDePasse(empl.getMotDePasse());
	setFonction(empl.getFonction());

	/*setNumero(empl.getNumero());
  	setNom(empl.getNom());
  	setPrenom(empl.getPrenom());*/

	#ifdef DEBUG
  	cout << "Je suis le Constructeur de copie Employe " << endl<<endl;
  	#endif

	}

/*destructeur*/
Employe::~Employe()
{
	delete motDePasse;
	#ifdef DEBUG
 	cout << "Je suis le destructeur Employe" << endl<<endl;
  	#endif

}

string Employe::Tuple()
{
	return " " + to_string((*this).getNumero())+ ";" + (*this).getNom() + ';' + (*this).getPrenom() + ";" + (*this).getFonction();

}
string Employe::ToString()// fct virtuelle pure Intervenant
{
	if( ((*this).getFonction()) == "Vendeur")
	{
		return "[V" + to_string((*this).getNumero()) + "] " + (*this).getNom() + " " + (*this).getPrenom();	

	}

	else// c'est un Administratif
	{
		return "[A" + to_string((*this).getNumero()) + "] " + (*this).getNom() + " " + (*this).getPrenom();

	}
	

}


void Employe::setLogin(const string l)
{
	login=l;
}
string Employe::getLogin()const
{
	return login;
}

void Employe::setMotDePasse(const string mdp)
{
	int i, lettre=0, chiffre=0;

	if(mdp.size()<6)
	{
		throw PasswordException("!! Minimum 6 caracteres pour votre Mot De Passe !!", PasswordException::INVALID_LENGTH);
	}

	while(i<=mdp.size() && mdp[i]!= '\0')
	{
		if(mdp[i]=='1' || mdp[i]=='2' || mdp[i]=='3' || mdp[i]=='4' || mdp[i]=='5' || mdp[i]=='6' || mdp[i]=='7' || mdp[i]=='8' || mdp[i]=='9' || mdp[i]=='0' )
		{
			chiffre=1;

		}

		if( mdp[i]>=0x41 && mdp[i]<=0x5A || mdp[i]>=0x61 && mdp[i]<=0x7A ) //MAJ ou minus
		{
			lettre= 1;
		}
		i++;
	}

  if(chiffre==0)
  {
  	throw PasswordException("!! Le Mot De Passe doit contenir au moin un chiffre !!", PasswordException::DIGIT_MISSING);
  }

  if(lettre==0)
  {
  	throw PasswordException("!! Le Mot De Passe doit contenir au moin une lettre !!", PasswordException::ALPHA_MISSING);
  }

	if(motDePasse!=NULL)
  {
    delete motDePasse;
  }
 	motDePasse= new string(mdp);

}

string Employe::getMotDePasse()const
{
	if(motDePasse==NULL)
	{
		throw PasswordException("!! Aucun Mot De Passe !!", PasswordException::NO_PASSWORD);

	}
	return *motDePasse;
}

void Employe::ResetMotDePasse()
{
	//motDePasse=NULL;
	if(motDePasse != NULL)	delete motDePasse;

	motDePasse=NULL;

}

void Employe::setFonction(const string fct)
{
		fonction= fct;

}
string Employe::getFonction()const
{
	return fonction;
}

Employe& Employe::operator=(const Employe& empl)
{
	Intervenant::operator=(empl);
	/*setNumero(empl.getNumero());
  	setNom(empl.getNom());
  	setPrenom(empl.getPrenom());*/
	setLogin(empl.getLogin());
	setMotDePasse(empl.getMotDePasse());
	setFonction(empl.getFonction());

	return (*this);

}

ostream& operator<<(ostream& s, const Employe& empl)
{

  s<<endl<<"info employe:"<<endl;

  s<<"numero employe: "<<empl.getNumero()<<endl;
  s<<"Nom: "<<empl.getNom()<<endl;
  s<<"Prenom: "<<empl.getPrenom()<<endl;
  s<<"Login: "<<empl.getLogin()<<endl;
  if(empl.motDePasse==NULL) s<<"MotDePasse: "<<"Pas de MDP"<<endl;
  else
  {
  	s<<"MotDePasse: "<<empl.getMotDePasse()<<endl;
  }
  
  s<<"Fonction: "<<empl.getFonction()<<endl;


  return s;

}