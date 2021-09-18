// HW5.cpp 

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <sstream>
#include <map>

#include "UniqueWords.h"

const std::string strPunct(".!?");

int main()
{
#pragma region EX1

	std::cout << "This is 1 exercise\n\n";
	/*
	===================================================================================================
	1.	Создать шаблонную функцию, которая принимает итераторы на начало и конец последовательности
	слов, и выводящую в консоль список уникальных слов (если слово повторяется больше 1 раза, то
	вывести его надо один раз). Продемонстрировать работу функции, передав итераторы различных типов.
	===================================================================================================
	*/
	std::vector<std::string> v1 = { "Hello", "Hi", "Hola", "Privet", "Namaste", "Sveiki", "Hello", "Guten Tag", "Ola", "Salut", "Zdravo", "Sveiki", "Hola" };
	UniqueWords(v1.begin(), v1.end());
	print(v1);

	std::list<std::string> v2 = { "Goodbye", "Bye", "Chau", "Adios", "Bye", "Auf Wiedersehen", "Arrivederci", "Chau", "Adeus", "Chau", "Adios" };
	UniqueWords(v2.begin(), v2.end());
	print(v2);

#pragma endregion

#pragma region EX2

	std::cout << "This is 2 exercise\n\n";
	/*
	===================================================================================================
	2.	Используя ассоциативный контейнер, напишите программу, которая будет считывать данные введенные
	пользователем из стандартного потока ввода и разбивать их на предложения. Далее программа должна
	вывести пользователю все предложения, отсортировав их по длине.
	===================================================================================================
	*/

	std::string input = "",
				line = "";

	std::map<int,std::string> mapSentenses;

	std::getline(std::cin, input);

	size_t first = 0;
	size_t second = input.find_first_of("?.!", first);
	while (second != std::string::npos)
	{
		line = input.substr(first, second + 1 - first);
		first = input.find_first_not_of(" \t\n", second + 1);
		second = input.find_first_of(".!?", first);
		mapSentenses.insert(std::make_pair(line.size(), line));
	}
	
	std::for_each(mapSentenses.begin(), mapSentenses.end(),
		[](std::pair<int, std::string> item) {
			std::cout << item.second << "\n";
		});

#pragma endregion
	return 0;
}
