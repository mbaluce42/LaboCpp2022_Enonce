#include "Client.h"
#define DEBUG


/*constructeur par defaut*/
Client::Client()
{
	setGsm("0000/00.00.00");
	#ifdef DEBUG
  cout << "Je suis le contructeur par defaut Client" << endl<<endl;
  #endif
}

/* contructeur d'initialisation | parametre*/
Client::Client(const string n, const string pren,const int num,const string phone) : Intervenant(n,pren,num)
{
	setGsm(phone);
	#ifdef DEBUG
  cout << "Je suis le contructeur d'initialisation Client" << endl<<endl;
  #endif
 }

/*Constructeur de copie*/
Client::Client(const Client &cli) : Intervenant(cli)
{
 /* setNumero(cli.getNumero());
  setNom(cli.getNom());
  setPrenom(cli.getPrenom());*/
	setGsm(cli.getGsm());

	#ifdef DEBUG
  	cout << "Je suis le contructeur de copie Client" << endl<<endl;
  	#endif
}

/*destructeur*/
Client::~Client()
{
	#ifdef DEBUG
  	cout << "Je suis le destructeur Client" << endl<<endl;
  	#endif

}

string Client::Tuple()// fct virtuelle pure
{
	return " " + to_string((*this).getNumero())+ ";" + (*this).getNom() + ';' + (*this).getPrenom() + ";" + (*this).gsm;
}

string Client::ToString()// fct virtuelle pure
{
	return "[C" + to_string((*this).getNumero()) + "] " + (*this).getNom() + " " + (*this).getPrenom();	

}

void Client::setGsm(const string phone)
{
	gsm=phone;
}

string Client::getGsm()const
{
	return gsm;
}

Client& Client::operator=(const Client& cli)
{
	Intervenant::operator=(cli);
/*	setNumero(cli.getNumero());
  setNom(cli.getNom());
  setPrenom(cli.getPrenom());*/
	setGsm(cli.getGsm());

	return (*this);

}

ostream& operator<<(ostream& s, const Client& cli)
{

  s<<endl<<"info client:"<<endl;

  s<<"numero client: "<<cli.getNumero()<<endl;
  s<<"Nom: "<<cli.getNom()<<endl;
  s<<"Prenom: "<<cli.getPrenom()<<endl;
  s<<"Numero GSM: "<<cli.getGsm()<<endl;


  return s;

}