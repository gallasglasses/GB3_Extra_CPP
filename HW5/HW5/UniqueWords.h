#pragma once

#include <vector>
#include <algorithm>
#include <set>

template <typename C>
void print(const C& container)
{
	for (const auto& i : container)
	{
		std::cout << i << " ";
	}
	std::cout << "\n";
}

template <typename T>
void UniqueWords(const T& begin, const T& end)
{
	std::set<std::string> setUniqueWords;
	std::for_each(begin, end, [&](const std::string& word) { setUniqueWords.insert(word); });
	print(setUniqueWords);
}
