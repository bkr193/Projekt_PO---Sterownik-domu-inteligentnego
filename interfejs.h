#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <vector>
#include "pomieszczenie.h"
#include "obiekt.h"
using namespace std;
#ifndef INTERFEJS_H
#define INTERFEJS_H



class interfejs
{
    public:
        interfejs();
        virtual ~interfejs();
        void logowanie();
        void co_robic();
        void dodaj_pomieszczenia();
        void gdzie_obiekt();
        void dodaj_obiekt();
        void usun_obiekt();
        void sprawdz();
        void ustaw();
        void zraszacze();
        void zresetuj();

    protected:
        vector <pomieszczenie*> pomieszczenia;
        vector <obiekt*> obiekty;
        bool czy_wlaczone = 0;

    private:
};

#endif // INTERFEJS_H
