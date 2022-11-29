#include"Iterateur.h"

#define DEBUG


/*Construction copie*/
template<class T>
Iterateur<T>::Iterateur(Vecteur<T>& vect): vec(vect), pVec(vec.v)
{

  #ifdef DEBUG
  cout << "Je suis le contructeur de copie Iterateur" << endl<<endl;
  #endif

}


template<class T>
void Iterateur<T>::reset()
{
  pVec=vec.v;
}


template<class T>
int Iterateur<T>::end()
{
  if(pVec - vec.v == vec._size)
  {
    return 1;

  }  
  return 0;

}

template<class T>
void Iterateur<T>::operator++()//pre-incrementation ex: ++D
{
   pVec++;

}

template<class T>
Iterateur<T>::operator T()const
{
  return *pVec;
}

template<class T>
void Iterateur<T>::operator++(int)
{
  return operator++();
}



template class Iterateur<int>;
template class Iterateur<Client>;
template class Iterateur<Employe>;