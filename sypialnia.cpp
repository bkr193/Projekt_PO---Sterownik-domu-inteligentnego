#include "sypialnia.h"

sypialnia::sypialnia(string n)
{
    name = n;
    //ctor
}

sypialnia::~sypialnia()
{
    //dtor
}

void sypialnia::przedstaw_sie()
{
    cout<<" "<<name<<endl;
}
