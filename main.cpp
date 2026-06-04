#include <iostream>
#include <random>
using namespace std;
int t[10][10];
int main()
{
int liczn=0,liczy=0,x,y;
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> dist(0,10);
while (liczn!=3 && liczy!=3)
{
    cout <<"twoja obecna liczba punktow to: "<<liczy<<endl;
    cout <<"twoja obecna liczba bledow to: "<<liczn<<endl;
    for (int i=0; i <10; i++)
{
    for (int j=0; j<10; j++)
    {
        t[i][j] = dist(gen);
    }
}
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
if (t[x-1][y-1]>=5)
{
    liczy++;
}
else
    {
    liczn++;
    }
}
cout <<"twoja obecna liczba punktow to: "<<liczy<<endl;
cout <<"twoja obecna liczba bledow to: "<<liczn<<endl;
if (liczn==3)
{
    cout <<"PRZEGRANA";
}
else if (liczy==3)
{
    cout <<"WYGRANA";
}
    return 0;
}
