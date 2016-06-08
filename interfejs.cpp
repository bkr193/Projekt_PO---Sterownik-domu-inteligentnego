#include "interfejs.h"

interfejs::interfejs()
{
    cout << "---------------------------------------------------------" << endl;
    cout << "Panel sterowania domu !" << endl;
	cout << "Aby przejsc dalej, nacisnij dolowny klawisz" << endl;
    cout << "---------------------------------------------------------" << endl;
    dodaj_pomieszczenia();
    czy_wlaczone = 0;
	_getch();
	system("cls");
	logowanie();
	//co_robic();
}

interfejs::~interfejs()
{
    //dtor
}
void interfejs::logowanie()
{
    int h;
    cout << "---------------------------------------------------------" << endl;
    cout << "Podaj haslo: " << endl;
    cin >> h;
    while(1)
    {
        if (h==12345)
        {
            system("cls");
            co_robic();
        }
        else
        {
            for (int i=0; i<=1; i++)
            {
                cout << "Podane haslo jest niepoprawne !" << endl;
                cout << "Podaj haslo ponownie: " << endl;
                cin >> h;
            }
            system("cls");
            cout << "Proba wlamania ! (Wyslano SMS)" << endl;
            exit(0);

        }
    }
}

void interfejs::co_robic()
{
	char s;
    cout << "---------------------------------------------------------" << endl;
	cout << "Co chcesz zrobic? Nacisnij odpowiedni przycisk" << endl;
    cout << "---------------------------------------------------------" << endl;
	cout << "1. Dodaj obiekt" << endl;
	cout << "2. Usun obiekt" << endl;
	cout << "3. Ustaw w pomieszczeniach" << endl;
	cout << "4. Sprawdz stan w pomieszczeniach" << endl;
	cout << "5. Zraszacze na dworze" << endl;
	cout << "6. Zresetuj ustawienia" << endl;
	cout << "7. Wyjscie" << endl;
    cout << "---------------------------------------------------------" << endl;

	s = _getch();

	switch (s)
	{
	case '1':
		system("cls");
		gdzie_obiekt();
		break;

	case '2':
		system("cls");
		usun_obiekt();
		break;

	case '3':
		system("cls");
		ustaw();
		break;

	case '4':
        system("cls");
        sprawdz();
		break;

	case '5':
        system("cls");
	    zraszacze();
		break;

    case '6':
        system("cls");
	    zresetuj();
		break;

    case '7':
        system("cls");
        exit(0);
        break;

    default:
		system("cls");
		cout << "Wybrano nieznana komende, wybierz jeszcze raz" << endl;
		co_robic();
		break;
	}

}
void interfejs::dodaj_pomieszczenia()
{
    pomieszczenia.push_back(new kuchnia);
    pomieszczenia.push_back(new dzienny);
    pomieszczenia.push_back(new sypialnia);
    pomieszczenia.push_back(new lazienka);
}

void interfejs::gdzie_obiekt()
{
    string znak;
    unsigned int liczba;
    unsigned int i;
    cout << "---------------------------------------------------------" << endl;
    cout <<"Gdzie chcesz dodac obiekt ?"<<endl;
    cout << "---------------------------------------------------------" << endl;
    for(i=0;i<pomieszczenia.size();i++)
    {
        cout<<i+1<<".";
        pomieszczenia.at(i) -> przedstaw_sie();
    }

    cout<<i+1<<".";
    cout<<"Wroc do poprzedniego menu"<<endl;
    cout << "---------------------------------------------------------" << endl;
    cin >> znak;
    cout << "---------------------------------------------------------" << endl;
    liczba=atoi(znak.c_str());

    if((liczba-1)== pomieszczenia.size())
    {
        system("cls");
        co_robic();
    }

    if((liczba-1) >= pomieszczenia.size())
    {
        cerr<<"Nie ma takiego pomieszczenia!"<<endl;
    }

    else
    {
        pomieszczenia.at(liczba-1)->dodaj_obiekt();
    }

    cout << "Aby przejsc dalej, nacisnij dolowny klawisz" << endl;
    _getch();
    system("cls");
    co_robic();

    }

