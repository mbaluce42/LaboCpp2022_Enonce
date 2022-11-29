#ifndef ITERATEUR_H
#define ITERATEUR_H


#include <iostream>
#include "Vecteur.h"
#include "Client.h"
#include "Employe.h"
using namespace std;



template<class T> 
class Iterateur
{

private:
        Vecteur<T>& vec;
        T* pVec;


public :
        
        /*Construction copie*/
        Iterateur(Vecteur<T>& vect);
    

        void reset();

        int end();


        operator T() const;

        void operator++();

        void operator++(int);


};
#endif