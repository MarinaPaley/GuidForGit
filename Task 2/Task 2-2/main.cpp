#include <iostream>

/**
* \brief Функция расчета значений для аргумента меньше, чем пороговое значение.
* \param x - Аргумент функции.
* \param a - Константное значение.
* \return Значение функции в точке \a x.
*/
double getFunctionBelowTreshold(const double x, const double a);

/**
* \brief Функция расчета значений для аргумента больше или равно пороговому значению.
* \param x - Аргумент функции.
* \param a - Константное значение.
* \return Значение функции в точке \a x.
*/
double getFunctionAboveOrEqualTreshold(const double x, const double a);

/**
* \brief Точка входа в программу.
* \return Возвращает 0 в случае успеха.
*/
int main()
{
	std::cout << "Введите значение x = ";
	double x = 0.0;
	std::cin >> x;

	const double THRESHOLD = 2.7;
	const double a = 3.5;

	if (x < THRESHOLD)
	{
		const double y = getFunctionBelowTreshold(x, a);
		std::cout << " y = " << y;
	}
	else
	{
		const double y = getFunctionAboveOrEqualTreshold(x, a);
		std::cout << " y = " << y;
	}

	return 0;
}

double getFunctionBelowTreshold(const double x, const double a)
{
	return a * x / 3 + std::pow(x, 3);
}

double getFunctionAboveOrEqualTreshold(const double x, const double a)
{
	return std::cbrt(std::pow(x, 3 * a)) * (a + 3 * x);
}