void interfejs::dodaj_obiekt()
{
    string znak;
    unsigned int liczba;
    unsigned int i;
    cout << "---------------------------------------------------------" << endl;
    cout <<"Jaki chcesz dodac obiekt ?"<<endl;
    cout << "---------------------------------------------------------" << endl;
    for(i=0;i<pomieszczenia.size();i++)
    {
        cout<<i+1<<".";
        pomieszczenia.at(i) -> przedstaw_sie();
    }

    cout<<i+1<<".";
    cout<<"Wroc do poprzedniego menu"<<endl;
    cout << "---------------------------------------------------------" << endl;
    cin >> znak;
    cout << "---------------------------------------------------------" << endl;
    liczba=atoi(znak.c_str());

    if((liczba-1)== pomieszczenia.size())
    {
        system("cls");
        co_robic();
    }

    if((liczba-1) >= pomieszczenia.size())
    {
        cerr<<"Nie ma takiego obiektu!"<<endl;
    }

    else
    {
        pomieszczenia.at(liczba-1)->dodaj_obiekt();
    }


}

void interfejs::usun_obiekt()
{
    string znak;
    unsigned int liczba;
    unsigned int i;
    unsigned int x;
    cout << "---------------------------------------------------------" << endl;
    cout <<"Gdzie chcesz usunac obiekt?"<<endl;
    cout << "---------------------------------------------------------" << endl;

    for(i=0;i<pomieszczenia.size();i++)
    {
        cout<<i+1<<".";
        pomieszczenia.at(i) -> przedstaw_sie();
    }

    cout<<i+1<<".";
    cout<<"Wroc do poprzedniego menu"<<endl;
    cout << "---------------------------------------------------------" << endl;
    cin >> znak;
    cout << "---------------------------------------------------------" << endl;
    liczba=atoi(znak.c_str());

    if((liczba-1)== pomieszczenia.size())
    {
        system("cls");
        co_robic();
    }

    if((liczba-1) >= pomieszczenia.size())
    {
        cerr<<"Nie ma takiego obiektu!"<<endl;
    }

    else
    {

        for(x=0;x<pomieszczenia.at(liczba-1)->obiekty.size();x++)
        {
            cout<<x+1<<".";
            pomieszczenia.at(liczba-1)->obiekty.at(x) -> pokaz_mnie();

        }
    }

     cout << "---------------------------------------------------------" << endl;
        cout<<"Jesli chcesz usunac obiekt, wybierz odpowiedni numer"<<endl;
        cout<<"W przeciwnym wypadku wcisnij: "<< pomieszczenia.at(liczba-1)->obiekty.size()+1 <<endl;
        cout << "---------------------------------------------------------" << endl;

        string znak1;
        unsigned int liczba1;
        cin >> znak1;
        liczba1=atoi(znak1.c_str());

            if((liczba1-1) ==  pomieszczenia.at(liczba-1)->obiekty.size())
            {
                cout<<""<<endl;
                cout << "Aby przejsc dalej, nacisnij dolowny klawisz" << endl;
                _getch();
                system("cls");
                co_robic();
            }

            if((liczba1-1) >=  pomieszczenia.at(liczba-1)->obiekty.size())
            {
                cerr<<"Nie ma takiego obiektu!"<<endl;
            }

            else
                delete pomieszczenia.at(liczba-1)->obiekty.at(liczba1-1);
                pomieszczenia.at(liczba-1)->obiekty.erase(pomieszczenia.at(liczba-1)->obiekty.begin() + liczba1 -1);


    cout << "---------------------------------------------------------" << endl;
    co_robic();




        //pomieszczenia.at(liczba-1)->obiekty.at(0)->pokaz_parametry();

    }


void interfejs::sprawdz()
{
     string znak;
     unsigned int liczba;
     unsigned int i;
     cout << "---------------------------------------------------------" << endl;
     cout <<"Z ktorego pomieszczenia pokazac informacje ?"<<endl;
     cout << "---------------------------------------------------------" << endl;
     for(i=0;i<pomieszczenia.size();i++)
    {
        cout<<i+1<<".";
        pomieszczenia.at(i) -> przedstaw_sie();
    }
    cout<<i+1<<".";
    cout<<"Wroc do poprzedniego menu"<<endl;
    cout << "---------------------------------------------------------" << endl;

    cin >> znak;
    liczba=atoi(znak.c_str());


    if((liczba-1)== pomieszczenia.size())
    {
        system("cls");
        co_robic();

    }

    if((liczba-1) >= pomieszczenia.size())
    {
        cerr<<"Nie ma takiego obiektu!"<<endl;

    }

    else
    {

        pomieszczenia.at(liczba-1)->obiekty.at(0)->pokaz_parametry();
    }

    cout<<""<<endl;
    cout << "Aby przejsc dalej, nacisnij dolowny klawisz" << endl;
    _getch();
    system("cls");
    co_robic();


}

