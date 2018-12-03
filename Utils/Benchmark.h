#pragma once

#include <chrono>
#include <iostream>
#include <cstdint>
#include <iomanip>
#include <vector>
#include <algorithm>

//Credit goes to Hopson, https://github.com/Hopson97
template<int N>
class Benchmark {
    using Clock = std::chrono::high_resolution_clock;
    using TimeUnit    = std::chrono::microseconds;
    using UnitType  = std::int64_t;
    public:
        template <typename F, typename... Args>
        Benchmark(const char* name, F function, Args... args)
        :m_name(name) 
        { 
            UnitType total = 0;
            std::array<UnitType, N> times;
            for (int i = 0; i < N; i++) {
                auto begin = Clock::now();
                function(std::forward<Args>(args)...);
                auto end = Clock::now();
                auto time = end - begin;
                auto ms = std::chrono::duration_cast<TimeUnit>(time);
                total += ms.count();
                times[i] = ms.count();
            }
            m_totalTime = total / 1000.0;
            m_avgTime   = (float(total) / float(N)) / 1000.0;
            m_minTime   = (*std::min_element(times.cbegin(), times.cend())) / 1000.0;
            m_maxTime   = (*std::max_element(times.cbegin(), times.cend())) / 1000.0;
        }

        void outputTimes() {
            std::cout << "\n==================================\n";
            std::cout << "Results for benchmark: "  << m_name       << '\n';
            std::cout << "Times benchmarked: "      << N      << "\n\n";
           // std::cout << "  Total time: "           << m_totalTime  << "ms\n";
            std::cout << "Average time: "           << m_avgTime    << "ms\n";
            std::cout << "Minimum time: "           << m_minTime    << "ms\n";
            std::cout << "Maximum time: "           << m_maxTime    << "ms\n";
            std::cout << "       Range: "           << m_maxTime - m_minTime << "ms\n";
            std::cout << "==================================\n";
        }
    private:
        const char* m_name;
        double m_totalTime;
        double m_avgTime;
        double m_minTime;
        double m_maxTime;
};