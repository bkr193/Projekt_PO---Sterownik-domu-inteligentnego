#ifndef CZUJNIK_O_H
#define CZUJNIK_O_H

#include <obiekt.h>
#include <conio.h>
#include <stdlib.h>

class czujnik_o : public obiekt
{
    public:
        czujnik_o(string &nazwa,char &o);
        virtual ~czujnik_o();
        void pokaz_parametry();
        void pokaz_mnie();
        void ustaw_parametry();
        void on();
        void off();
        void komendy();


    protected:

    private:
        string *name;
        char *okna;
};

#endif // CZUJNIK_O_H
