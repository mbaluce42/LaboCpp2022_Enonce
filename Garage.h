#ifndef GARAGE_H
#define GARAGE_H


#include <iostream>
#include "Client.h"
#include "Employe.h"
#include "Modele.h"
#include "Option.h"
#include "Vecteur.h"
#include "Iterateur.h"
using namespace std;


class Garage
{

 private:
        Vecteur<Employe> employes; //VecteurTrie<Employe> 
        Vecteur<Client> clients; // ou Vecteur<Client>
        Vecteur<Modele> modeles;
        Vecteur<Option> options;
 public:
        Garage();
        void ajouteModele(const Modele & m);
        void afficheModelesDisponibles() const;
        Modele getModele(int indice);

        void ajouteOption(const Option & o);
        void afficheOptionsDisponibles() const;
        Option getOption(int indice);

        void ajouteClient(string nom,string prenom,string gsm);
        void afficheClients() const;
        void supprimeClientParIndice(int ind);
        void supprimeClientParNumero(int num);

        void ajouteEmploye(string nom,string prenom,string login,string fonction);
        void afficheEmployes() const;
        void supprimeEmployeParIndice(int ind);
        void supprimeEmployeParNumero(int num);

};
#endif