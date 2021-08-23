#include "Timer.h"

double Timer::elapsed() const
{
    return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
}

Timer::Timer() : m_beg(clock_t::now())
{

}

Timer::Timer(std::string name) : m_name(name), m_beg(clock_t::now())
{

}

void Timer::start(std::string name)
{
    m_name = name;
    m_beg = clock_t::now();
}
void Timer::print() const
{
    std::cout << m_name << ":\t" << elapsed() * 1000 << " ms" << '\n';
}
