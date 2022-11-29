
PROGAMS = Test1 Test2a Test2b Test2c Test3 Test4 Test5 Test6 Test7 Test8a

all: $(PROGAMS)

Test1:		Test1.cpp Modele.o
			g++ Test1.cpp Modele.o -o Test1

Test2a:		Test2a.cpp Voiture.o Modele.o Option.o
			g++ Test2a.cpp Voiture.o Modele.o Option.o -o Test2a

Test2b:		Test2b.cpp Option.o
			g++ Test2b.cpp Option.o -o Test2b


Test2c:		Test2c.cpp Option.o Voiture.o Modele.o
			g++ Test2c.cpp Option.o Voiture.o Modele.o -o Test2c

Test3:		Test3.cpp Voiture.o Modele.o Option.o
			g++ Test3.cpp Voiture.o Option.o Modele.o -o Test3

Test4:	Test4.cpp Personne.o Client.o Intervenant.o Employe.o
		g++ Test4.cpp Personne.o Client.o Intervenant.o Employe.o -o Test4

Test5: Test5.cpp Voiture.o Modele.o Option.o Personne.o Client.o Intervenant.o Employe.o Exception.o OptionException.o PasswordException.o 
		g++ Test5.cpp Voiture.o Modele.o Option.o Personne.o Client.o Intervenant.o Employe.o Exception.o OptionException.o PasswordException.o  -o Test5

Test6:	Test6.cpp Vecteur.o Client.o Intervenant.o Personne.o Iterateur.o
		g++ Test6.cpp Vecteur.o Client.o Intervenant.o Personne.o Iterateur.o -o Test6

Test7:		Test7.cpp Voiture.o Modele.o Option.o OptionException.o Exception.o
			g++ Test7.cpp Voiture.o Option.o Modele.o OptionException.o Exception.o -o Test7

Test8a:	Test8a.cpp Garage.o Modele.o Option.o Personne.o Client.o Intervenant.o Employe.o Iterateur.o Vecteur.o Exception.o OptionException.o PasswordException.o 
		g++ Test8a.cpp Garage.o Modele.o Option.o Personne.o Client.o Intervenant.o Employe.o Iterateur.o Vecteur.o Exception.o OptionException.o PasswordException.o  -o Test8a

Modele.o:	Modele.cpp Modele.h
			g++ Modele.cpp -c

Voiture.o:	Voiture.cpp Voiture.h
			g++ Voiture.cpp -c


Option.o:	Option.cpp Option.h
			g++ Option.cpp -c

Personne.o: Personne.cpp Personne.h 
			g++ Personne.cpp -c

Intervenant.o: Intervenant.cpp Intervenant.h
				g++ Intervenant.cpp -c

Client.o:	Client.cpp Client.h
			g++ Client.cpp -c


Employe.o:	Employe.cpp Employe.h
			g++ Employe.cpp -c

Exception.o:	Exception.cpp Exception.h
				g++ Exception.cpp -c

OptionException.o:	OptionException.cpp OptionException.h
					g++ OptionException.cpp -c


PasswordException.o:	PasswordException.cpp PasswordException.h
						g++ PasswordException.cpp -c


Vecteur.o:	Vecteur.cpp Vecteur.h
			g++ Vecteur.cpp -c


Iterateur.o:	Iterateur.cpp Iterateur.h
				g++ Iterateur.cpp -c

VecteurTrie.o:	VecteurTrie.cpp VecteurTrie.h
			g++ VecteurTrie.cpp -c

Garage.o:	Garage.cpp Garage.h
			g++ Garage.cpp -c
clean :
			rm -f *.o




