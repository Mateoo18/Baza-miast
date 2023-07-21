
#include <iostream>
#include "Miasto.h"
using namespace std;

void Miasto::wypisz_nazwe() {
    cout<<"Nazwa miasta: "<< nazwa<<endl;
}
Miasto:: Miasto(int IDD,int liczba_miesz,string nazwa_mia,string woj,int budzet)
{
    budget=budzet;
    ID=IDD;
    nazwa=nazwa_mia;
    wojewodztwo=woj;
    if(liczba_miesz<0)cout<<"Prosze podać poprawna liczba mieszkancow";
    else liczba_mieszkancow=liczba_miesz;
}

Miasto::~Miasto() {

}

void Miasto::wypisz_woje() {
    cout<<wojewodztwo<<endl;
}
