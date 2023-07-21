//
// Created by mateusz on 19.03.23.
//

#include "Wsie.h"
#include "Miasto.h"
#include <iostream>

using namespace std;
    void Wsie::wypisz_nazwe1() {
        cout << "Nazwa miasta: " << nazwa << endl;
    }

    Wsie::Wsie(int IDD, int liczba_miesz, string nazwa_mia, string woj,int budzet) : Miasto( IDD, liczba_miesz, nazwa_mia, woj,budzet)
    {
        budget=budzet;
        id=IDD;
        nazwa = nazwa_mia;
        wojewodztwo = woj;
        if (liczba_miesz < 0)cout << "Prosze podać poprawna liczba mieszkancow";
        else liczba_mieszkancow = liczba_miesz;
    }
    Wsie::~Wsie() {
    }

void Wsie::wypisz_woje() {
        cout<<wojewodztwo<<endl;
    }
    /*
void Wsie::wypisz_woje() {
    cout<<wojewodztwo<<endl;
}
     */
