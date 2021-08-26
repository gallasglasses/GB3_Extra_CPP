#include "Array.h"

template<typename T>
Array<T>::Array(size_t arrN) : n(arrN)
{
	arr = new T[n];
}

template<typename T>
Array<T>& Array<T>::operator[] (const size_t& arrN)
{
	if (arrN > 0 && arrN < n)
	{
		return arr[arrN];
	}
	return arr[0];
}

template<typename T>
typename Array<T>::MyIterator begin()
{
	return arr;
}

template<typename T>
typename Array<T>::MyIterator end()
{
	return arr+n;
}