#include "Vecteur.h"
#define DEBUG


/*constructeur par defaut*/
	template <class T>
	Vecteur<T>::Vecteur()
	{
		_sizeMax=10;
		_size=0;
		v= new T[_sizeMax];
		#ifdef DEBUG
  		cout << "Je suis le contructeur par defaut Vecteur" << endl<<endl;
  		#endif
	}

	template <class T>
	/* contructeur d'initialisation | parametre*/
	Vecteur<T>::Vecteur(const int n)
	{
		_sizeMax=n;
		_size=0;
		v=new T[_sizeMax];
		#ifdef DEBUG
  		cout << "Je suis le contructeur d'initialisation Vecteur" << endl<<endl;
  		#endif

	}
	
	template <class T>
	/*Constructeur de copie*/
	Vecteur<T>::Vecteur(const Vecteur& vec)
	{
		_size=vec.size();
		_sizeMax=vec.sizeMax();
		v= new T[vec.sizeMax()];
		for(int i=0; i<vec.size();i++)
    	{
    		v[i]= vec.v[i];
    		
    	}
    			
		#ifdef DEBUG
  		cout << "Je suis le contructeur de copie Vecteur" << endl<<endl;
  		#endif

	}
	
	

	template <class T>
	/*destructeur*/
	Vecteur<T>::~Vecteur()
	{
		delete [] v;
		#ifdef DEBUG
  		cout << "Je suis le destructeur Vecteur" << endl<<endl;
  		#endif

	}


	template <class T>
	int Vecteur<T>::size()const
	{
		return _size;
	}


	template <class T>
	int Vecteur<T>::sizeMax()const
	{
		return _sizeMax;
	}

     
    template <class T>
	void Vecteur<T>::insere(const T& val)
    {
    	if(_size<sizeMax())
    	{
    		v[_size]= val;
    		_size ++;
    	}

    }

    template <class T>
	T Vecteur<T>::retire(int ind)
    {
    	T tmp;

    	if((*this)._size != 0 && ind>=0 )
    	{
    		tmp= (*this).v[ind];
    	

    		for(int i=ind; i<(*this).size();i++)
    		{
    	
    			(*this).v[i]= (*this).v[i+1];
   
    		}

    		
    	}
    	(*this)._size--;
    	return tmp;


    }

    template <class T>
    T& Vecteur<T>::operator=(const Vecteur& vec)
    {
    	delete [] v;
    	
    	(*this)._sizeMax=vec.sizeMax();
    	(*this)._size= vec.size();

    	
    	for(int i=0; i<vec.size(); i++)
  		{
  			(*this).v[i]=vec.v[i];
    	}    

    	return *this->v;
    }


    template <class T>
    T Vecteur<T>::operator[](int i)
    {
    	return *(v+i);
    }

   

    template <class T>
    void Vecteur<T>::Affiche()const
    {
    	for(int i=0; i<size(); i++)
  		{
    		cout<< "vec[" << i<<"]= "<<v[i]<<endl;
    	}    
    	cout<< endl;
    }

    template class Vecteur<int>;
    template class Vecteur<Client>;
    template class Vecteur<Employe>;
    template class Vecteur<Option>;
    template class Vecteur<Modele>;