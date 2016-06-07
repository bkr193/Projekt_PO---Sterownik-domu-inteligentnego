#include "dzienny.h"

dzienny::dzienny(string n)
{
    name = n;
    //ctor
}

dzienny::~dzienny()
{
    //dtor
}

void dzienny::przedstaw_sie()
{
    cout<<" "<<name<<endl;
}

