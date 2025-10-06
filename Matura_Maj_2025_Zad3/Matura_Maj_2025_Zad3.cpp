
#include <iostream>
#include <fstream>
#include <string>
#include <numeric>
#include <cmath>


using namespace std; 


ifstream fin("dron.txt");
const int Wier = 100, Kol = 2;
int Punkty[Wier][Kol];

void WczytajPunkty()
{
    int dx, dy;
    int x = 0, y = 0;   

    for (int i = 0; i < Wier; i++)
    {
        fin >> dx >> dy;   // wczytaj przesunięcie
        x += dx;           // aktualizuj pozycję
        y += dy;

        Punkty[i][0] = x;  // zapisz punkt (x,y)
        Punkty[i][1] = y;
    }
    fin.close();
}


int main()
{
    cout << "Zad.3.1\n";
    int a, b, licznik = 0;
    while (fin >> a >> b) // automatycznie czyta dwie liczby z linii
        if (gcd(abs(a), abs(b)) > 1) licznik++;
    cout << licznik << endl;

    fin.clear();   // skasuj EOF
    fin.seekg(0);  // na początek pliku

    cout << "Zad.3.2a\n";
    WczytajPunkty();
    int licz = 0;
    for (int i = 0; i < Wier; i++) {
        int x = Punkty[i][0];
        int y = Punkty[i][1];


        if (x < 5000 && y < 5000) {
            licz++;
        }
    }
    cout << licz << endl;


    cout << "Zad.3.2b\n";
    for (int i = 0; i < Wier; i++) {
        for (int j = 0; j <i; j++) {
            for (int k = 0; k < j; k++) {

                int xp = Punkty[i][0],yp = Punkty[i][1];
                int xs = Punkty[j][0],ys = Punkty[j][1];
                int xk = Punkty[k][0],yk = Punkty[k][1];

                if ( xs * 2 == xp + xk && ys * 2 == yp + yk&&xp!=xk){
                    cout << "(" << xp << ";" << yp << ")" << "(" << xs << "; " << ys << ")" << "(" << xk << ";" << yk << ")" << endl;
                }
            }
        }
    }
}

