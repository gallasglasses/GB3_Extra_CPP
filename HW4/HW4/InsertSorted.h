#pragma once
#include <vector>
#include <algorithm>

template <typename T>
void insert_sorted(std::vector<T>& v, const T& value)
{
	v.insert(std::upper_bound(v.cbegin(), v.cend(), value), value);
}

template <typename C, typename V>
void insert_sorted2(C& container, const V& value)
{
	typename C::iterator it = std::upper_bound(std::begin(container), std::end(container), value);
	*(std::inserter(container, it)) = value;
}