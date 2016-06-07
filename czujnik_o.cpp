#include "czujnik_o.h"

czujnik_o::czujnik_o(string &nazwa, char &o)
{
    _getch();
	system("cls");
    czy_wlaczone=0;
    czy_otwarte=0;
    okna = &o;
    name = &nazwa;
    //ctor

}

czujnik_o::~czujnik_o()
{
    cout<<"Usunieto czujnik okien w: "<<name<<endl;
}

void czujnik_o::pokaz_parametry()
{
    if (czy_wlaczone==1)
    {
        if (czy_otwarte==0)
        {
          cout << *name << ": " << "okna sa zamkniete." <<  endl;
        }
        else
        {
            cout << *name << ": " << "okna sa otwarte." << endl;
        }

    }
    else
    {
        cout<<"Czujnik okien w: "<<*name<<" jest wylaczony"<<endl;
    }
}

void czujnik_o::pokaz_mnie()
{
    if (czy_wlaczone==1)
    {
        cout<<"Czujnik okien w "<<*name<<" wlaczony"<<endl;
    }
    else
    {
         cout<<"Czujnik okien w "<<*name<<" wylaczony"<<endl;
    }
}
void czujnik_o::ustaw_parametry()
{
    char o;
    if (czy_wlaczone==0)
    {
        cout<<"Musisz wlaczyc czujnik!"<<endl;
    }
    else
    {
        cout << "1. Otworz okna" << endl;
        cout << "2. Zamknij okna" << endl;
        *okna = o;
        o = _getch();

        switch(o)
        {
            case '1':
            if(czy_otwarte==0)
            {
                czy_otwarte=1;
                cout << "Otwarto okna" <<endl;
                komendy();

            }
            else
            {
                cout << "Okna sa juz otwarte" << endl;
                ustaw_parametry();
            }
            break;

            case '2':
            if(czy_otwarte==0)
            {
                cout << "Okna sa juz zamkniete" << endl;
                ustaw_parametry();
            }
            else
            {
                czy_otwarte=0;
                cout << "Zamknieto okna" <<endl;
                komendy();
            }
            break;

            default:
            system("cls");
            cout << "Wybrano nieznana komende, wybierz jeszcze raz" << endl;
            ustaw_parametry();
            break;
        }
    }
}
void czujnik_o::on()
{
    if (czy_wlaczone==0)
    {
        czy_wlaczone=1;
        cout<<"Wlaczono czujnik okien w: "<< *name <<endl;
        komendy();

    }
    else
    {
        cout<<"Czujnik juz jest wlaczony w:"<< *name <<endl;
    }


}
void czujnik_o::off()
{
    if (czy_wlaczone==1)
    {
        czy_wlaczone=0;
        cout<<"Wylaczono czujnik okien w: "<< *name<<endl;
    }
    else
    {
        cout<<"Czujnik juz jest wylaczony w: "<<*name<<endl;
    }
}

void czujnik_o::komendy()
{
    system("cls");
    char s;
    cout << "---------------------------------------------------------" << endl;
    cout<<"Co chcesz zrobic z czujnikiem okien w: "<<*name<< " ?"<<endl;
    cout << "1. Wlacz" << endl;
	cout << "2. Wylacz " << endl;
	cout << "3. Ustaw okna" << endl;
	cout << "4. Powrot do menu glownego" << endl;
    cout << "---------------------------------------------------------" << endl;
    s = _getch();
	switch (s)
	{
	case '1':
		system("cls");
		on();
		return;
		break;

	case '2':
		system("cls");
        off();
        return;
		break;
    case '3':
		system("cls");
		ustaw_parametry();
        return;
		break;
    case '4':
		system("cls");
        return;
		break;

	default:
		system("cls");
		cout << "Wybrano nieznana komende, wybierz jeszcze raz" << endl;
		komendy();
		break;
	}


}
