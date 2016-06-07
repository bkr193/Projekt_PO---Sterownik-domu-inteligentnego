#include <iostream>
#include "kuchnia.h"
#include "dzienny.h"
#include "lazienka.h"
#include "sypialnia.h"
#include "czujnik_o.h"
#include "czujnik_s.h"
#include "czujnik_t.h"

#include "obiekt.h"
#include <vector>
#include <conio.h>
#include <stdlib.h>


using namespace std;
#ifndef POMIESZCZENIE_H
#define POMIESZCZENIE_H


class pomieszczenie
{
    protected:
        string name;
        float temperatura;
        char swiatlo;
        char okna;

    public:
        pomieszczenie();
        virtual ~pomieszczenie();
        virtual void przedstaw_sie()=0;
        vector <obiekt*> obiekty;
        friend void ustaw_parametry(float temperatura);
        friend void ustaw_parametry(char swiatlo);
        friend void ustaw_parametry(char okna);
        friend void pokaz_parametry(float temperatura);
        friend void pokaz_parametry(char swiatlo);
        friend void pokaz_parametry(char okna);
        void dodaj_obiekt();



    private:
};

#endif // POMIESZCZENIE_H
