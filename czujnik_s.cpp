#include "czujnik_s.h"

czujnik_s::czujnik_s(string &nazwa, char &sw)
{
    _getch();
	system("cls");
    czy_wlaczone=0;
    czy_zapalone=0;
    swiatlo = &sw;
    name = &nazwa;
    //ctor

}

czujnik_s::~czujnik_s()
{
    cout<<"Usunieto czujnik swiatla w: "<<name<<endl;
}

void czujnik_s::pokaz_parametry()
{
    if (czy_wlaczone==1)
    {
        if (czy_zapalone==0)
        {
          cout << *name << ": " << "swiatla sa zgaszone." <<  endl;
        }
        else
        {
            cout << *name << ": " << "swiatla sa zapalone." << endl;
        }

    }
    else
    {
        cout<<"Czujnik swiatla w: "<<*name<<" jest wylaczony"<<endl;
    }
}

void czujnik_s::pokaz_mnie()
{
    if (czy_wlaczone==1)
    {
        cout<<"Czujnik swiatla w "<<*name<<" wlaczony"<<endl;
    }
    else
    {
         cout<<"Czujnik swiatla w "<<*name<<" wylaczony"<<endl;
    }
}
void czujnik_s::ustaw_parametry()
{
    char sw;
    if (czy_wlaczone==0)
    {
        cout<<"Musisz wlaczyc czujnik!"<<endl;
    }
    else
    {
        *swiatlo = sw;
        cout << "1. Zapal swiatlo" << endl;
        cout << "2. Zgas swiatlo" << endl;
        sw = _getch();

        switch(sw)
        {
            case '1':
            if(czy_zapalone==0)
            {
                czy_zapalone=1;
                cout << "Zapalono swiatlo" <<endl;
                komendy();

            }
            else
            {
                cout << "Swiatlo juz jest wlaczone" << endl;
                ustaw_parametry();
            }
            break;

            case '2':
            if(czy_zapalone==0)
            {
                cout << "Swiatlo juz jest wylaczone" << endl;

            }
            else
            {
                czy_zapalone=0;
                cout << "Zgaszono swiatlo" <<endl;
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
void czujnik_s::on()
{
    if (czy_wlaczone==0)
    {
        czy_wlaczone=1;
        cout<<"Wlaczono czujnik swiatla w: "<< *name <<endl;

    }
    else
    {
        cout<<"Czujnik juz jest wlaczony w: "<< *name <<endl;
    }


}
void czujnik_s::off()
{
    if (czy_wlaczone==1)
    {
        czy_wlaczone=0;
        cout<<"Wylaczono czujnik swiatla w: "<< *name <<endl;
    }
    else
    {
        cout<<"Czujnik juz jest wylaczony w: "<<*name<<endl;
    }
}

void czujnik_s::komendy()
{
    system("cls");
    char s;
    cout << "---------------------------------------------------------" << endl;
    cout<<"Co chcesz zrobic z czujnikiem swiatla w: "<<*name<< " ?"<<endl;
    cout << "1. Wlacz" << endl;
	cout << "2. Wylacz " << endl;
	cout << "3. Ustaw swiatlo" << endl;
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
