#ifndef CZUJNIK_S_H
#define CZUJNIK_S_H

#include <obiekt.h>
#include <conio.h>
#include <stdlib.h>

class czujnik_s : public obiekt
{
    public:
        czujnik_s(string &nazwa,char &sw);
        virtual ~czujnik_s();
        void pokaz_parametry();
        void pokaz_mnie();
        void ustaw_parametry();
        void on();
        void off();
        void komendy();


    protected:

    private:
        string *name;
        char *swiatlo;
};

#endif // CZUJNIK_S_H
