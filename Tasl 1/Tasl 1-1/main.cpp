#define _USE_MATH_DEFINES // for C++
#include <cmath>
#include <iostream>

/**
*  \brief Функция расчета по заданной формуле.
*  \param x Аргумент функции.
*  \param y Аргумент функции.
*  \return Значение функции.
*/
double getA(double x, double y);

/**
*  \brief Функция расчета по заданной формуле.
*  \param x Аргумент функции.
*  \param z Аргумент функции.
*  \return Значение функции.
*/
double getB(double x, double z);
/**
* \brief Точка входа в программу.
* \return Возвращает 0 в случае успеха.
*/
int main()
{
	const double x = -1.3;
	const double y = 7.6;
	const double z = -1.85;
	const double a = getA(x, y);
	const double b = getB(x, z);
	std::cout << "x = " << x << " y = " << y << " z = " << z << "\n";
	std::cout << "a = " << a << " b = " << b << std::endl;
	return 0;
}

double getA(const double x, const double y)
{
	return exp(x / y) - cbrt(y / x);
}

double getB(const double x, const double z)
{
	return 2 * cos(x - M_PI_2) / (1.0/ 2 + sin(z) * sin(z));
}
