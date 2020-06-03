// Chisl_methods_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <math.h>
#include "windows.h"

using namespace std;

double F(double x) //функция
{
	return sin(x);
}

double IntF(double x) //первообразная от функции
{
	return -cos(x);
}

double MethodSquare(double a, double b, double h) //метод прямоугольников
{
	double  x;
	double res = 0;
	double i = 1;
	do 
	{
		x = a + i * h;
		res = res + F(x);
		i++;
	} while (i <= (b - a) / h);
	res = h * res;
	return res;
}

double MethodSympson(double a, double b, double h) //метод Симпсона
{
	double  x;
	double res = 0;
	double i = 1;
	do
	{
		x = a + i * h;
		res = res + 4 * F(x);
		i++;
		x = a + i * h;
		res = res + 2 * F(x);
		i++;
	} while (i <= (b - a) / h);
	res = res * h / 3;
	return res;
}

double MethodTrapec(double a, double b, double h) //метод трапеций
{
	double  x;
	double res = 0;
	for (double x = a + h; x < b; x += h)
		res += F(x);
	res = h * (res+(F(a)-F(b))/2);
	return res;
}

double Integral(double a, double b, double eps, double Int(double a,double b,double h)) //вычисление определенного интеграла с заданной точность
{
	double h = 0.5; //шаг разбиения
	double Icur= Int(a, b, h);//значение интеграла на текущем шаге итерации
	double Ipre;//значение интеграла на предыдущем шаге итерации
	do
	{
		Ipre = Icur;
		h = h/2;//уменьшаем шаг
		Icur = Int(a, b, h);
	} while (abs(Icur - Ipre) >= eps);
	return Icur;
}



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double a = 0; //границы интегрирования
	double b = 5.6; 
	double eps=0.00001;//погрешность численного интегрирования
	cout << "Значение интеграла " << (IntF(b) - IntF(a)) << endl;
	cout << "Погрешность " << eps << endl;
	cout << "Метод Симпсона " << (Integral(a, b, eps, MethodSympson)) << endl;
	cout << "Метод прямоугольников " << (Integral(a, b, eps, MethodSquare)) << endl;
	cout << "Метод трапеций " << (Integral(a, b, eps, MethodTrapec)) << endl;
}
