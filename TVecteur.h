#ifndef TVECTEUR_H
#define TVECTEUR_H


#include <iostream>
#include "Client.h"
using namespace std;


template<class T> class Iterateur;

template<class T> class TVecteur
{

private:

        T* v;
        int _sizeMax;
        int _size;
 
public :

        //constructeur par defaut
        TVecteur();

        /* contructeur d'initialisation | parametre*/
        TVecteur(const int n);

        /*Construction copie*/
        TVecteur(const TVecteur& vec);
    
        /*destructeur*/
        ~TVecteur();

        /*getter*/
        int size()const;
        int sizeMax()const;

        void insere(const T& val);

        T retire(int ind);

        T& operator=(const TVecteur& vec);

        T operator[](int i);
        /*Client operator[](int i);*/

        void Affiche()const;




        friend class Iterateur<T>;
        


};
#endif
