// viernes, 28 de abril de 2017
// Laboratorio II - Programacion III
// Jose Carlos Rojas Herrera - 11541234

#include <iostream>
#include <cmath>

int factorial(int);
double distancia(double, double, double, double);
double altura(double, double, double, double, double);

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
	cout << "e^(" << x << ") = " << Euler << endl << endl;
	
	double x1, y1, x2, y2, x3, y3, x4, y4;
	cout << "Ejercicio 2 - Area de un Trapezoide\n" << "Ingrese x1 [A]: ";
	cin >> x1;
	cout << "Ingrese y1 [A]: ";
	cin >> y1;
	cout << "Ingrese x2 [B]: ";
	cin >> x2;
	cout << "Ingrese y2 [B]: ";
	cin >> y2;
	cout << "Ingrese x3 [C]: ";
        cin >> x3;
        cout << "Ingrese y3 [C]: ";
        cin >> y3;
	cout << "Ingrese x4 [D]: ";
        cin >> x4;
        cout << "Ingrese y4 [D]: ";
        cin >> y4;
	// TODO: Validar las coordenadas
	cout << endl << "Los puntos son:" << endl;
	cout << "A(" << x1 << ", " << y1 << ")" << endl;
	cout << "B(" << x2 << ", " << y2 << ")" << endl;
	cout << "C(" << x3 << ", " << y3 << ")" << endl;
	cout << "D(" << x4 << ", " << y4 << ")" << endl << endl;
	
	// distancias
	double CD = distancia(x3, y3, x4, y4);
	double DB = distancia(x4, y4, x2, y2);
	double BA = distancia(x2, y2, x1, y1);
	double AC = distancia(x1, y1, x3, y3);
	cout << "Los lados del trapezoide miden:" << endl;
	cout << "Lado 1: CD = " << CD << endl;
	cout << "Lado 2: DB = " << DB << endl;
	cout << "Lado 3: BA = " << BA << endl;
	cout << "Lado 4: AC = " << AC << endl << endl;
	
	// diagonales
	double CB = distancia(x3, y3, x2, y2);
	double AD = distancia(x1, y1, x4, y4);
	
	cout << "Los lados del triangulo 1 miden:" << endl;
	cout << "Lado 1: CD = " << CD << endl;
	cout << "Lado 2: AD = " << AD << endl;
	cout << "Lado 3: AC = " << AC << endl << endl;
	
	cout << "Los lados del triangulo 2 miden:" << endl;
        cout << "Lado 1: DB = " << DB << endl;
        cout << "Lado 2: BA = " << BA << endl;
        cout << "Lado 3: AD = " << AD << endl << endl;
	
	// semi-perimetros
	double s1, s2;
	s1 = (CD + AD + AC) / 2;
	s2 = (DB + BA + AD) / 2;
	double p1, p2;
	p1 = 2 * s1;
	p2 = 2 * s2;
	cout << "Semi-perimetro triangulo 1: " << s1 << endl;
	cout << "Semi-perimetro triangulo 2: " << s2 << endl;
	cout << "Perimetro triangulo 1: " << p1 << endl;
	cout << "Perimetro triangulo 2: " << p2 << endl << endl;
	
	// alturas
	double h1, h2, h3, area1 = 0;
	h1 = altura(s1, CD, CD, AD, AC);
	h2 = altura(s1, AD, CD, AD, AC);
	h3 = altura(s1, AC, CD, AD, AC);
	int op_CDA;
	cout << "Triangulo CDA\n1. CD\n2. AD\n3. AC\nEscoja la base del primer triangulo: ";
	cin >> op_CDA;
	if(op_CDA == 1)
	{
		// cout << CD << endl << h1 << endl;
		area1 = (0.5) * CD * h1;
		// cout << area1 << endl;
	}
	else if(op_CDA == 2)
	{
		area1 = (0.5) * AD * h2;
	}
	else if(op_CDA == 3)
	{
		area1 = (0.5) * AC * h3;
	}
	else
	{
		cout << "Escoja una opcion valida." << endl;
	}
	cout << "Las alturas del triangulo 1 miden:" << endl;
	cout << "Altura 1: " << h1 << endl;
	cout << "Altura 2: " << h2 << endl;
	cout << "Altura 3: " << h3 << endl << endl;
	
	double h4, h5, h6, area2 = 0;
	h4 = altura(s2, DB, DB, BA, AD);
	h5 = altura(s2, BA, DB, BA, AD);
	h6 = altura(s2, AD, DB, BA, AD);
	int op_DBA;
	cout << "Triangulo DBA\n1. DB\n2. BA\n3. AD\nEscoja la base del segundo triangulo: ";
	cin >> op_DBA;
	if(op_DBA == 1)
	{
		area2 = (0.5) * DB * h4;
		// cout << area2 << endl;
	}
        else if(op_DBA == 2)
		area2 = (0.5) * BA * h5;
        else if(op_DBA == 3)
		area2 = (0.5) * AD * h6;
        else
                cout << "Escoja una opcion valida." << endl;
	cout << "Las alturas del triangulo 2 miden:" << endl;
        cout << "Altura 1: " << h4 << endl;
        cout << "Altura 2: " << h5 << endl;
        cout << "Altura 3: " << h6 << endl << endl;
	
	cout << "El area del trapezoide es de: " << (area1 + area2) << endl;
	
	return 0;

}

int factorial(int x)
{
	int f = 1;
	for(int i = 1; i <= x; i++)
		f *= i;
	return f;
}

double distancia(double x1, double y1, double x2, double y2)
{
	double a, b;
	a = pow((x2 - x1), 2);
	b = pow((y2 - y1), 2);
	return sqrt((a + b));
}

double altura(double s, double l, double a, double b, double c)
{
	double base;
	base = s * ((s - a) * (s - b) * (s - c));
	return (2/l) * sqrt(base);
}
