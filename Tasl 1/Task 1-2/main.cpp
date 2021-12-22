#include <iostream>

/**
* \brief Рассчивает периметр прямоугольника.
* \param length Длина прямоугольника.
* \param width Ширина прямоугольника.
* \return Периметр прямоугольника.
*/
double getPerimetr(double length, double width);

/**
* \brief Рассчивает площадь прямоугольника.
* \param length Длина прямоугольника.
* \param width Ширина прямоугольника.
* \return Площадь прямоугольника.
*/
double getArea(double length, double width);

/**
* \brief Точка входа в программу.
* \return Возвращает 0 в случае успеха.
*/

int main()
{
	std::cout << "Введите значение длины прямоугольника = ";
	double length = 0.0;
	std::cin >> length;
	std::cout << "Введите значение ширины прямоугольника = ";
	double width = 0.0;
	std::cin >> width;

	const double perimetr = getPerimetr(length, width);
	const double area = getArea(length, width);

	std::cout << "Периметр прямоугольника = " << perimetr <<
		" Площадь прямоугольника = " << area;


	return 0;
}

double getPerimetr(const double length, const double width)
{
	return (length + width) * 2;
}

double getArea(const double length, const double width)
{
	return length * width;
}
