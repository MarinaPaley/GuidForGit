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
* \brief Считать сторону прямоугольника из консоли.
* \param message Побуждающее сообщение для пользователя.
* \return Сторона прямоугольника.
*/
double getSide(const std::string& message = "");

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
	try {
		const double length = getSide("Введите значение длины прямоугольника = ");
		const double width = getSide("Введите значение ширины прямоугольника = ");


		std::cout << "Введите число, соответсвующее заданию.\n"
			<< static_cast<int>(userInput::AREA) << " - вычисление площади прямоугольника.\n"
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
	}
	catch (std::out_of_range&)
	{
		std::cout << "Введена неправильная сторона!";
		return 1;
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

double getSide(const std::string& message)
{
	std::cout << message;
	double side = 0.0;
	std::cin >> side;
	if (side <= 0)
	{
		throw std::out_of_range("Введена неправильная сторона!");
	}

	return side;
}
