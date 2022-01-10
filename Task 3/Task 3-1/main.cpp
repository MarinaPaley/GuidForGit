#include <iostream>
#include <iomanip>

/**
* \brief Существует ли функция в точке x.
* \param x Аргумент функции.
* \return true, если существует.
*/
bool isExists(const double x);

/**
* \brief Расчет функции в точке x.
* \param x Аргумент функции.
* \return Значение функции в точке x.
*/
double getY(const double x);

/**
* \brief Точка входа в программу.
* \return 0 в случае успеха.
*/
int main()
{
	const double xStart = 0.05;
	const double xFinish = 0.8;
	const double step = 0.05;
	double x = xStart;

	std::cout << std::setw(10) << " x " << "  " << " y " << "\n";

	while (x <= xFinish + step)
	{
		if (isExists(x))
		{
			const double y = getY(x);
			std::cout << std::setw(10) << x << "  " << y << "\n";
		}
		else
		{
			std::cout << std::setw(10) << x << "  " <<"Нет решения" << "\n";
		}

		x += step;
	}
	return 0;
}

bool isExists(const double x)
{
	return std::abs(std::cos(x)) > std::numeric_limits<double>::min() && (x > std::sin(x));
}

double getY(const double x)
{
	return std::tan(x) - 1.0/ 3 * std::log(x - std::sin(x));
}
