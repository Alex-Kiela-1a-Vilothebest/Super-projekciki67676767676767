#include <iostream>
#include <random>
#include <thread>
#include <chrono>
#include <conio.h>

using namespace std;
int t[10][10];
char a[10][10];
int main()
{
int liczn=0,liczy=0,x,y,licz2=0,tempx,tempy,d,czas=2,litera;
cout <<"********************************"<<endl;
cout <<"*  =   =  =====  =   =  =   =  *"<<endl;
cout <<"*  == ==  =      ==  =  =   =  *"<<endl;
cout <<"*  = = =  ====   = = =  =   =  *"<<endl;
cout <<"*  =   =  =      =  ==  =   =  *"<<endl;
cout <<"*  =   =  =====  =   =   ===   *"<<endl;
cout <<"********************************"<<endl;
cout <<endl;
cout << "wybierz opcje:\n";
cout <<"\n";
cout <<"1 - zacznij gre.\n";
cout <<"2 - informacje o autorze.\n";
cout <<"3 - instrukcja, czyli jak grac.\n";
cout <<endl;
cin >>d;
while (d!=1 && d!=2 && d!=3)
{
    cin >>d;
}
while (d!=1)
{
    if (d==2)
{
    system ("cls");
    cout <<"Alex Kiela - Klasa 1a - Liceum Vilo - Krol bezrobocia.\n";
    cout <<endl;
    cout <<"1 - zacznij gre.\n";
    cout <<"3 - instrukcja, czyli jak grac.\n";
    cout <<endl;
    cin >>d;
    while (d!=1 && d!=3)
{
    cin >>d;
}

}
else if (d==3)
{
 system("cls");
    cout <<"na poczadku gry wyswietla sie plansza.\n";
    cout <<"zadaniem gracza jest podanie wspolzednych pola, ktore chce wybrac.\n";
    cout <<"jesli gracz trafi na dobre pole, wowczas rozpocznie sie odliczanie 2 sekundowe odliczanie \nzadaniem gracza bedzie wcisniecie klaiwsza 'y'.\njesli mu sie to uda, uzyska wowczas 2 punkty, a jesli nacisnie inny klawisz,lub upłynie czas, nic sie nie stanie,\npo odliczantym polu pojawii sie znak '1'\n";
    cout <<"natomiast, jesli gracz trafi na zle polen rowniez rozpocznie sie odliczanie, tym razem jednak zadaniem gracza bed  pojawii sie znak 'X'\n";
    cout <<"istnieje rowniez 10% szans na trafienie pola o nazwie bomba, opisanego znakiem 'B'\n";
    cout <<"gracz ma prawo do 15 b³edow, a do wygranej musi zdobyc 10 punktow.\n";
    cout <<"za kazde dobre pole gracz zdobywa punkt, natomiast za kazde zle pole gracz traci zycie, natomiast za trafienie na pole B, gracz natychmiastowo przegrywa.\n";
    cout <<"jesli gracz trafi na dobre pole, i postanowi wybrac jakiekolwiek inne pole bedace obok dobrego pola, i bedzie ono polem dobrym, gracz otrzyma 2 punkty.\n";
     cout <<"jesli pole bedzie natomiast zle, gracz otrzyma 5 punktow blednych.\n";
    cout <<endl;
    cout <<"1 - zacznij gre.\n";
    cout <<"2 - informacje o autorze.\n";
    cout <<endl;
    cin >>d;
    while (d!=1 && d!=2)
{
    cin >>d;
}

}
}
if (d==1)
{
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> dist(0,10);
do

{
    system("cls");
    cout <<"twoja obecna liczba punktow to: "<<liczy<<endl;
    cout <<"twoja obecna liczba bledow to: "<<liczn<<endl;
    if (licz2==0)
    for (int i=0; i <10; i++)
{
    for (int j=0; j<10; j++)
    {
        t[i][j] = dist(gen);
    }
}
if (licz2 == 0)
{
    for (int i=0; i <10; i++)
{
    for (int j=0; j<10; j++)
    {
        a[i][j] = 'O';
    }
}
}
cout<< "   1 2 3 4 5 6 7 8 9 10"<<endl;
for (int i=0; i <10; i++)
{
if (i!=9)
{
    cout <<i+1<<"  ";
}
else
{
    cout <<i+1<<" ";
}

    for (int j=0; j<10; j++)
    {
        if (a[i][j] == 'X')
        {
            cout << "\033[31mX\033[0m"<<" ";
        }

        else if (a[i][j]=='1')
        {
            cout <<"\033[32m1\033[0m"<<" ";
        }
        else if (a[i][j]=='B')
        {
            cout <<"\033[35mB\033[0m"<<" ";
        }
        else
        {
            cout <<a[i][j] <<" ";
        }
    }
    cout <<endl;
}
do
{

    cout <<"wybierz wspolzedne x: ";
cin >>y;

while (y>10 || y<1)
{
    cout <<"wybierz wspolzedne x: ";
    cin >>y;
}
cout <<"wybierz wspolzedne y: ";
cin >>x;

while (x>10 || x<1)
{
    cout <<"wybierz wspolzedne y: ";
    cin >>x;
}
}
while (a[x-1][y-1]=='1' || a[x-1][y-1]=='X');

if (t[x-1][y-1]<5 && t[x-1][y-1]!=1 && x==tempy && y==tempx-1 && t[tempy-1][tempx-1]>=5)
{


a[x-1][y-1] = 'X';
    cout << "Nacisnij 'x' w ciagu 2 sekund!\n";

    auto start = chrono::steady_clock::now();

    while (true)
    {

        if (_kbhit())
        {
            char znak = _getch();

            if (znak != 'x')
            {
        liczn=liczn+5;
            }

            break;
        }

        auto teraz = chrono::steady_clock::now();

        auto sekundy = chrono::duration_cast<chrono::seconds>(
            teraz - start
        ).count();

        cout << "\rPozostalo: " << 2 - sekundy << " sekund   ";

        if (sekundy >= 2)
        {
liczn=liczn+5;
            break;
        }


        this_thread::sleep_for(chrono::milliseconds(100));
    }


}

else if (t[x-1][y-1]<5 && t[x-1][y-1]!=1 && x==tempy-1 && y==tempx && t[tempy-1][tempx-1]>=5)
{

a[x-1][y-1] = 'X';
cout << "Nacisnij 'x' w ciagu 2 sekund!\n";

    auto start = chrono::steady_clock::now();

    while (true)
    {

        if (_kbhit())
        {
            char znak = _getch();

            if (znak != 'x')
            {
        liczn=liczn+5;
            }

            break;
        }

        auto teraz = chrono::steady_clock::now();

        auto sekundy = chrono::duration_cast<chrono::seconds>(
            teraz - start
        ).count();

        cout << "\rPozostalo: " << 2 - sekundy << " sekund   ";

        if (sekundy >= 2)
        {
liczn=liczn+5;
            break;
        }


        this_thread::sleep_for(chrono::milliseconds(100));
    }

}
else if (t[x-1][y-1]<5 && t[x-1][y-1]!=1 && x==tempy && y==tempx+1 && t[tempy-1][tempx-1]>=5)
{

a[x-1][y-1] = 'X';
cout << "Nacisnij 'x' w ciagu 2 sekund!\n";

    auto start = chrono::steady_clock::now();

    while (true)
    {

        if (_kbhit())
        {
            char znak = _getch();

            if (znak != 'x')
            {
        liczn=liczn+5;
            }

            break;
        }

        auto teraz = chrono::steady_clock::now();

        auto sekundy = chrono::duration_cast<chrono::seconds>(
            teraz - start
        ).count();

        cout << "\rPozostalo: " << 2 - sekundy << " sekund   ";

        if (sekundy >= 2)
        {
liczn=liczn+5;
            break;
        }


        this_thread::sleep_for(chrono::milliseconds(100));
    }

}
else if (t[x-1][y-1]<5 && t[x-1][y-1]!=1 && x==tempy+1 && y==tempx && t[tempy-1][tempx-1]>=5)
{

a[x-1][y-1] = 'X';
cout << "Nacisnij 'x' w ciagu 2 sekund!\n";

    auto start = chrono::steady_clock::now();

    while (true)
    {

        if (_kbhit())
        {
            char znak = _getch();

            if (znak != 'x')
            {
        liczn=liczn+5;
            }

            break;
        }

        auto teraz = chrono::steady_clock::now();

        auto sekundy = chrono::duration_cast<chrono::seconds>(
            teraz - start
        ).count();

        cout << "\rPozostalo: " << 2 - sekundy << " sekund   ";

        if (sekundy >= 2)
        {
liczn=liczn+5;
            break;
        }


        this_thread::sleep_for(chrono::milliseconds(100));
    }

}
else if (t[x-1][y-1]<5 && t[x-1][y-1]!=1 && x==tempy-1 && y==tempx-1 && t[tempy-1][tempx-1]>=5)
{

a[x-1][y-1] = 'X';
cout << "Nacisnij 'x' w ciagu 2 sekund!\n";

    auto start = chrono::steady_clock::now();

    while (true)
    {

        if (_kbhit())
        {
            char znak = _getch();

            if (znak != 'x')
            {
        liczn=liczn+5;
            }

            break;
        }

        auto teraz = chrono::steady_clock::now();

        auto sekundy = chrono::duration_cast<chrono::seconds>(
            teraz - start
        ).count();

        cout << "\rPozostalo: " << 2 - sekundy << " sekund   ";

        if (sekundy >= 2)
        {
liczn=liczn+5;
            break;
        }


        this_thread::sleep_for(chrono::milliseconds(100));
    }

}
else if (t[x-1][y-1]<5 && t[x-1][y-1]!=1 && x==tempy-1 && y==tempx-1 && t[tempy-1][tempx-1]>=5)
{

a[x-1][y-1] = 'X';
cout << "Nacisnij 'x' w ciagu 2 sekund!\n";

    auto start = chrono::steady_clock::now();

    while (true)
    {

        if (_kbhit())
        {
            char znak = _getch();

            if (znak != 'x')
            {
        liczn=liczn+5;
            }

            break;
        }

        auto teraz = chrono::steady_clock::now();

        auto sekundy = chrono::duration_cast<chrono::seconds>(
            teraz - start
        ).count();

        cout << "\rPozostalo: " << 2 - sekundy << " sekund   ";

        if (sekundy >= 2)
        {
liczn=liczn+5;
            break;
        }


        this_thread::sleep_for(chrono::milliseconds(100));
    }

}else if (t[x-1][y-1]<5 && t[x-1][y-1]!=1 && x==tempy+1 && y==tempx-1 && t[tempy-1][tempx-1]>=5)
{

a[x-1][y-1] = 'X';
cout << "Nacisnij 'x' w ciagu 2 sekund!\n";

    auto start = chrono::steady_clock::now();

    while (true)
    {

        if (_kbhit())
        {
            char znak = _getch();

            if (znak != 'x')
            {
        liczn=liczn+5;
            }

            break;
        }

        auto teraz = chrono::steady_clock::now();

        auto sekundy = chrono::duration_cast<chrono::seconds>(
            teraz - start
        ).count();

        cout << "\rPozostalo: " << 2 - sekundy << " sekund   ";

        if (sekundy >= 2)
        {
liczn=liczn+5;
            break;
        }


        this_thread::sleep_for(chrono::milliseconds(100));
    }

}
else if (t[x-1][y-1]<5 && t[x-1][y-1]!=1 && x==tempy+1 && y==tempx+1 && t[tempy-1][tempx-1]>=5)
{

a[x-1][y-1] = 'X';
cout << "Nacisnij 'x' w ciagu 2 sekund!\n";

    auto start = chrono::steady_clock::now();

    while (true)
    {

        if (_kbhit())
        {
            char znak = _getch();

            if (znak != 'x')
            {
        liczn=liczn+5;
            }

            break;
        }

        auto teraz = chrono::steady_clock::now();

        auto sekundy = chrono::duration_cast<chrono::seconds>(
            teraz - start
        ).count();

        cout << "\rPozostalo: " << 2 - sekundy << " sekund   ";

        if (sekundy >= 2)
        {
liczn=liczn+5;
            break;
        }


        this_thread::sleep_for(chrono::milliseconds(100));
    }

}
else if (t[x-1][y-1]<5 && t[x-1][y-1]!=1 && x==tempy-1 && y==tempx+1 && t[tempy-1][tempx-1]>=5)
{
    a[x-1][y-1] = 'X';
cout << "Nacisnij 'x' w ciagu 2 sekund!\n";

    auto start = chrono::steady_clock::now();

    while (true)
    {

        if (_kbhit())
        {
            char znak = _getch();

            if (znak != 'x')
            {
        liczn=liczn+5;
            }
liczn=liczn+5;
            break;
        }

        auto teraz = chrono::steady_clock::now();

        auto sekundy = chrono::duration_cast<chrono::seconds>(
            teraz - start
        ).count();

        cout << "\rPozostalo: " << 2 - sekundy << " sekund   ";

        if (sekundy >= 2)
        {
liczn=liczn+5;
            break;
        }


        this_thread::sleep_for(chrono::milliseconds(100));
    }
}



else if (t[x-1][y-1]>=5 && t[x-1][y-1]!=1 && x==tempy && y==tempx-1 && t[tempy-1][tempx-1]>=5)
{

a[x-1][y-1] = '1';
    cout << "Nacisnij 'y' w ciagu 2 sekund!\n";

    auto start = chrono::steady_clock::now();

    while (true)
    {

        if (_kbhit())
        {
            char znak = _getch();

            if (znak == 'y')
            {
        liczy=liczy+4;
            }

            break;
        }

        auto teraz = chrono::steady_clock::now();

        auto sekundy = chrono::duration_cast<chrono::seconds>(
            teraz - start
        ).count();

        cout << "\rPozostalo: " << 2 - sekundy << " sekund   ";

        if (sekundy >= 2)
        {

            break;
        }


        this_thread::sleep_for(chrono::milliseconds(100));
    }
}
else if (t[x-1][y-1]>=5 && t[x-1][y-1]!=1 && x==tempy-1 && y==tempx && t[tempy-1][tempx-1]>=5)
{
cout << "Nacisnij 'y' w ciagu 2 sekund!\n";

    auto start = chrono::steady_clock::now();

    while (true)
    {

        if (_kbhit())
        {
            char znak = _getch();

            if (znak == 'y')
            {
        liczy=liczy+4;
            }

            break;
        }

        auto teraz = chrono::steady_clock::now();

        auto sekundy = chrono::duration_cast<chrono::seconds>(
            teraz - start
        ).count();

        cout << "\rPozostalo: " << 2 - sekundy << " sekund   ";

        if (sekundy >= 2)
        {
            break;
        }


        this_thread::sleep_for(chrono::milliseconds(100));
    }
a[x-1][y-1] = '1';
}
else if (t[x-1][y-1]>=5 && t[x-1][y-1]!=1 && x==tempy && y==tempx+1 && t[tempy-1][tempx-1]>=5)
{
cout << "Nacisnij 'y' w ciagu 2 sekund!\n";

    auto start = chrono::steady_clock::now();

    while (true)
    {

        if (_kbhit())
        {
            char znak = _getch();

            if (znak == 'y')
            {
        liczy=liczy+4;
            }

            break;
        }

        auto teraz = chrono::steady_clock::now();

        auto sekundy = chrono::duration_cast<chrono::seconds>(
            teraz - start
        ).count();

        cout << "\rPozostalo: " << 2 - sekundy << " sekund   ";

        if (sekundy >= 2)
        {
            break;
        }


        this_thread::sleep_for(chrono::milliseconds(100));
    }
a[x-1][y-1] = '1';
}
else if (t[x-1][y-1]>=5 && t[x-1][y-1]!=1 && x==tempy+1 && y==tempx && t[tempy-1][tempx-1]>=5)
{
cout << "Nacisnij 'y' w ciagu 2 sekund!\n";

    auto start = chrono::steady_clock::now();

    while (true)
    {

        if (_kbhit())
        {
            char znak = _getch();

            if (znak == 'y')
            {
        liczy=liczy+4;
            }

            break;
        }

        auto teraz = chrono::steady_clock::now();

        auto sekundy = chrono::duration_cast<chrono::seconds>(
            teraz - start
        ).count();

        cout << "\rPozostalo: " << 2 - sekundy << " sekund   ";

        if (sekundy >= 2)
        {
            break;
        }


        this_thread::sleep_for(chrono::milliseconds(100));
    }
a[x-1][y-1] = '1';
}
else if (t[x-1][y-1]>=5 && t[x-1][y-1]!=1 && x==tempy-1 && y==tempx-1 && t[tempy-1][tempx-1]>=5)
{
cout << "Nacisnij 'y' w ciagu 2 sekund!\n";

    auto start = chrono::steady_clock::now();

    while (true)
    {

        if (_kbhit())
        {
            char znak = _getch();

            if (znak == 'y')
            {
        liczy=liczy+4;
            }

            break;
        }

        auto teraz = chrono::steady_clock::now();

        auto sekundy = chrono::duration_cast<chrono::seconds>(
            teraz - start
        ).count();

        cout << "\rPozostalo: " << 2 - sekundy << " sekund   ";

        if (sekundy >= 2)
        {
            break;
        }


        this_thread::sleep_for(chrono::milliseconds(100));
    }
a[x-1][y-1] = '1';
}
else if (t[x-1][y-1]>=5 && t[x-1][y-1]!=1 && x==tempy-1 && y==tempx-1 && t[tempy-1][tempx-1]>=5)
{
cout << "Nacisnij 'y' w ciagu 2 sekund!\n";

    auto start = chrono::steady_clock::now();

    while (true)
    {

        if (_kbhit())
        {
            char znak = _getch();

            if (znak == 'y')
            {
        liczy=liczy+4;
            }

            break;
        }

        auto teraz = chrono::steady_clock::now();

        auto sekundy = chrono::duration_cast<chrono::seconds>(
            teraz - start
        ).count();

        cout << "\rPozostalo: " << 2 - sekundy << " sekund   ";

        if (sekundy >= 2)
        {

            break;
        }


        this_thread::sleep_for(chrono::milliseconds(100));
    }
a[x-1][y-1] = '1';
}else if (t[x-1][y-1]>=5 && t[x-1][y-1]!=1 && x==tempy+1 && y==tempx-1 && t[tempy-1][tempx-1]>=5)
{
cout << "Nacisnij 'y' w ciagu 2 sekund!\n";

    auto start = chrono::steady_clock::now();

    while (true)
    {

        if (_kbhit())
        {
            char znak = _getch();

            if (znak == 'y')
            {
        liczy=liczy+4;
            }

            break;
        }

        auto teraz = chrono::steady_clock::now();

        auto sekundy = chrono::duration_cast<chrono::seconds>(
            teraz - start
        ).count();

        cout << "\rPozostalo: " << 2 - sekundy << " sekund   ";

        if (sekundy >= 2)
        {
            break;
        }


        this_thread::sleep_for(chrono::milliseconds(100));
    }
a[x-1][y-1] = '1';
}
else if (t[x-1][y-1]>=5 && t[x-1][y-1]!=1 && x==tempy+1 && y==tempx+1 && t[tempy-1][tempx-1]>=5)
{
cout << "Nacisnij 'y' w ciagu 2 sekund!\n";

    auto start = chrono::steady_clock::now();

    while (true)
    {

        if (_kbhit())
        {
            char znak = _getch();

            if (znak == 'y')
            {
        liczy=liczy+4;
            }

            break;
        }

        auto teraz = chrono::steady_clock::now();

        auto sekundy = chrono::duration_cast<chrono::seconds>(
            teraz - start
        ).count();

        cout << "\rPozostalo: " << 2 - sekundy << " sekund   ";

        if (sekundy >= 2)
        {
            break;
        }


        this_thread::sleep_for(chrono::milliseconds(100));
    }
a[x-1][y-1] = '1';
}
else if (t[x-1][y-1]>=5 && t[x-1][y-1]!=1 && x==tempy-1 && y==tempx+1 && t[tempy-1][tempx-1]>=5)
{
cout << "Nacisnij 'y' w ciagu 2 sekund!\n";

    auto start = chrono::steady_clock::now();

    while (true)
    {

        if (_kbhit())
        {
            char znak = _getch();

            if (znak == 'y')
            {
        liczy=liczy+4;
            }

            break;
        }

        auto teraz = chrono::steady_clock::now();

        auto sekundy = chrono::duration_cast<chrono::seconds>(
            teraz - start
        ).count();

        cout << "\rPozostalo: " << 2 - sekundy << " sekund   ";

        if (sekundy >= 2)
        {
            break;
        }


        this_thread::sleep_for(chrono::milliseconds(100));
    }
a[x-1][y-1] = '1';
}
else if (t[x-1][y-1]>=5)
{
 cout << "Nacisnij 'y' w ciagu 2 sekund!\n";

    auto start = chrono::steady_clock::now();

    while (true)
    {

        if (_kbhit())
        {
            char znak = _getch();

            if (znak == 'y')
            {
        liczy=liczy+2;
            }

            break;
        }

        auto teraz = chrono::steady_clock::now();

        auto sekundy = chrono::duration_cast<chrono::seconds>(
            teraz - start
        ).count();

        cout << "\rPozostalo: " << 2 - sekundy << " sekund   ";

        if (sekundy >= 2)
        {
            break;
        }


        this_thread::sleep_for(chrono::milliseconds(100));
    }
    a[x-1][y-1] = '1';
}
else if (t[x-1][y-1]<5 && t[x-1][y-1]!=1)
{

    a[x-1][y-1] = 'X';
cout << "Nacisnij 'x' w ciagu 2 sekund!\n";

    auto start = chrono::steady_clock::now();

    while (true)
    {

        if (_kbhit())
        {
            char znak = _getch();

            if (znak != 'x')
            {
        liczn=liczn+2;
            }

            break;
        }

        auto teraz = chrono::steady_clock::now();

        auto sekundy = chrono::duration_cast<chrono::seconds>(
            teraz - start
        ).count();

        cout << "\rPozostalo: " << 2 - sekundy << " sekund   ";

        if (sekundy >= 2)
        {
liczn=liczn+2;
            break;
        }


        this_thread::sleep_for(chrono::milliseconds(100));
    }
    }

else if (t[x-1][y-1]==1)
{
   cout << "Nacisnij 'B' w ciagu 1 sekundy!\n";

    auto start = chrono::steady_clock::now();

    while (true)
    {

        if (_kbhit())
        {
            char znak = _getch();

            if (znak != 'B')
            {
        liczn=liczn+10000;
            }

            break;
        }

        auto teraz = chrono::steady_clock::now();

        auto sekundy = chrono::duration_cast<chrono::seconds>(
            teraz - start
        ).count();

        cout << "\rPozostalo: " << 1 - sekundy << " sekund   ";

        if (sekundy >= 1)
        {
liczn=liczn+10000;
            break;
        }


        this_thread::sleep_for(chrono::milliseconds(100));
    }
    a[x-1][y-1] = 'B';
}
licz2++;
tempx = y;
tempy = x;
cout <<"twoja obecna liczba punktow to: "<<liczy<<endl;
cout <<"twoja obecna liczba bledow to: "<<liczn<<endl;
}
while (liczn<15 && liczy<10);
system("cls");
cout << "   1 2 3 4 5 6 7 8 9 10"<<endl;
for (int i=0; i <10; i++)
{
    if (i!=9)
{
    cout <<i+1<<"  ";
}
else
{
    cout <<i+1<<" ";
}

    for (int j=0; j<10; j++)
    {
        if (a[i][j] == 'X')
        {
            cout << "\033[31mX\033[0m"<<" ";
        }

        else if (a[i][j]=='1')
        {
            cout <<"\033[32m1\033[0m"<<" ";
        }
        else if (a[i][j]=='B')
        {
            cout <<"\033[35mB\033[0m"<<" ";
        }
        else
        {
            cout <<a[i][j] <<" ";
        }
    }
    cout <<endl;
}
cout <<endl;
if (liczn>=15)
{
    cout <<"P R Z E G R A N A";
}
else if (liczy>=10)
{
    cout <<"W Y G R A N A";
}
    return 0;
}
}


