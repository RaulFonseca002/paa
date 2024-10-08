#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <map>
#include <string>
#include <chrono>
#include <fstream>
#include <ctime>

using namespace std;
using namespace std::chrono;

struct LogStruct {
    time_point<system_clock> startTime;
    time_point<system_clock> endTime;
    duration<double> timeSpentLogger;
    int instacesCount;
    int attribuitionCount;
    int compareCount;
};

class Log {
public:
    static Log& getInstance() {
        static Log instance;
        return instance;
    }

    Log();
    ~Log();

    void init(string key);
    void end(string key);
    void incrementInstance(string key, int value);
    void incrementAttribuition(string key, int value);
    void incrementCompare(string key, int value);
    void printLog(string key);

private:

    string formatTime(const system_clock::time_point& tp);

    map<string, LogStruct> logs;

    Log(const Log&) = delete;
    Log& operator=(const Log&) = delete;
};

#endif // LOG_H
