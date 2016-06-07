#include "lazienka.h"

lazienka::lazienka(string n)
{
    name = n;
    //ctor
}

lazienka::~lazienka()
{
    //dtor
}

void lazienka::przedstaw_sie()
{
    cout<<" "<<name<<endl;
}
