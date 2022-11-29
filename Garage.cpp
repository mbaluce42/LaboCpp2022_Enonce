
#include "Garage.h"
#define DEBUG





Garage::Garage()
{

	#ifdef DEBUG
  	cout << "Je suis le contructeur par defaut Garage	" << endl<<endl;
  	#endif
}
        
void Garage::ajouteModele(const Modele & m)
{
	modeles.insere(m);

}
void Garage::afficheModelesDisponibles() const
{
	modeles.Affiche();

}

void Garage::ajouteOption(const Option & o)
{
	options.insere(o);

}

void Garage::afficheOptionsDisponibles() const
{
	options.Affiche();


}
        
Option Garage::getOption(int indice)
{
	return options[indice];


}

void Garage::ajouteClient(string nom,string prenom,string gsm) 
{
	clients.insere(Client(nom,prenom,gsm));


}
        
void Garage::afficheClients() const
{
	clients.Affiche();
	// regarde dans le constructeur paramettrer avec static
}

void Garage::supprimeClientParIndice(int ind)
{
	clients.retire(ind);

}
        
void Garage::supprimeClientParNumero(int num)
{
	Iterateur<Client> it(clients);
	int i=0;
  	for (it.reset() ; !it.end() ; it++)
  	{
    	Client c = (Client)it;
    	if(c.getNumero()== num)
    	{
    		clients.retire(i);
    	}
    	i++;
  	}


}


void Garage::ajouteEmploye(string nom,string prenom,string login,string fonction) 
{
	employes.insere(Employe(nom,prenom,login,fonction));
	//vec.insere(Client("Wagner","Jean-Marc",1,"0498.25.36.23"));


}   

void Garage::afficheEmployes() const
{
		
	employes.Affiche();
	
}
        

void Garage::supprimeEmployeParIndice(int ind)
{
	employes.retire(ind);

}

void Garage::supprimeEmployeParNumero(int num)
{
	Iterateur<Employe> it(employes);
	int i=0;
  for (it.reset() ; !it.end() ; it++)
  {
    Employe e = (Employe)it;
    if(e.getNumero()== num)
    {
    	employes.retire(i);
    }
    i++;
  }

}