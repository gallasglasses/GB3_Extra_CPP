#pragma once

#include <iostream>
#include <sstream>
#include <mutex>

class PCout : public std::ostringstream
{
public:
    PCout() = default;

    ~PCout()
    {
        std::lock_guard<std::mutex> guard(mPrint);
        std::cout << this->str();
    }

private:
    static std::mutex mPrint;
};