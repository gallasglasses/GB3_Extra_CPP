// HW4

#define _USE_MATH_DEFINES

#include <iostream>
#include <numeric>
#include <vector>
#include <list>
#include <cmath>
#include "InsertSorted.h"

template <typename C>
void print(const C& container) 
{
	for (const auto& i : container) 
	{
		std::cout << i << " ";
	}
	std::cout << "\n";
}

int main()
{
#pragma region EX1

	std::cout << "This is 1 exercise\n\n";
	/*
	===================================================================================================
	1. 	Имеется отсортированный массив целых чисел. Необходимо разработать функцию insert_sorted, 
	которая принимает вектор и новое число и вставляет новое число в определенную позицию в векторе, 
	чтобы упорядоченность контейнера сохранялась. Реализуйте шаблонную функцию insert_sorted, 
	которая сможет аналогично работать с любым контейнером, содержащим любой тип значения. 
	===================================================================================================
	*/
	std::vector<int> m1 = { 0, 1, 2, 5, 9, 10, 20, 40 };
	insert_sorted(m1, 56);
	print(m1);
	std::list<double> m2 = { 0.5, 1.3, 3.14, 5.65, 10.99 };
	insert_sorted2(m2, 7.83);
	print(m2);
	std::cout << "__________________________________________________________\n\n";
#pragma endregion

#pragma region EX2

	std::cout << "This is 2 exercise\n\n";
	/*
	===================================================================================================
	2.	Сгенерируйте вектор, состоящий из 100 вещественный чисел, представляющий 
	собой значения аналогового сигнала, изменяющегося по синусоиде. На основе этого массива 
	чисел создайте другой вектор целых чисел, представляющий цифровой сигнал, в котором будут 
	откинуты дробные части чисел. Выведите получившиеся массивы чисел. Посчитайте ошибку, которой 
	обладает цифровой сигнал по сравнению с аналоговым по формуле: Sum(ai-bi)^2. Постарайтесь 
	воспользоваться алгоритмическими функциями, не используя циклы.
	===================================================================================================
	*/

	//const double pi = boost::math::constants::pi<double>();
	double a = 0.0,
		   b = 1.0,
		   c = 1.0,
		   x = 0.0,
		   d = 0.0;
	double y = a + b * std::sin(c * x + d);

	std::vector<double> aSignal(100);
	std::vector<int> dSignal(100);

	std::generate(aSignal.begin(), aSignal.end(), [a, b, c, &x, d]()
		{
			x += M_PI/6;
			return a + b * std::sin(c * x + d);
		}
	);

	copy(aSignal.begin(), aSignal.end(), std::ostream_iterator<double>(std::cout, " ")); //output

	std::transform(aSignal.begin(), aSignal.end(), dSignal.begin(), [&](const double aSignal)
		{
			return static_cast<int>(trunc(aSignal));
		}
	);

	std::cout << "\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n\n";

	copy(dSignal.begin(), dSignal.end(), std::ostream_iterator<int>(std::cout, " ")); //output

	double error = std::inner_product(aSignal.begin(), aSignal.end(), dSignal.begin(), 0.0, std::plus<>(), [](const double a, const int d) -> double
		{
			return (a - d) * (a - d);
		}
	);
	std::cout << "\nerror: " << error;
	std::cout << "\n__________________________________________________________\n\n";
#pragma endregion

	return 0;
}
