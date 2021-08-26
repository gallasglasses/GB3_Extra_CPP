#pragma once
#include "Array.h"

template<typename T>
class MyIterator : public std::iterator<std::input_iterator_tag, T>
{
private:
    MyIterator(T* p);
public:
    MyIterator(const MyIterator& it);

    bool operator!=(MyIterator const& other) const;
    bool operator==(MyIterator const& other) const;
    typename MyIterator::reference operator*() const;
    MyIterator& operator++();
private:
    T* p;
};

