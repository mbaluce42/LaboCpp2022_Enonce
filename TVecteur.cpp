#include "Vecteur.h"
#include "Client.h"
//#define DEBUG



/*constructeur par defaut*/
	template <class T>
	TVecteur<T>::TVecteur()
	{
		_sizeMax=10;
		_size=0;
		v= new T[_sizeMax];
		#ifdef DEBUG
  		cout << "Je suis le contructeur par defaut TVecteurr" << endl<<endl;
  		#endif
	}

	template <class T>
	/* contructeur d'initialisation | parametre*/
	TVecteur<T>::TVecteur(const int n)
	{
		_sizeMax=n;
		_size=0;
		v=new T[_sizeMax];
		#ifdef DEBUG
  		cout << "Je suis le contructeur d'initialisation TVecteur" << endl<<endl;
  		#endif

	}
	
	template <class T>
	/*Constructeur de copie*/
	TVecteur<T>::TVecteur(const TVecteur& vec)
	{
		_size=vec.size();
		_sizeMax=vec.sizeMax();
		v= new T[vec.sizeMax()];
		for(int i=0; i<vec.size();i++)
    	{
    		v[i]= vec.v[i];
    		
    	}
    			
		#ifdef DEBUG
  		cout << "Je suis le contructeur de copie TVecteur" << endl<<endl;
  		#endif

	}
	
	

	template <class T>
	/*destructeur*/
	TVecteur<T>::~TVecteur()
	{
		delete [] v;
		#ifdef DEBUG
  		cout << "Je suis le destructeur TVecteur" << endl<<endl;
  		#endif

	}


	template <class T>
	int TVecteur<T>::size()const
	{
		return _size;
	}


	template <class T>
	int TVecteur<T>::sizeMax()const
	{
		return _sizeMax;
	}

     
    template <class T>
	void TVecteur<T>::insere(const T& val)
    {
    	if(_size<sizeMax())
    	{
    		if(_size==0)
    		{
    			v[_size]= val;
    			_size ++;
    		}


    		else
    		{
    			for(int i=0; i<(*this).size();i++)
    			{
    				if()
    				(*this).v[i]= (*this).v[i+1];
   
    			}
    		}

    		
    	}

    }

    template <class T>
	T TVecteur<T>::retire(int ind)
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
    T& TVecteur<T>::operator=(const TVecteur& vec)
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
    T TVecteur<T>::operator[](int i)
    {
    	return *(v+i);
    }

   

    template <class T>
    void TVecteur<T>::Affiche()const
    {
    	for(int i=0; i<size(); i++)
  		{
    		cout<< "vec[" << i<<"]= "<<v[i]<<endl;
    	}    
    	cout<< endl;
    }



    template class TVecteur<int>;
    template class TVecteur<Client>;