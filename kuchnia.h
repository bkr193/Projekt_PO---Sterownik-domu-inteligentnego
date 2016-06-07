#ifndef KUCHNIA_H
#define KUCHNIA_H

#include <pomieszczenie.h>


class kuchnia : public pomieszczenie
{
    public:
        kuchnia(string n="Kuchnia");
        virtual ~kuchnia();
        void przedstaw_sie();
    protected:

    private:
};

#endif // KUCHNIA_H
