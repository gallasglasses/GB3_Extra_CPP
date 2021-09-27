// HW6.cpp

#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <mutex>
#include <iomanip> 
#include <algorithm>
#include "pcout.h"

std::mutex PCout::mPrint{};
std::mutex mHouse;

void FunctionForPCout1(size_t i)
{
	PCout{} << "It's " << i << std::endl;
}

void FunctionForPCout2()
{
	PCout{} << "Hello " << std::endl;
}

void FindPrimeNumber(long long checkedNumber, long long& counter, long long& thatNumber)
{
	while (counter < checkedNumber)
	{
		bool isNumberPrime = true;
		thatNumber++;
		if (thatNumber == 1)
		{
			isNumberPrime = false;
		}
		for (unsigned divider = 2; (static_cast<unsigned long>(divider * divider) <= static_cast<unsigned long>(thatNumber)); divider++)
		{
			if (thatNumber % divider == 0)
			{
				isNumberPrime = false;
			}
		}
		if (isNumberPrime)
		{
			counter++;
			//std::cout << counter << " counter |" << thatNumber << " thatNumber!\n";
		}
	}
}

long long PrimeNumberCounter(long long checkedNumber)
{
	long long thatNumber = 0;
	long long counter = 0;

	std::thread th3( FindPrimeNumber, checkedNumber, std::ref(counter), std::ref(thatNumber));
	while (counter < checkedNumber)
	{
		std::cout << counter << " \n";
		std::this_thread::sleep_for(std::chrono::milliseconds(0));
	}
	th3.join();
	return thatNumber;
}

void MasterTrickster(std::vector<size_t>& item)
{
	while (!item.empty())
	{
		mHouse.lock();
		size_t NewItem = rand() % 100 + 1;
		item.push_back(NewItem);
		std::cout << "\nThe master bought a new item for $ " << NewItem << "\n";
		std::cout << "++++++++++++++++++++++++\n";
		std::cout << "+   Master's cabinet   +\n";
		std::cout << "++++++++++++++++++++++++\n";
		size_t cout = 1;
		for (std::vector<size_t>::iterator it = item.begin(); it != item.end(); ++it, cout++)
		{

			std::cout << "+ " << std::setw(2) << cout << ". " << std::setw(16)<< *it << " +\n";
		}
		std::cout << "++++++++++++++++++++++++\n";
		mHouse.unlock();
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
}

void ThiefGarrett(std::vector<size_t>& item)
{
	while (!item.empty())
	{
		mHouse.lock();
		std::vector<size_t> ThiefTreasure;
		std::vector<size_t>::iterator ExpensiveItem = std::max_element(item.begin(), item.end());
		ThiefTreasure.push_back(*ExpensiveItem);
		std::cout << "\nThe thief stolen a new item for $ " << *ExpensiveItem << "\n";
		item.erase(ExpensiveItem);
		std::cout << "########################\n";
		std::cout << "#   Thief's treasure   #\n";
		std::cout << "########################\n";
		size_t cout = 1;
		for (std::vector<size_t>::iterator it = ThiefTreasure.begin(); it != ThiefTreasure.end(); ++it, cout++)
		{

			std::cout << "# " << std::setw(2) << cout << ". " << std::setw(16) << *it << " #\n";
		}
		std::cout << "########################\n";
		mHouse.unlock();
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
}

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

	for (size_t i = 0; i < 5; i++)
	{
		std::thread th1(FunctionForPCout1, i);
		th1.join();
		std::thread th2(FunctionForPCout2);
		th2.join();
	}


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

	std::cout << "Enter the number and i find this prime number:	";
	long long checkedNumber;
	std::cin >> checkedNumber;
	std::cout << PrimeNumberCounter(checkedNumber) <<", you are " << checkedNumber << " prime number!!! Congrats!\n";


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

	std::vector<size_t> items = { 29, 49, 99, 69 };
	std::thread Master(MasterTrickster, std::ref(items));
	std::thread Thief(ThiefGarrett, std::ref(items));
	Master.join();
	Thief.join();



	std::cout << "__________________________________________________________\n";

#pragma endregion

	return 0;
}