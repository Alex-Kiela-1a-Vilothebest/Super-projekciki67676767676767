#include <iostream>
#include <random>
using namespace std;
int t[10][10];
char a[10][10];
int main()
{
int liczn=0,liczy=0,x,y,licz2=0,tempx,tempy,d;
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
    cout <<"jesli gracz trafi na dobre pole, wowczas na tym polu pojawii sie znak '1'\n";
    cout <<"natomiast, jesli gracz trafi na zle pole pojawii sie znak 'X'\n";
    cout <<"istnieje rowniez 10% szans na trafienie pola o nazwie bomba, opisanego znakiem 'B'\n";
    cout <<"gracz ma 4 zycia, a do wygranej musi zdobyc 3 punkty.\n";
    cout <<"za kazde dobre pole gracz zdobywa punkt, natomiast za kazde zle pole gracz traci zycie, natomiast za trafienie na pole B, gracz natychmiastowo przegrywa.\n";
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

for (int i=0; i <10; i++)
{
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

    cout <<"wybierz wspolzedne x :";
cin >>x;

while (x>10 || x<1)
{
    cout <<"wybierz wspolzedne x :";
    cin >>x;
}
cout <<"wybierz wspolzedne y :";
cin >>y;

while (y>10 || y<1)
{
    cout <<"wybierz wspolzedne y :";
    cin >>y;
}
}
while (x==tempx && y==tempy);

if (t[x-1][y-1]>=5)
{
    liczy++;
    a[x-1][y-1] = '1';
}
else if (t[x-1][y-1]<5 && t[x-1][y-1]!=1)
{
    {
    liczn++;
    a[x-1][y-1] = 'X';
    }
}
else if (t[x-1][y-1]==1)
{
    liczn = 4;
    a[x-1][y-1] = 'B';
}
licz2++;
tempx = x;
tempy = y;
cout <<"twoja obecna liczba punktow to: "<<liczy<<endl;
cout <<"twoja obecna liczba bledow to: "<<liczn<<endl;
}
while (liczn!=4 && liczy!=3);
system("cls");
for (int i=0; i <10; i++)
{
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
if (liczn==4)
{
    cout <<"P R Z E G R A N A";
}
else if (liczy==3)
{
    cout <<"W Y G R A N A";
}
    return 0;
}
}


