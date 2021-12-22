#define _USE_MATH_DEFINES // for C++
#include <cmath>
#include <iostream>

/**
*  \brief Функция расчета по заданной формуле.
*  \param x Первый параметр функции.
*  \param y Второй параметр функции.
*  \return Значение функции.
*/
double getA(double x, double y);

/**
*  \brief Функция расчета по заданной формуле.
*  \param x Первый параметр функции.
*  \param z Второй параметр функции.
*  \return Значение функции.
*/
double getB(double x, double z);
/**
* \brief Точка входа в программу.
* \return Возвращает 0 в случае успеха.
*/
int main()
{
	const auto x = -1.3;
	const auto y = 7.6;
	const auto z = -1.85;
	const auto a = getA(x, y);
	const auto b = getB(x, z);

	std::cout << "x = " << x << " y = " << y << " z = " << z << "\n";
	std::cout << "a = " << a << " b = " << b << std::endl;

	return 0;
}

double getA(const double x, const double y)
{
	return std::exp(x / y) - std::cbrt(y / x);
}

double getB(const double x, const double z)
{
	return 2 * std::cos(x - M_PI_2) / (1.0 / 2 + std::sin(z) * std::sin(z));
}
