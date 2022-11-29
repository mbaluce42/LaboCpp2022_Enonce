#ifndef MODELE_H
#define MODELE_H

#include <iostream>
#include <cstring>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

enum Moteur { Essence, Diesel, Electrique, Hybride };

class Modele
{
private:
        char* nom;
        int puissance;
        Moteur moteur;
        float prixDeBase;
public:
        Modele();//constructeur par defaut

         /* contructeur d'initialisation | parametre*/
         Modele(const char* name, int p, Moteur m,float prix);
        
        //-----------------------------------------------------------------
         /*contructeur de copie*/
         /*Syntaxe fonction--> nomClasse (const nomClasse & autre_objet); */
         Modele(const Modele &modl);

      
          void setNom(const char* n);
          char* getNom ()const;
        
          //-----------------------------
          void setMoteur(Moteur m);
          Moteur getMoteur()const;
         
          //---------------------------------

          void setPuissance(int p);
          int getPuissance ()const;
          
          //---------------------------------------
          void setPrixDeBase(float prix);
          float getPrixDeBase ()const;
          //-----------------------------------------

          
         ~Modele();//destructeur

         void Affiche(void)const;


        friend ostream& operator<<(ostream& s, const Modele& mod);

        friend istream& operator>>(istream& s, Modele& mod);

        void Save(ofstream& fichier)const;
        void Load(ifstream& fichier);

};
#endif



