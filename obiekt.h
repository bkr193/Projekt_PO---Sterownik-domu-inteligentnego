#include "czujnik_t.h"
#include "czujnik_s.h"
#include "czujnik_o.h"

#include <vector>
#include "czujnik_o.h"
#include "czujnik_s.h"
#include "czujnik_t.h"
#ifndef OBIEKT_H
#define OBIEKT_H

#include <iostream>
using namespace std;


class obiekt
{
    public:
        obiekt();
        virtual ~obiekt();
        virtual void pokaz_parametry()=0;
        virtual void pokaz_mnie()=0;
        virtual void komendy()=0;  //do zrobienia
        virtual void on()=0;
        virtual void off()=0;





    protected:
        bool czy_wlaczone;
        bool czy_zapalone;
        bool czy_otwarte;

    private:

};

#endif // OBIEKT_H
