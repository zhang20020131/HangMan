#include "Time.h"

TimePoint Time::time = Time::GetTime();
TimePoint Time::previousTimeStamp = Time::GetTime();