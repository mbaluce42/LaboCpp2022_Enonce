#ifndef VECTEUR_H
#define VECTEUR_H


#include <iostream>
#include "Client.h"
#include "Employe.h"
#include "Option.h"
#include "Modele.h"
using namespace std;

template<class T> class Iterateur;

template<class T> class Vecteur
{
private :
            T * v;
            int _sizeMax;
            int _size;
 
public :

        //constructeur par defaut
        Vecteur();

        /* contructeur d'initialisation | parametre*/
        Vecteur(const int n);

        /*Construction copie*/
        Vecteur(const Vecteur& vec);
    
        /*destructeur*/
        ~Vecteur();

        /*getter*/
        int size()const;
        int sizeMax()const;

        void insere(const T& val);

        T retire(int ind);

        T& operator=(const Vecteur& vec);

        T operator[](int i);
        /*Client operator[](int i);*/

        void Affiche()const;

        friend class Iterateur<T>;


};
#endif
