#include "pomieszczenie.h"

pomieszczenie::pomieszczenie()
{
    //ctor
}

pomieszczenie::~pomieszczenie()
{
    //dtor

}

void pomieszczenie::dodaj_obiekt()
{
    char s;
    cout << "---------------------------------------------------------" << endl;
    cout<<"Co chcesz dodac do: "<<name<<endl;
    cout << "1. Dodaj Czujnik temperatury" << endl;
	cout << "2. Dodaj czujnik swiatla" << endl;
	cout << "3. Dodaj czujnik okien" << endl;
    //cout << "5. Wylacz wszystkie urzadzenia!" << endl;
    cout << "---------------------------------------------------------" << endl;
    s = _getch();
	switch (s)
	{
	case '1':
		system("cls");
        cout << "Aby przejsc dalej, nacisnij dolowny klawisz" << endl;
        obiekty.push_back(new czujnik_t(name, temperatura));
        cout<<"Dodano nowy czujnik temperatury w: "<<name<<endl;
		break;

	case '2':
		system("cls");
		cout << "Aby przejsc dalej, nacisnij dolowny klawisz" << endl;
        obiekty.push_back(new czujnik_s(name, swiatlo));
        cout<<"Dodano nowy czujnik swiatla w: "<<name<<endl;
		break;

    case '3':
		system("cls");
		cout << "Aby przejsc dalej, nacisnij dolowny klawisz" << endl;
        obiekty.push_back(new czujnik_o(name, okna));
        cout<<"Dodano nowy czujnik okien w: "<<name<<endl;
		break;

	default:
		system("cls");
		cout << "Wybrano nieznana komende, wybierz jeszcze raz" << endl;
		dodaj_obiekt();
		break;
	}

	return;


}
