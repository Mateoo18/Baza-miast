//
// Created by mateusz on 19.03.23.
//

#ifndef PROJECTC____WSIE_H
#define PROJECTC____WSIE_H
#include <iostream>
#include "Miasto.h"
#include "Aglomeracja.h"
using namespace std;
class Aglomeracja;
class Miasto;
class Wsie : public  Miasto {
    int id,budget;
public:
    void wypisz_nazwe1();
     //virtual void wypisz_woje();
     friend bool czy_zaprzyjaznione(int id_wies,int id_miasto);
    Wsie() {};
    Wsie(int ,int ,string ,string, int) ;
    ~Wsie();
    void wypisz_woje() override;

};


#endif //PROJECTC____WSIE_H
