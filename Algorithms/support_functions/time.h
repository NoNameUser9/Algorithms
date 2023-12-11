#pragma once
#include <chrono>

namespace NNU9
{
    class time
    {
        std::chrono::time_point<chrono::system_clock> start_ = std::chrono::system_clock::now();
        std::chrono::time_point<chrono::system_clock> end_ = std::chrono::system_clock::now();
    public:
        void start()
        {
            start_ = std::chrono::system_clock::now();
        }
        void end()
        {
            end_ = std::chrono::system_clock::now();
        }
        auto count()
        {
            return std::chrono::duration<double, std::ratio<1, 1>>(end_ - start_);
        }
    };
}
