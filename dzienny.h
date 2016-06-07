#ifndef DZIENNY_H
#define DZIENNY_H

#include <pomieszczenie.h>

class dzienny : public pomieszczenie
{
    public:
        dzienny(string n = "Dzienny");
        virtual ~dzienny();
        void przedstaw_sie();
    protected:

    private:
};

#endif // DZIENNY_H
