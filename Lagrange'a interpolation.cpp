// metody_lab1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define MAX 100


double tab[MAX];
double war[MAX];

int n;
int x;

double lx(double *tab, double *war, double x, int size)
{
    double LX = 0; //wynik
    for (int j = 1; j <= size; j++)//petla dla Lx
    {
        double wynik = 1; ///uwaga
        for (int i = 1; i <= size; i++)
        {
            if (i != j) //warunek 
                wynik *= (x - tab[i-1]) / (tab[j-1] - tab[i-1]); //x-x2/x1-x2... mnozone w petli daje L1(x) itp

        }
        wynik *= war[j - 1]; // Y1*L1(x) itp
        LX += wynik; //wynik końcowy
    }
    return LX;
}

bool wczytaj()
{
    
        ifstream plik;
        int counter = 0;

        plik.open("dane.txt");
        if (!plik.good())
            return false;

        while (true) //pętla nieskończona
        {
            
                if (!plik.fail())
                {
                    if (counter <= 1) //w  drugiej lini zaczyna sie ciag argumentów
                    {
                        plik >> n;
                        plik >> x;
                    }
                    else
                    {
                        for (int i = 0; i < n; i++)
                        {
                            plik >> tab[i];
                        }

                        for (int i = 0; i < n; i++)
                        {
                            plik >> war[i];
                        }
                    }
                    counter++;
                    cout << counter << endl;

                }
            else
                break; //zakończ wczytywanie danych - wystąpił jakiś błąd (np. nie ma więcej danych w pliku)

        } 
        return true;
    
}

int main()
{
    cout<<"Podaj liczbe argumentow : " << endl;
    cout << n << endl;
    cout << "Podaj argumenty : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << tab[i];
    }
    cout << "Podaj wartosci dla argumentow : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << war[i];
    }

    cout << "podaj wartosc x:" << endl;
    cout << x;

    cout << endl << endl;


    cout << x<<endl<<endl;

    cout << "wartosc od x:" << endl;
    cout << lx(tab, war, x, n) << endl;
}


// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
