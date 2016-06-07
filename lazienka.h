#ifndef LAZIENKA_H
#define LAZIENKA_H

#include <pomieszczenie.h>

class lazienka : public pomieszczenie
{
    public:
        lazienka(string n="Lazienka");
        virtual ~lazienka();
        void przedstaw_sie();
    protected:

    private:
};

#endif // LAZIENKA_H
