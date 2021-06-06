#pragma once
#include <chrono>
#include <string>


typedef std::chrono::high_resolution_clock Clock;
typedef Clock::time_point TimePoint;

class Time
{
public:
    static TimePoint time;
    static TimePoint previousTimeStamp;

    static void GetFormattedTimeStamp(TimePoint* point = nullptr)
    {
        if (!point)
            point = &GetTime();//指针指向GetTime

        auto now = GetTime();

        auto duration = now - time;

        std::chrono::hours hours =
            std::chrono::duration_cast<std::chrono::hours>(duration);
        std::chrono::minutes minutes =
            std::chrono::duration_cast<std::chrono::minutes>(duration);
        std::chrono::seconds seconds =
            std::chrono::duration_cast<std::chrono::seconds>(duration);


        printf("[%02d:%02d:%02d] ", (int)hours.count(),//显示时间
            (int)minutes.count() % 60,
            (int)seconds.count() % 60);
        
    }

    static TimePoint GetTime()
    {
        return Clock::now();
    }


};

