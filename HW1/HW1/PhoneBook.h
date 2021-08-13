#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <tuple>
#include <optional>
#include <algorithm>

struct Person
{
    std::string                 surname;
    std::string                 name;
    std::optional<std::string>  patronymic;
};

bool operator<(const Person& p1, const Person& p2);

bool operator==(const Person& p1, const Person& p2);

std::ostream& operator<<(std::ostream& out, const Person& p);

struct PhoneNumber
{
    int                         countryÑode;
    int                         townÑode;
    std::string                 pNumber;
    std::optional<int>          addNumber;
};

bool operator<(const PhoneNumber& pN1, const PhoneNumber& pN2);

std::ostream& operator<<(std::ostream& out, const PhoneNumber& pN);

class PhoneBook
{
private:

    std::vector<std::pair<Person, PhoneNumber>> vPersonPhoneData;

public:

    PhoneBook(std::ifstream& f);

    void SortByName();
    void SortByPhone();
    std::tuple<std::string, PhoneNumber> GetPhoneNumber(const std::string& surname);
    void ChangePhoneNumber(const Person& p, const PhoneNumber& pN);

    friend std::ostream& operator<<(std::ostream& out, const PhoneBook& pB);
};

