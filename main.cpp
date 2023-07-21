#include <iostream>
#include "Miasto.h"
#include "Wsie.h"
#include <map>
#include "Graph.h"

using namespace std;

class Aglomeracja;
class Miasto;
class Wsie;
map<int,int>miasta_i_wsie;
Miasto miasta[100];
Wsie wsie[100];

bool czy_zaprzyjaznione(int id_wsi,int id_miasto)
{

    map<int,int>::iterator itr;
    for(itr=miasta_i_wsie.begin(); itr!=miasta_i_wsie.end();itr++)
    {
        if(itr->first==id_miasto && itr->second==id_wsi)
        {
            cout<<"tak są w przyjazni, budzet miasta "<<miasta[id_miasto].nazwa<<"wynosi: "<<miasta[id_miasto].budget<<endl;
           cout<<"tak są w przyjazni, budzet wsi "<<wsie[id_wsi].nazwa<<"wynosi: "<<wsie[id_wsi].budget<<endl;
            return 1;
        }

    }
    return 0;
}
int NR=0,mapa=0,num=0,idd=0;
int main() {
cout<<"WITAJ W BAZIE DANYCH MIAST I WSI W DANYM KARJU!"<<endl;
cout<<"PODAJ DANĄ LICZBĘ ABY WYKONAC DANA CZYNNOSC: "<<endl;
cout<<"1-dodanie miasta do bazy danych\n";
    cout<<"2-dodanie wsi do bazy danych\n";
    cout<<"3-podanie miasta i wsi i ktore sa w przyjazni i moga od siebie pobierac informacje\n";
    cout<<"4-sprawdzenie czy miasto i wies sa w przyjazni-czy moga pobierac od siebie poufne dane\n";
    cout<<"5-sprawdzenie w jakim wojewodztwie znajduje sie miasto lub wies\n";
    cout<<"6-sprawdzenie najktrotsza droge pomiedzy dwoma miastami\n";
    cout<<"7-sprawdz czy dwa miasta maja taka sama liczbe mieszkancow\n";
    cout<<"8-zakoncz program\n";
    for(;;) {
        cout<< "wybierz co chcesz zrobic: "<<endl;
        int wybor;
        cin >> wybor;
        if (wybor == 1) {
            cout << "Podaj miasto jakie chcesz dodac: " << endl;

            int bud;
            string nazwa_miasta, woj;
            int ilosc_miesz;
            try {
                cin >> nazwa_miasta >> ilosc_miesz >> woj >> bud;
                if(ilosc_miesz<0) throw 1;
                else
                {miasta[idd] = Miasto(idd, ilosc_miesz, nazwa_miasta, woj,bud);
                    NR++;
                    idd++;

                }
            }
            catch(...)
            {
                cout<<"ilosc mieszkancow nie moze byc mniejsza od zera!!"<<endl;
            }

        }
        if(wybor==2)
        {
            cout << "Podaj wies jakie chcesz dodac: " << endl;
            cout<<"podawaj odpowiedno: NAZWA MIASTA, ILOSC MIESZKANCOW, WOJEWODZTWO, BUDZET MIASTA"<<endl;
            int bud;
            string nazwa_wies, woj;
            int ilosc_miesz;
            try {
                cin >> nazwa_wies >> ilosc_miesz >> woj >> bud;
                if(ilosc_miesz<0)throw -1;
                else
                wsie[idd] = Wsie(idd, ilosc_miesz, nazwa_wies, woj, bud);
                //  wsie[num].wypisz_nazwe();
                num++;
                idd++;
            }
            catch(...)
                {
                cout<<"Liczba mieszkancow nie moze byc ujemna!"<<endl;
                }

        }

        if (wybor == 3) {
            cout << "Podaj miasta zaprzyjaznione ze soba mogace uzyskiwac od siebie wiadomosci: " << endl;
           cout<<"PODAJ ID MIASTA I WSI: "<<endl;
            int id1, id2;//id1-miasto id2-wies
            cin >> id1 >> id2;
            miasta_i_wsie.insert(pair<int, int>(id1, id2));
            //miasta_i_wsie[id1]=id2;
        }
        if (wybor == 4)//sprawdzenie miasta czy sa zaprzyjaznione
        {
            cout << "Podaj miasto i wies do sprawdzenia: " << endl;
            cout<<"PODAJ ID MIASTA I WSI: "<<endl;
            int id1, id2;
            cin >> id1 >> id2;
            czy_zaprzyjaznione(id2, id1);

        }
        if(wybor==5)
        {
            cout<<"Jezeli chcesz sprawdzic wojewodztwo miasta wpisz-1 ,a jezeli wojewodztwo wsi wpisz -2 "<<endl;
            int podaj,id;
            cin>>podaj;
            Aglomeracja *aglo;
            if(podaj==1) {
                try {
                    cout<<"PODAJ ID MIASTA: "<<endl;
                    cin >> id;
                    if(id>idd || id<0)
                    {
                        throw -1;
                    }
                    else
                    {
                        aglo = &miasta[id];
                        aglo->wypisz_woje();
                    }

                }catch (int e){
                    cout<<"Podaj poprawne ID!";
                }

            }
            else
            {
                try{
                    cout<<"PODAJ ID WSI: "<<endl;
                cin >> id;
                if(id>idd || id<0)
                {
                    throw -1;
                }
                else
                {
                    aglo=&wsie[id];
                    aglo->wypisz_woje();
                }

            }catch (int e){
                cout<<"Podaj poprawne ID!";
            }

            }
        }
        if(wybor==6)
        {
            cout<<"Oblicz najkrotszą drogę pomiedzy miastami i wsiami"<<endl;
            cout<<"Podaj dlugosc drogi pomiedzy miastami(podawaj ID): "<<endl;
            cout<<"podaj ilosc miast pomiedzy ktorymi chcesz sprawdzic najkrotsza droge oraz ilosc drog miedzy nimi: "<<endl;
            int n,m;
            cin>>n>>m;

            Graph g(n);
            for(int i=0;i<m;i++)
            {
                int a,b,c;
                cin>>a>>b>>c;
                g.addEdge(a,b,c);

            }
            cout<<"Podaj miasto z ktorego chcesz jechac: "<<endl;
            int pocz,kon;
            cin>>pocz;
            cout<<"podaj miasto do ktorego chcesz dojechac: "<<endl;
            cin>>kon;
            g.najkrotsza(pocz,kon,n);


        }
        if(wybor==7)
        {
            cout<<"Podaj ID miast ktore chcesz sprawdzic czy maja taka sama liczbe mieszkancow: "<<endl;
            int id1,id2;
            cin>>id1>>id2;
            if(miasta[id1]==miasta[id2])
            {
                cout<<"miasta maja taka sama liczbe mieszkancow!"<<endl;
            }
            else
            {
                cout<<"miasta maja rozna liczbe mieszkancow"<<endl;
            }
        }
        if(wybor==8)
        {
            return 0;
        }
    }
    }


