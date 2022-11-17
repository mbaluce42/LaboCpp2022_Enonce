#ifndef VOITURE_H
#define VOITURE_H
#include <iostream>
#include <cstring>
#include <string>
#include "Modele.h"
#include "Option.h"
#include "OptionException.h"
using namespace std;



class Voiture
{
private:
        string nom;
        Modele modele;
        Option* option[5];
public:

        Voiture();//constructeur par defaut

        /* contructeur d'initialisation | parametre*/
        Voiture(const string name, const Modele &modl);
        
        /*constructeur de copie*/
        Voiture(const Voiture &voit);
 
        Voiture& operator=(const Voiture& v);
        friend Voiture operator+(const Voiture& v,const Option & o);
        friend Voiture operator+(const Option & o, const Voiture& v);
        friend Voiture operator-(const Voiture& v, const Option& o);
        friend Voiture operator-(const Voiture& v, const string CodeOpt);
        int operator<(const Voiture& voit);
        int operator>(const Voiture& voit);
        int operator==(const Voiture& voit);




        void setModele(const Modele &modl);


        Modele getModele()const;


        void setNom(const string n);

        string getNom ()const;

        void Affiche (void)const;

        ~Voiture();//destructeur

        
        void AjouteOption(const Option &opt);

        void RetireOption(string code);

        float getPrix()const;

        friend ostream& operator<<(ostream&  s, const Voiture& voit);

        //friend istream& operator>>(istream& s, Voiture& voit);

        Option *operator[](int i);



};
#endif