void interfejs::ustaw()
{

    cout << "---------------------------------------------------------" << endl;
    cout <<"Gdzie chcesz ustawic parametry ?"<<endl;
    cout << "---------------------------------------------------------" << endl;

    string znak;
    unsigned int liczba;
    unsigned int i;

    for(i=0;i<pomieszczenia.size();i++)
    {
        cout<<i+1<<".";
        pomieszczenia.at(i) -> przedstaw_sie();
    }

    cout<<i+1<<".";
    cout<<"Wroc do poprzedniego menu"<<endl;
    cout << "---------------------------------------------------------" << endl;
    cin >> znak;
    cout << "---------------------------------------------------------" << endl;
    liczba=atoi(znak.c_str());

    if((liczba-1)== pomieszczenia.size())
    {
        system("cls");
        co_robic();
    }

    if((liczba-1) >= pomieszczenia.size())
    {
        cerr<<"Nie ma takiego obiektu!"<<endl;
    }

    else
    {
        unsigned int x;
        for(x=0;x<pomieszczenia.at(liczba-1)->obiekty.size();x++)
        {
            cout<<x+1<<".";
            pomieszczenia.at(liczba-1)->obiekty.at(x) -> pokaz_mnie();

        }

        cout << "---------------------------------------------------------" << endl;
        cout<<"Wybierz odpowiedni numer"<<endl;
        cout<<"W przeciwnym wypadku wcisnij: "<< pomieszczenia.at(liczba-1)->obiekty.size()+1 <<endl;
        cout << "---------------------------------------------------------" << endl;

        string znak1;
        unsigned int liczba1;
        cin >> znak1;
        liczba1=atoi(znak1.c_str());

            if((liczba1-1) ==  pomieszczenia.at(liczba-1)->obiekty.size())
            {
                cout<<""<<endl;
                cout << "Nacisnij dolowny klawisz" << endl;
                _getch();
                system("cls");
                co_robic();
            }

            if((!liczba) >=  pomieszczenia.at(liczba-1)->obiekty.size())
            {
                cerr<<"Nie ma takiego obiektu!"<<endl;
            }

            else
            {
                pomieszczenia.at(liczba-1)->obiekty.at(liczba1-1) -> komendy();
            }



    cout << "---------------------------------------------------------" << endl;




    }


    co_robic();
}
void interfejs::zraszacze()
{
    char s;
    cout << "1. Wlacz zraszacze" << endl;
    cout << "2. Wylacz zraszacze" << endl;
    cout << "3. Powrot do glownego menu" << endl;
    cout << "---------------------------------------------------------" << endl;
    s = _getch();
    switch(s)
    {
    case '1':
        if(czy_wlaczone == 0)
        {
            czy_wlaczone = 1;
            cout << "Wlaczono zraszacze" << endl;
        }
        else
        {
            cout << "Zraszacze sa juz wlaczone" << endl;
        }
        co_robic();
        system("cls");
        break;

    case '2':
        if(czy_wlaczone == 1)
        {
            czy_wlaczone = 0;
            cout << "Wylaczono zraszacze" << endl;
        }
        else
        {
            cout << "Zraszacze sa juz wylaczone" << endl;
        }
        co_robic();
        system("cls");
		break;

    case '3':
        system("cls");
        co_robic();
        break;

    default:
		system("cls");
		cout << "Wybrano nieznana komende, wybierz jeszcze raz" << endl;
		zraszacze();
		break;
    }

    co_robic();
}
void interfejs::zresetuj()
{
    char pom;
    system("cls");
    cout<<"Przywrocisz ustawienia domyslne, jestes pewien ?"<<endl;
    cout<<"Jesli tak, wcisnij Y, nacisniecie innego przycisku spowoduje powrot"<<endl;

    pom = _getch();

	switch (pom)
	{
	case 'y':
		system("cls");
		unsigned int i;
		cout << "---------------------------------------------------------" << endl;
        for(i=0;i<pomieszczenia.size();i++)
        {
            for(unsigned int x=0;x<pomieszczenia.at(i)->obiekty.size();x++)
            {
                pomieszczenia.at(i)->obiekty.at(x) -> off();
            }
        }
        cout << "---------------------------------------------------------" << endl;

		break;

    case 'Y':
		system("cls");
		cout << "---------------------------------------------------------" << endl;
        for(i=0;i<pomieszczenia.size();i++)
        {
            for(unsigned int x=0;x<pomieszczenia.at(i)->obiekty.size();x++)
            {
                pomieszczenia.at(i)->obiekty.at(x) -> off();
            }
        }
        cout << "---------------------------------------------------------" << endl;

		break;

    default:
		system("cls");
		co_robic();
		break;
	}
    cout<<"Nacisnij dowolny klawisz by przejsc dalej"<<endl;
	_getch();
    system("cls");
    co_robic();

}


