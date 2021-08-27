#pragma once
#include "Array.h"

template<typename T>
class MyIterator : public std::iterator<std::input_iterator_tag, T>
{
    friend class Array<T>;
private:
    MyIterator(T* p);
public:
    MyIterator(const MyIterator& it);

    bool operator!=(MyIterator const& other) const;
    bool operator==(MyIterator const& other) const;
    T& operator*() const;
    MyIterator& operator++();
private:
    T* p;
};

template<typename T>
inline MyIterator<T>::MyIterator(T* p) 
    : p(p)
{

}

template<typename T>
inline MyIterator<T>::MyIterator(const MyIterator& it)
    : p(it.p)
{

}

template<typename T>
inline bool MyIterator<T>::operator!=(MyIterator const& other) const
{
    return p != other.p;
}

template<typename T>
inline bool MyIterator<T>::operator==(MyIterator const& other) const
{
    return p == other.p;
}

template<typename T>
inline T& MyIterator<T>::operator*() const
{
    return *p;
}

template<typename T>
inline MyIterator<T>& MyIterator<T>::operator++()
{
    ++p;
    return *this;
}