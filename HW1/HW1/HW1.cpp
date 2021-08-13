// HW1.cpp

#include "PhoneBook.h"

int main()
{
    std::ifstream file("PhoneBook.txt"); /*путь к файлу PhoneBook.txt*/ 
    PhoneBook book(file);
    std::cout << book;

    std::cout << "\n\n------SortByPhone-------\n";
    book.SortByPhone();
    std::cout << book;

    std::cout << "\n\n------SortByName--------\n";
    book.SortByName();
    std::cout << book;

    std::cout << "\n\n-----GetPhoneNumber-----\n";
    /*лямбда функция, которая принимает фамилию и выводит номер телефона этого человека, либо строку с ошибкой*/
    auto print_phone_number = [&book](const std::string& surname) {
        std::cout << surname << "\t";
        auto answer = book.GetPhoneNumber(surname);
        if (get<0>(answer).empty())
            std::cout << get<1>(answer);
        else
            std::cout << get<0>(answer);
        std::cout << "\n";
    };

    /*вызовы лямбды*/
    print_phone_number("Ivanov");
    print_phone_number("Petrov");
    print_phone_number("Solovev");

    std::cout << "\n\n----ChangePhoneNumber----\n";
    book.ChangePhoneNumber(Person{ "Kotov", "Vasilii", "Eliseevich" }, PhoneNumber{ 7, 123, "15344458", std::nullopt });
    book.ChangePhoneNumber(Person{ "Mironova", "Margarita", "Vladimirovna" }, PhoneNumber{ 16, 465, "9155448", 13 });
    std::cout << book;

    return 0;
}