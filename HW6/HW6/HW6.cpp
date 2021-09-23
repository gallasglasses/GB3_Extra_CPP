﻿// HW6.cpp

#include <iostream>

int main()
{
#pragma region EX1

	std::cout << "This is 1 exercise\n\n";
	/*
	===================================================================================================
	1. Создайте потокобезопасную оболочку для объекта cout. Назовите ее pcout. Необходимо, 
	чтобы несколько потоков могли обращаться к pcout и информация выводилась в консоль. 
	Продемонстрируйте работу pcout.
	===================================================================================================
	*/



	std::cout << "__________________________________________________________\n";

#pragma endregion

#pragma region EX2

	std::cout << "This is 2 exercise\n\n";
	/*
	===================================================================================================
	2.	Реализовать функцию, возвращающую i-ое простое число (например, 
	миллионное простое число равно 15485863). Вычисления реализовать во вторичном потоке.
	В консоли отображать прогресс вычисления. 
	===================================================================================================
	*/



	std::cout << "__________________________________________________________\n";

#pragma endregion

#pragma region EX3

	std::cout << "This is 3 exercise\n\n";
	/*
	===================================================================================================
	3.	Промоделировать следующую ситуацию. Есть два человека (2 потока): хозяин и вор. 
	Хозяин приносит домой вещи. При этом у каждой вещи есть своя ценность. Вор забирает вещи, 
	каждый раз забирает вещь с наибольшей ценностью.
	===================================================================================================
	*/



	std::cout << "__________________________________________________________\n";

#pragma endregion

	return 0;
}