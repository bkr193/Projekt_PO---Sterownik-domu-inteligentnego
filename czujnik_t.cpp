#include "czujnik_t.h"

czujnik_t::czujnik_t(string &nazwa,float &temp)
{
    _getch();
	system("cls");
    czy_wlaczone=0;
    temperatura = &temp;
    name = &nazwa;
    //ctor

}

czujnik_t::~czujnik_t()
{
    cout<<"Usunieto czujnik temperatury: "<<name<<endl;
}

void czujnik_t::pokaz_parametry()
{
    if (czy_wlaczone==1)
    {
       cout<< *name <<": "<< " Temperatura: "<<*temperatura << endl;
    }
    else
    {
        cout<<"Czujnik temperatury: "<<*name<<" jest wylaczony"<<endl;
    }
}

void czujnik_t::pokaz_mnie()
{
    if (czy_wlaczone==1)
    {
        cout<<"Czujnik temperatury w "<<*name<<" wlaczony"<<endl;
    }
    else
    {
         cout<<"Czujnik temperatury w "<<*name<<" wylaczony"<<endl;
    }
}
void czujnik_t::ustaw_parametry()
{
    if (czy_wlaczone==0)
    {
        cout<<"Musisz wlaczyc czujnik!"<<endl;
    }
    else
    {
    cout<<"Wprowadz temperature od 0 do 40 stopni"<<endl;
    float x;
    cin >> x;
    if(x >=0 && x <= 40)
    {
        *temperatura = x;
        cout<<"Ustawiono nowe temperature: "<<*temperatura<< " w:"<<*name<<endl;
    }
    else
    {
        cout<<"Cos poszlo nie tak, spobuj jeszcze raz!"<<endl;
        cout<<"Nacisnij dowolny klawisz by kontynuowac"<<endl;
        _getch();
        ustaw_parametry();
    }
    }


}
void czujnik_t::on()
{
    if (czy_wlaczone==0)
    {
        czy_wlaczone=1;
        cout<<"Wlaczono czujnik temperatury w: "<< *name <<endl;

    }
    else
    {
        cout<<"Czujnik juz jest wlaczony w: "<< *name <<endl;
    }


}
void czujnik_t::off()
{
    if (czy_wlaczone==1)
    {
        czy_wlaczone=0;
        cout<<"Wylaczono czujnik temperatury w: "<< *name<<endl;
    }
    else
    {
        cout<<"Czujnik juz jest wylaczony w: "<<*name<<endl;
    }
}

void czujnik_t::komendy()
{
    system("cls");
    char s;
    cout << "---------------------------------------------------------" << endl;
    cout<<"Co chcesz zrobic z czujnikiem temperatury w: "<<*name<< " ?"<<endl;
    cout << "1. Wlacz" << endl;
	cout << "2. Wylacz " << endl;
	cout << "3. Ustaw temperature" << endl;
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
