#include "MyIterator.h"

template<typename T>
MyIterator<T>::MyIterator(T* p) :
    p(p)
{

}

template<typename T>
MyIterator<T>::MyIterator(const MyIterator& it) :
    p(it.p)
{

}

template<typename T>
bool MyIterator<T>::operator!=(MyIterator const& other) const
{
    return p != other.p;
}

template<typename T>
bool MyIterator<T>::operator==(MyIterator const& other) const
{
    return p == other.p;
}

template<typename T>
typename MyIterator<T>::reference MyIterator<T>::operator*() const
{
    return *p;
}

template<typename T>
MyIterator<T>& MyIterator<T>::operator++()
{
    ++p;
    return *this;
}