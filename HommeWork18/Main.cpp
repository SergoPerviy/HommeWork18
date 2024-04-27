#include <iostream>

int my_sum(int num1, int num2=0, int num3=0, int num4=0, int num5=0) {
	int result = num1 + num2 + num3 + num4 + num5;
	return result;
}

inline double my_mean(int num1, int num2, int num3) {
	double result = double(num1 + num2 + num3) / 3;
	return result;
}

short my_max(short num1, short num2, short num3) {
	std::cout << "Тип переменных SHORT\nМаксимальное число из " << num1 << ", " << num2 << ", " << num3 << " равно: ";
	return short(num1 > num2 && num1 > num3 ? num1 : num2 > num3 ? num2 : num3);
}

int my_max(int num1, int num2, int num3) {
	std::cout << "Тип переменных INT\nМаксимальное число из " << num1 << ", " << num2 << ", " << num3 << " равно: ";
	return num1 > num2 && num1 > num3 ? num1 : num2 > num3 ? num2 : num3;
}

double my_max(double num1, double num2, double num3) {
	std::cout << "Тип переменных DOUBLE\nМаксимальное число из " << num1 << ", " << num2 << ", " << num3 << " равно: ";
	return num1 > num2 && num1 > num3 ? num1 : num2 > num3 ? num2 : num3;
}

template <typename T>
void my_positive_arr(T arr[], const int lenght) {
	for (int i = 0; i < lenght; i++) {
		if (arr[i] < 0) {
		for (int j = i; j < lenght-1; j++) {
			arr[j+1] = 0;
			}
		}
	}
}

int main() {
	setlocale(LC_ALL, "Russian");

	int a{}, b{}, c{}, m{}, n{};

	/*
	Задача 1.
	Создайте функцию, которая принимает от 1-го до 5-ти (включительно) разных чисел, после чего возвращает их сумму. 
	Для решения необходимо использовать параметры по умолчанию. Учтите, что в функции должен быть один обязательный параметр.
	*/

	std::cout << "Задача №1.\nВведите 5 чисел -> ";
	std::cin >> a >> b >> c >> m >> n;
	std::cout << "Сумма чисел: " << a << ", " << b << ", " << c << ", " << m << ", " << n << " равна: " <<
		my_sum(a, b, c, m, n) << "\n\n";

	/*
	Задача 2.
	Создайте встраиваемую функцию, которая принимает три числа и возвращает их среднее арифметическое.
	*/

	std::cout << "Задача №2.\nВведите 3 числа -> ";
	std::cin >> a >> b >> c;
	std::cout << "Среднее арифметическое чисел: " << a << ", " << b << ", " << c << " равно: " <<
		my_mean(a, b, c) << "\n\n";

	/*
	Задача 3.
	Создайте перегруженную функцию для нахождения максимального из трёх переданных в неё значений. 
	Функция должна поддерживать типы int, short и double. Также функция должна выводить тип переданных в неё значений.
	*/

	std::cout << "Задача №3.\n";
	std::cout << my_max(1, 2, 3) << "\n"; //В консоли тип данных будет определен как INT.
	std::cout << my_max(1.1, 2.2, 3.3) << "\n";
	std::cout << my_max(32768, 32768, 32769) << "\n\n";
	
	/*
	Задача 4
	Напишите шаблонную функцию, которая принимает массив любого типа и его длину типа int. Функция должна найти 
	первое отрицательное число в массиве и обнулить все элементы массива, которые находятся справа от него.
	*/

	std::cout << "Задача№4\nИзначальный массив:\n";
	
	const int size = 5;
	int arr[size] = { 1, -1, 2, 3, 4 };
	std::cout << "{ ";
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b }\n";

	my_positive_arr(arr, size);

	std::cout << "Измененный массив:\n";
	std::cout << "{ ";
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b }\n";

	return 0;
}