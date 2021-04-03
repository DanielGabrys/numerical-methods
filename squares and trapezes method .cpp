#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> 
#include <cmath>

using namespace std;

int p;
int przedzialy;
double poczatek, koniec;

double* tabX;


int wczytaj()
{

	ifstream plik;
	

	plik.open("C:\\Users\\danie\\Desktop\\dane.txt");
	if (!plik.good())
		return 0;

	while (true)
	{
		plik >> p >> przedzialy;
		
		for (int i = 0; i < p + 1; i++)
		{
			double m;
			plik >> m;
			tabX[i] = m;
			cout << tabX[i] << endl;
		}

		plik >> poczatek;
		plik >> koniec;

		if (plik.fail())
			break; 
	}
	return 1;
			
}


double fx(int p,double *tabX,double xn)
{
	double wynik = 0.0;
	double pot = 1.0;
	for (int i=0; i<p+1; i++) //dla p+1 ilosci wspolczynnikow, gdzie p stopien wielomianu
	{
		for (int j = i; j < p; j++)
		{
			pot *= xn; // potegujemy dany wyraz wielomianu
		}
		wynik += tabX[i]*pot; //przemnazamy przez wspolczynnik i sumujemy
		pot = 1;
	}
	if (wynik >= 0) //jezeli wartość wynosi zero musimy zmienic znak, inaczej pola się odejmą zamiast dodac
		return wynik;
	else
		return -wynik;

}

double funkcja_niewielomianowa(double xn)
{
	//tutaj okreslic wzor funkcji

	return 1 / (xn*xn + 1);
	//return sin(xn);
	//return pow( xn, 0.5 );
}




double kwadraty(int st, int prze,double *tabx, double pocz, double kon)
{
	double w = 0.0;
	double pocz2 = pocz; //poczatek przedzialu
	double dx = (kon - pocz) / double(prze); //rozmiar przedzialu
	for (int i = 1; i < prze+ 1; i++) //kolejne rzedy
	{
		
		w += fx(st, tabX, pocz2 + dx); //obliczenie wartosci funkcji dla kolejnych przedzialow
		//w+=funkcja_niewielomianowa(pocz2 + dx);
		pocz2 += dx;
		
	}
	return w*dx;
}

double trapezy(int st, int prze, double *tabx, double pocz, double kon)
{
	double w = 0.0;
	double pocz2 = pocz;
	double dx = (kon - pocz) / double(prze); 
	for (int i = 1; i < prze; i++) //liczy najpierw dla elementow srodkowych 
	{

		w += fx(st, tabX, pocz2 + dx);
		//w+=funkcja_niewielomianowa(pocz2 + dx);
		pocz2 += dx;

	}
	w*= dx;

	 //dodajemy 1 i ostatni element
	 w +=( (fx(st, tabX, pocz) + fx(st, tabX, kon))*dx / 2.0); //dodajemy pierwszy i ostatni element
	// w += ( (funkcja_niewielomianowa(pocz) + funkcja_niewielomianowa(kon))*dx / 2.0);
	 return w;
}

int main() {

	//int s=wczytaj();
	
	cin >> p;
	cin>> przedzialy;
	tabX =new double[p + 1];
	

	for (int i = 0; i < p + 1; i++)
	{
		cin >> tabX[i];
	}
	cin >> poczatek >> koniec;
	
	//cout << p<<" "<<przedzialy<<" "<<poczatek << " " << koniec << endl; 
	double wynik = kwadraty(p, przedzialy, tabX, poczatek, koniec);
	cout<< "METODA KWADRATOW: " << setprecision(12)<<wynik << endl;

	double wynik2 = trapezy(p, przedzialy, tabX, poczatek, koniec);
	cout << "METODA TRAPEZOW: " << setprecision(12)<<wynik2 << endl;
	
	//delete [] tabX;
	


}
