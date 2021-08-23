// HW2.cpp

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include <iterator>
#include "Timer.h"

template < typename T >
void swap(T *a, T *b);

template < typename T >
void sortPointers(std::vector<T*>& v);

template < typename T >
void printVector(const std::vector<T*>& v);

//template < typename T >
//void deleteVector(std::vector<T*>& v);

const std::string strVowels("AaEeIiOoUuYy");
//const std::string strVowels("ја≈еЄ»иќо”уыЁэёюя€");
Timer timer;

void getCountVowels1();
void getCountVowels2();
void getCountVowels3();
void getCountVowels4();

int main()
{
#pragma region EX1

    std::cout << "This is 1 exercise\n\n";
    /*
    =======================================================================================================================================
    1. –еализуйте шаблонную функцию Swap, котора€ принимает два указател€ и 
    обменивает местами значени€, на которые указывают эти указатели.
    =======================================================================================================================================
    */

    int a = 100;
    int b = 900;
    std::cout << "a: " << a << "\tb: " << b << "\n";
    swap(&a, &b);
    std::cout << "a: " << a << "\tb: " << b << "\n";

    std::cout << "__________________________________________________________\n";
#pragma endregion

#pragma region EX2

    std::cout << "This is 2 exercise\n\n";
    /*
    =======================================================================================================================================
    2. –еализуйте шаблонную функцию SortPointers, котора€ принимает вектор указателей и 
    сортирует указатели по значени€м, на которые они указывают.
    =======================================================================================================================================
    */
    
    std::vector<int*> v;
    v.push_back(new int(65));
    v.push_back(new int(13));
    v.push_back(new int(2));
    v.push_back(new int(10));
    v.push_back(new int(3));
    v.push_back(new int(24));
    v.push_back(new int(15));
    v.push_back(new int(0));

    printVector(v);
    sortPointers(v);
    printVector(v);

    std::cout << "__________________________________________________________\n";
#pragma endregion

#pragma region EX3

    std::cout << "This is 3 exercise\n\n";
    /*
    =======================================================================================================================================
    3. ѕодсчитайте количество гласных букв в книге У¬ойна и мирФ. ƒл€ подсчета используйте 4 способа:
    *      count_if и find
    *      count_if и цикл for
    *      цикл for и find
    *      2 цикла for
    «амерьте врем€ каждого способа подсчета и сделайте выводы.
    =======================================================================================================================================
    */

    getCountVowels1();
    getCountVowels2();
    getCountVowels3();
    getCountVowels4();

#pragma endregion
    
    return 0;
}

template < typename T >
void swap(T *a, T *b)
{
    T swap_p = *a;
    *a = *b;
    *b = swap_p;
}

template < typename T >
void sortPointers(std::vector<T*>& v)
{
    std::sort(v.begin(), v.end(),
        [](T *a, T *b)
        {
            return *a < *b;
        }
    );
}

template < typename T >
void printVector(const std::vector<T*>& v)
{
    std::cout << "vec : ";
    for (typename std::vector<T*>::const_iterator it = v.begin(); it != v.end(); it++)
    {
        std::cout << *(*it) << " ";
    }
    /*for (size_t i = 0; i < v.size(); i++)
    {
        std::cout << *v[i] << " ";
    }*/
    std::cout << "\n";
}

template < typename T >
void deleteVector(std::vector<T*>& v)
{
    for (typename std::vector<T*>::const_iterator it = v.begin(); it != v.end(); ++it)
    {
        delete* it;
        *it = nullptr;
    }
    v.clear();
}

void getCountVowels1() //count_if и find
{
    //std::ifstream file("pride_and_prejudice.txt");
    std::ifstream file("war_and_peace.txt");

    unsigned int countVowels = 0,
        count = 0;

    if (file.is_open())
    {
        timer.start("count_if & find");
        count = std::count_if(std::istream_iterator<char>(file), std::istream_iterator<char>(),
            [&](char a)
            {
                return strVowels.find(a) != std::string::npos;
            }
        );
        countVowels = countVowels + count;
        std::cout << "Vowels : " << countVowels << "\n";
        timer.print();
        std::cout << "\n";
        file.close();
    }
    else
    {
        std::cout << "Error! File not found!\n";
    }
}

void getCountVowels2() //count_if и цикл for
{
    //std::ifstream file("pride_and_prejudice.txt");
    std::ifstream file("war_and_peace.txt");

    unsigned int countVowels = 0,
        count = 0;

    if (file.is_open())
    {
        timer.start("count_if & loop for");
        count = std::count_if(std::istream_iterator<char>(file), std::istream_iterator<char>(),
            [&](char a)
            {
                for (size_t i = 0; i < strVowels.size(); i++)
                {
                    if (a == strVowels[i])
                    {
                        return true;
                    }
                }
                return false;
            }
        );
        countVowels = countVowels + count;
        std::cout << "Vowels : " << countVowels << "\n";
        timer.print();
        std::cout << "\n";
        file.close();
    }
    else
    {
        std::cout << "Error! File not found!\n";
    }
}

void getCountVowels3() //цикл for и find
{
    //std::ifstream file("pride_and_prejudice.txt");
    std::ifstream file("war_and_peace.txt");
    unsigned int countVowels = 0;
    if (file.is_open())
    {
        timer.start("loop for & find");
        for (char ch; file >> ch; )
        {
            auto count = strVowels.find(ch);
            if (count != std::string::npos)
            {
                countVowels++;
            }
        }
        std::cout << "Vowels : " << countVowels << "\n";
        timer.print();
        std::cout << "\n";
        file.close();
    }
    else
    {
        std::cout << "Error! File not found!\n";
    }
}

void getCountVowels4() //2 цикла for
{
    //std::ifstream file("pride_and_prejudice.txt");
    std::ifstream file("war_and_peace.txt");
    unsigned int countVowels = 0;
    if (file.is_open())
    {
        timer.start("    2 loops for"); 
        for (char ch; file >> ch; )
        {
            for (size_t i = 0; i < strVowels.size(); i++)
            {
                if (ch == strVowels[i])
                {
                    countVowels++;
                }
            }
        }
        std::cout << "Vowels : " << countVowels << "\n";
        timer.print();
        std::cout << "\n";
        file.close();
    }
    else
    {
        std::cout << "Error! File not found!\n";
    }
}