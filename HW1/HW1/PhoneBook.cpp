#include "PhoneBook.h"

bool operator<(const Person& p1, const Person& p2)
{
    return std::tie(p1.surname, p1.name, p1.patronymic) <
        std::tie(p2.surname, p2.name, p1.patronymic);
}

bool operator==(const Person& p1, const Person& p2)
{
    return std::tie(p1.surname, p1.name, p1.patronymic) ==
        std::tie(p2.surname, p2.name, p1.patronymic);
}

std::ostream& operator<<(std::ostream& out, const Person& p)
{
    if (p.patronymic.has_value())
    {
        out << std::setw(13) << p.surname 
            << std::setw(11) << p.name
            << std::setw(16) << p.patronymic.value()
            << std::setw(5);
    }
    else
    {
        out << std::setw(13) << p.surname
            << std::setw(11) << p.name
            << std::setw(21);
    }
    return out;
}

bool operator<(const PhoneNumber& pN1, const PhoneNumber& pN2)
{
    return std::tie(pN1.countryCode, pN1.townCode, pN1.pNumber, pN1.addNumber) <
        std::tie(pN2.countryCode, pN2.townCode, pN1.pNumber, pN2.addNumber);
}

std::ostream& operator<<(std::ostream& out, const PhoneNumber& pN)
{
    if (pN.addNumber.has_value())
    {
        out << "+" << pN.countryCode
            << "(" << pN.townCode
            << ")" << pN.pNumber
            << " " << pN.addNumber.value();
    }
    else
    {
        out << "+" << pN.countryCode
            << "(" << pN.townCode
            << ")" << pN.pNumber;
    }
    return out;
}

PhoneBook::PhoneBook(std::ifstream& f)
{
    if (f.is_open())
    {
        std::string line;
        Person person;
        PhoneNumber personNumber;
        while (!f.eof())
        {
            std::getline(f, line);
            std::stringstream in(line);
            in >> person.surname;
            in >> person.name;
            if (in.getline(&line[0], in.tellg(), ' '))
            {
                if (in.peek() != '+')
                {
                    in >> person.patronymic.emplace();
                }
                else
                {
                    person.patronymic.reset();
                }
            }
            in >> personNumber.countryCode;
            if (in.getline(&line[0], in.tellg(), '('))
            {
                in >> personNumber.townCode;
            }
            if (in.getline(&line[0], in.tellg(), ')'))
            {
                in >> personNumber.pNumber;
            }
            if (!in.eof())
            {
                in >> personNumber.addNumber.emplace();
            }
            else
            {
                personNumber.addNumber.reset();
            }
            vPersonPhoneData.push_back(std::make_pair(person, personNumber));
        }
        f.close();
    }
    else
    {
        std::cout << "Error! File not found!\n";
    }
}

void PhoneBook::SortByName()
{
	std::sort(vPersonPhoneData.begin(), vPersonPhoneData.end(), 
        [](const auto& nÑurrent, const auto& nNext) 
		{
		    return nÑurrent.first < nNext.first;
		}
    );
}

void PhoneBook::SortByPhone()
{
    std::sort(vPersonPhoneData.begin(), vPersonPhoneData.end(),
        [](const auto& pÑurrent, const auto& pNext)
        {
            return pÑurrent.second < pNext.second;
        }
    );
}

std::tuple<std::string, PhoneNumber> PhoneBook::GetPhoneNumber(const std::string& surname)
{
    PhoneNumber personNumber;
    size_t count = 0;
    
    std::for_each(vPersonPhoneData.begin(), vPersonPhoneData.end(),
        [&, surname](const auto& vPPD) mutable
        {
            if (vPPD.first.surname == surname) {
                count++;
                personNumber = vPPD.second;
            }
        }
    );

    std::string line;
    if (count == 0)
    {
        line = "Not found!";
    }
    else if (count == 1)
    {
        line.clear();
    }
    else
    {
        line = "Found more than 1";
    }
    return { line, personNumber };
}

void PhoneBook::ChangePhoneNumber(const Person& p, const PhoneNumber& pN)
{
    auto personLine = std::find_if(vPersonPhoneData.begin(), vPersonPhoneData.end(),
        [&, p](const auto& vPPD)
        {
            return vPPD.first == p;
        }
    );
    if (personLine != std::end(vPersonPhoneData))
    {
        personLine->second = pN;
    }
}

std::ostream& operator<<(std::ostream& out, const PhoneBook& pB)
{
    for (size_t i = 0; i < pB.vPersonPhoneData.size(); i++)
    {
        out << pB.vPersonPhoneData[i].first
            << pB.vPersonPhoneData[i].second
            << "\n";
    }
    return out;
}