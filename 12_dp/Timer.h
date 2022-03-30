#ifndef TIMER_H
#define TIMER_H

#include <iostream>
#include <chrono>

#define TIME_FUNCTION(name) Timer timer##__LINE__(name)
#define TIME_UTIL() TIME_FUNCTION(__PRETTY_FUNCTION__)

class Timer 
{
public:
    Timer(const char* name) : name_(name)
    {
        start_ = std::chrono::high_resolution_clock::now();
    }

    ~Timer()
    {
        end_ = std::chrono::high_resolution_clock::now();
        duration_ = end_ - start_;
        std::cout << name_ << " # run time: " << duration_.count() << "ms " << std::endl;
    }

private:
    const char* name_;
    std::chrono::time_point<std::chrono::high_resolution_clock> start_;
    std::chrono::time_point<std::chrono::high_resolution_clock> end_;
    std::chrono::duration<double, std::milli> duration_;
};

#endif /* TIMER_H */
