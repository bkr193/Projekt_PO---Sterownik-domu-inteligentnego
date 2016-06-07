#include "kuchnia.h"

kuchnia::kuchnia(string n)
{
    name = n;
    //ctor
}

kuchnia::~kuchnia()
{
    //dtor
}

void kuchnia::przedstaw_sie()
{
    cout<<" "<<name<<endl;
}
