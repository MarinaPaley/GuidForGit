#include <iostream>

/**
* \brief Рассчивает периметр прямоугольника.
* \param length Длина прямоугольника.
* \param width Ширина прямоугольника.
* \return Периметр прямоугольника.
*/
double getPerimeter(double length, double width);

/**
* \brief Рассчивает площадь прямоугольника.
* \param length Длина прямоугольника.
* \param width Ширина прямоугольника.
* \return Площадь прямоугольника.
*/
double getArea(double length, double width);


/**
* \brief Пользовательский ввод
* \param PERIMETER Расчет периметра прямоугольника.
* \param AREA Расчет площади прямоугольника.
*/
enum class userInput
{
	PERIMETER = 1,
	AREA
};

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

	std::cout << "Введите число, соответсвующее заданию.\n"
		<< static_cast<int>(userInput::AREA) << " - вычисление площади прямоугольника "
		<< static_cast<int>(userInput::PERIMETER) << " - вычисление периметра прямоугольника.\n";

	int input = 0;
	std::cin >> input;
	const auto choice = static_cast<userInput>(input);

	switch (choice)
	{
	case userInput::AREA:
		{
			const auto area = getArea(length, width);
			std::cout << " Площадь прямоугольника = " << area;
			break;
		}
	case userInput::PERIMETER:
		{
			const auto perimetr = getPerimeter(length, width);
			std::cout << "Периметр прямоугольника = " << perimetr;
			break;
		}
	}

	
	return 0;
}

double getPerimeter(const double length, const double width)
{
	return (length + width) * 2;
}

double getArea(const double length, const double width)
{
	return length * width;
}
