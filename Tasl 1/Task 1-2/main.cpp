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
* \brief Считывает сторону прямоугольника.
* \param message Побуждающее сообщение.
* \return Сторноа прямоугольника.
*/
double getSide(const std::string& message = "");

/**
* \brief Точка входа в программу.
* \return Возвращает 0 в случае успеха.
*/

int main()
{
	const double length = getSide("Введите значение длины прямоугольника = ");
	const double width = getSide("Введите значение ширины прямоугольника = ");

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

double getSide(const std::string& message)
{
	std::cout << message;
	double side = 0.0;
	std::cin >> side;
	return side;
}
