
#include <iostream>
#include <vector>
#include <list>
#include "Matrix.h"
#include "Array.h"
#include "MyIterator.h"

int main()
{
#pragma region EX1

    std::cout << "This is 1 exercise\n\n";
    /*
    =======================================================================================================================================
    1. Написать функцию, добавляющую в конец списка вещественных чисел элемент, 
    значение которого равно среднему арифметическому всех его элементов.
    =======================================================================================================================================
    */

    std::list<double> l{ 12, 56.7, 0, 1243, -235.43, 5, 3.14 };

    double num = 0;
    for (std::list<double>::iterator it = l.begin(); it != l.end(); it++)
    {
        num += *it;
    }
    for (std::list<double>::iterator it = l.begin(); it != l.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n";
    num = num / l.size();
    l.push_back(num);
    for (std::list<double>::iterator it = l.begin(); it != l.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    std::cout << "__________________________________________________________\n";
#pragma endregion

#pragma region EX2

    std::cout << "This is 2 exercise\n\n";
    /*
    =======================================================================================================================================
    2. Создать класс, представляющий матрицу. Реализовать в нем метод, вычисляющий определитель матрицы.
    =======================================================================================================================================
    */

    Matrix matrix1(3);
    std::vector<double> m1 = {4, 1, 2, 
                             10, 7, 9, 
                              5, 2, 0};
    matrix1.setMatrix(matrix1.det.ptrM, m1);
    std::cout << "Determinant is " << matrix1.getDeterminant(matrix1.det.ptrM, 3) << "\n";

    Matrix matrix2(4);
    std::vector<double> m2 = { 13, 7, 1, 3,
                                5, 8, 21, 6, 
                                1, 2, 0, 1,
                                4, 15, 6, 3};
    matrix2.setMatrix(matrix2.det.ptrM, m2);
    std::cout << "Determinant is " << matrix2.getDeterminant(matrix2.det.ptrM, 4) << "\n";

    std::cout << "__________________________________________________________\n";
#pragma endregion

#pragma region EX3

    std::cout << "This is 3 exercise\n\n";
    /*
    =======================================================================================================================================
    3. Реализовать собственный класс итератора, с помощью которого можно будет проитерироваться по диапазону целых чисел в цикле for-range-based.
    =======================================================================================================================================
    */

    Array<int> arr(10);
    int x = 0;
    for (auto it = arr.begin(); it != arr.end(); it++)
    {
        it = x++;
    }
    for (auto it = arr.begin(); it != arr.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    std::cout << "__________________________________________________________\n";
#pragma endregion
}