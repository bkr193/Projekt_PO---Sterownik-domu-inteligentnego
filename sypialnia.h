#ifndef SYPIALNIA_H
#define SYPIALNIA_H

#include <pomieszczenie.h>

class sypialnia : public pomieszczenie
{
    public:
        sypialnia(string n="Sypialnia");
        virtual ~sypialnia();
        void przedstaw_sie();
    protected:

    private:
};

#endif // SYPIALNIA_H
