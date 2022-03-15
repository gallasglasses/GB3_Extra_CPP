#pragma once

#include <iostream>

template <typename T>
class MyIterator;

template<typename T>
class Array
{
private:
	T* arr;
	size_t n;
public:

	typedef MyIterator<T> iterator;

	Array();
	Array(size_t arrN = 1);

	size_t size() const;

	T& operator[] (const size_t arrN) const;
	iterator begin();
	iterator end();

	friend std::ostream& operator<<(std::ostream& out, const Array<T>& arrN);
};

template<typename T>
inline std::ostream& operator<<(std::ostream& out, const Array<T>& arrN)
{
	out << Array<T>::arr[arrN];
	return out;
}

template<typename T>
inline Array<T>::Array()
{
	n = 0;
	arr = nullptr;
}

template<typename T>
inline Array<T>::Array(size_t arrN) 
	: n(arrN)
{
	arr = new T[n];
}

template<typename T>
inline size_t Array<T>::size() const
{
	return n;
}

template<typename T>
inline T& Array<T>::operator[] (const size_t arrN) const
{
	return arr[arrN];
}

template<typename T>
inline typename Array<T>::iterator Array<T>::begin()
{
	return arr;
}

template<typename T>
inline typename Array<T>::iterator Array<T>::end()
{
	return arr + n;
}