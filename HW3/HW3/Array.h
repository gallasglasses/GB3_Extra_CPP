#pragma once

#include <list>
#include <iostream>
#include "MyIterator.h"

template<typename T>
class Array
{
private:
	T* arr;
	size_t n;
public:

	template<typename T>
	class MyIterator;

	Array(size_t arrN = 1);

	Array& operator[] (const size_t& arrN);
	MyIterator begin();
	MyIterator end();

	friend std::ostream& operator<<(std::ostream& out, const Array<T>& arrN);
};

template<typename T>
std::ostream& operator<<(std::ostream& out, const Array<T>& arrN)
{
	out << Array<T>::arr[arrN];
	return out;
}