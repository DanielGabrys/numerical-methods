#include <iostream>
#include <fstream>
#include <string>

using namespace std;

double x;
int p;

double* tabX = new double[p];
double* tabY = new double[p];


int wczytaj()
{

	ifstream plik;
	int counter = 0;

	plik.open("C:\\Users\\danie\\Desktop\\dane.txt");
	if (!plik.good())
		return 0;

	while (1==1) //pętla nieskończona
	{

		if (!plik.fail())
		{
			if (counter < 1) //w  drugiej lini zaczyna sie ciag argumentów
			{
				plik >> p;
				plik >> x;
				if (p < 1) return 0;
			}
			else
			{
				

				for (int i = 0; i < p; i++)
				{
					plik >> tabX[i];
					if (x == tabX[i])
						return 0;
				}

				for (int i = 0; i < p; i++)
				{
					plik >> tabY[i];
				}
			}
			counter++;
		}
		else
			break; //zakończ wczytywanie danych - wystąpił jakiś błąd (np. nie ma więcej danych w pliku)

	}
	return 1;

}


double **macierz(double *tabx, double*taby, int n)
{
	double **M = new double *[n-1]; // tablica NxN wartosci ilorazow, na glównej przekątnej znajdą sie szukane wspolczynniki
	for (int i = 0; i < n - 1; i++) //pierwszy rzad
	{
		
		M[i] = new double[n-1];
		M[0][i] = (taby[i + 1] - taby[i]) / (tabx[i+1]-tabx[i]);
	}

	for (int j = 1; j < n-1; j++) //kolejne rzedy
	{
		for (int i = j; i < n-1; i++)
		{
			double d=M[j][i] = (M[j - 1][i] - M[j - 1][i - 1]) / (tabx[i + 1] - tabx[i - j]); //kolejne ilorazy

			//cout<<M[j - 1][i]<<"-"<< M[j - 1][i - 1]<<":"<<tabx[i + 1]<<"-"<<tabx[i - j]<<endl;
			//cout << d << endl;
		}
	}
	
	return M;
}


int main() {

	int dane=wczytaj();
	if (dane == 1)
	{
		double** M = macierz(tabX, tabY, p); //macierz wspolczynnikow

		double wynik = tabY[0]; //pierwszy element wyrazenia
		for (int i = 1; i < p; i++) // wykonuje sie dla punktow
		{
			double iloczyn = 1;
			double wpol = M[i - 1][i - 1]; //wspolczynniki przed nawiasami,bierzemy elementy z przekatnej maciezy
			for (int j = 0; j < i; j++) // mnozenie nawiasow
			{
				iloczyn *= (x - tabX[j]);
			}
			iloczyn *= wpol;
			wynik += iloczyn; //dodajemy czlony 
		}

		cout << "WYNIK: " << wynik << endl;

		for (int i = 0; i < p - 1; i++) 
			delete[] M[i];

		delete[] M;
	}
	else
		cout << "bledne dane"<< endl;
	

	
}
