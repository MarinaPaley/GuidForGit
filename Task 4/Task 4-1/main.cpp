#include <string>
#include <iostream>
#include <random>


/**
* \brief Считывает размер массива.
* \param message Сообщение пользователю.
* \return Размер массива.
*/
size_t getSize(const std::string& message = "", size_t maxSize = std::numeric_limits<std::size_t>::max());

/**
* \brief Считывает значения элементов массива с клавиатуры.
* \param size длина массива.
* \return Массив.
*/
int* getManualInputArray(const size_t size);

/**
* \brief Заполнение массива случайными числами.
* \param size Длина массива.
* \param minValue Минимальное значение массива.
* \param maxValue Максимальное значение массива.
* \return Массив.
*/
int* getRandomInputArray(const size_t size, const int minValue = -10, const int maxValue = 10);

/**
* \brief Печатает массив.
* \param array Массив.
* \param size длина массива.
* \param out Поток вывода.
*/
void print(int* array, const size_t size, std::ostream& out = std::cout);

/**
* \brief Меняет последние k элементов массива на противоположные по знаку.
* \param array Массив.
* \param size длина массива.
* \param k Количество элементов для замены.
*/
void exchangeLastKElementsByOpposite(int* array, const size_t size, const size_t k);

/**
* \brief Заменяет средний элемент массива на минимальный по значению элемент.
* \param array Массив.
* \param size длина массива.
*/
void exchangeMiddleElementByMinValue(int* array, const size_t size);


/**
* \brief Находит минимальный по значению элемент.
* \param array Массив.
* \param size длина массива.
* \return Минимальный по значению элемент.
*/
int getMin(int* array, const size_t size);

/**
* \brief Находит номер первой пары соседних элементов с разными знаками.
* \param array Массив.
* \param size длина массива.
* \return Номер первой пары соседних элементов с разными знаками.
*/
size_t getPairNumberWithOppositeSign(int* array, const size_t size);

/**
* \brief Класс для выбора заполнения массива.
* \param MANUAL Ручной способ.
* \param RANDOM Заполнение массива случайными числами.
*/
enum class arrayInputChoice
{
	MANUAL,
	RANDOM
};

/**
* \brief Точка входа в программу.
* \return В случае успеха возвращает 0.
*/
int main()
{
	try {
		const auto size = getSize("Введите размер массива = ");
		int* myArray = nullptr;

		std::cout << "Введите требуемое действие \n" << static_cast<int>(arrayInputChoice::MANUAL) << " для ручного ввода массива\n"
			<< static_cast<int>(arrayInputChoice::RANDOM) << " для заполнения массива случайными числами\n";
		int userInput = 0;
		std::cin >> userInput;
		const auto choice = static_cast<arrayInputChoice>(userInput);

		switch (choice)
		{
		case arrayInputChoice::MANUAL:
		{
			myArray = getManualInputArray(size);
			break;
		}
		case arrayInputChoice::RANDOM:
		{
			myArray = getRandomInputArray(size);
			break;
		}
		default:
			std::cerr << "Вы ввели некорректное действие!";
			return 1;
		}

		print(myArray, size);

		const auto k = getSize("Введете значение k = ", size);
		
		exchangeLastKElementsByOpposite(myArray, size, k);
		std::cout << "Меняет последние k элементов массива на противоположные по знаку.\n";
		print(myArray, size);

		exchangeMiddleElementByMinValue(myArray, size);
		std::cout << "Заменяет средний элемент массива на минимальный по значению элемент.\n";
		print(myArray, size);


		const auto numberPair = getPairNumberWithOppositeSign(myArray, size);
		if (numberPair < size)
		{
			std::cout << "Номер первой пары соседних элементов с разными знаками = " << numberPair;
		}
		else
		{
			std::cout << "Все пары имеют одинаковые знаки";
		}


		if (myArray != nullptr)
		{
			delete[] myArray;
			myArray = nullptr;
		}

		return 0;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
		return 1;
	}
}

size_t getSize(const std::string& message, size_t maxSize)
{
	const auto TRESHOLD = 1;
	int size = TRESHOLD;
	std::cout << message;
	std::cin >> size;

	if (size < TRESHOLD || size > maxSize)
	{
		throw std::out_of_range("Введен неправильный размер массива!");
	}

	return size;
}

int* getManualInputArray(const size_t size)
{
	int* myArray = new int[size];

	std::cout << "Введите элементы массива\n";
	for (size_t i = 0; i < size; i++)
	{
		std::cout << "A[" << i + 1 << "] = ";
		std::cin >> myArray[i];
	}

	return myArray;
}

int* getRandomInputArray(const size_t size, const int minValue, const int maxValue)
{
	std::random_device random;
	std::mt19937 gen(random());
	const std::uniform_int_distribution<int> uniformDistrinbution(minValue, maxValue);

	int* myArray = new int[size];
	for (size_t i = 0; i < size; i++)
	{
		myArray[i] = uniformDistrinbution(gen);
	}

	return myArray;
}

void print(int* array, const size_t size, std::ostream& out)
{

	if (array == nullptr)
	{
		throw std::out_of_range("Массив не определен!");
	}

	out << "Массив:\n";
	for (size_t i = 0; i < size; i++)
	{
		out << array[i] << " ";
	}
	out << "\n";
}

void exchangeLastKElementsByOpposite(int* array, const size_t size, const size_t k)
{
	if (array == nullptr)
	{
		throw std::out_of_range("Массив не определен!");
	}

	for (size_t i = size - k; i < size; i++)
	{
		array[i] *= -1;
	}
}

void exchangeMiddleElementByMinValue(int* array, const size_t size)
{
	if (size % 2 == 0)
	{
		std::cout << "Данная функция не может быть реализована, так как размер массива является четным числом!\n";
		return;
	}

	const size_t indexOfMiddle = size / 2;
	array[indexOfMiddle] = getMin(array, size);
}

int getMin(int* array, const size_t size)
{
	auto min = array[0];

	for (size_t i = 1; i < size; i++)
	{
		if (min > array[i])
		{
			min = array[i];
		}
	}
	return min;
}

size_t getPairNumberWithOppositeSign(int* array, const size_t size)
{
	size_t pairNumber = 0;
	while (pairNumber < size - 1 && array[pairNumber] * array[pairNumber + 1] >= 0)
	{
		pairNumber++;
	}
	return pairNumber + 1;
}
