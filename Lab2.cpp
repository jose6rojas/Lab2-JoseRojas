// viernes, 28 de abril de 2017
// Laboratorio II - Programacion III
// Jose Carlos Rojas Herrera - 11541234

#include <iostream>
#include <cmath>

int factorial(int);

using namespace std;

int main()
{

	int x;
	cout << "Ejercicio 1 - Numero de Euler\n" << "Ingrese un numero: ";
	cin >> x;
	cout << factorial(x) << endl;
	
	double numerador = 0;
	int denominador = 0;
	double Euler = 0;
	for(int i = 1; i <= 13; i++)
	{
		numerador = pow(x, i);
		denominador = factorial(i);
		Euler += (numerador / denominador);
	}
	Euler++;
	cout << "e^(" << x << ") = " << Euler << endl;
	
	int x1, y1, x2, y2, x3, y3, x4, y4;
	
	return 0;

}

int factorial(int x)
{
	int f = 1;
	for(int i = 1; i <= x; i++)
		f *= i;
	return f;
}
