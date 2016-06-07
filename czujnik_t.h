#ifndef CZUJNIK_T_H
#define CZUJNIK_T_H

#include <obiekt.h>
#include <conio.h>
#include <stdlib.h>

class czujnik_t : public obiekt
{
    public:
        czujnik_t(string &nazwa,float &temp);
        virtual ~czujnik_t();
        void pokaz_parametry();
        void pokaz_mnie();
        void ustaw_parametry();
        void on();
        void off();
        void komendy();


    protected:

    private:
        string *name;
        float *temperatura;
};

#endif // CZUJNIK_T_H
