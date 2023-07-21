
#ifndef PROJECTC____MIASTO_H
#define PROJECTC____MIASTO_H
#include <iostream>
#include "Aglomeracja.h"
using namespace std;
class Aglomeracja;
class Miasto : public Aglomeracja
        {
private:
    int ID;
    int budget;
public:
string nazwa;
string wojewodztwo;
int liczba_mieszkancow;
void wypisz_nazwe();

bool operator ==(Miasto mm)
{
    if(liczba_mieszkancow==mm.liczba_mieszkancow)
    {
        return true;
    }
    else
    {
        return false;
    }
}

virtual void wypisz_woje();
     friend bool czy_zaprzyjaznione(int id_wies,int id_miasto);
Miasto(){};
Miasto(int ,int ,string ,string ,int);
~Miasto();


};


#endif //PROJECTC____MIASTO_H
