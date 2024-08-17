#include "Log.hpp"

Log::Log() {}

Log::~Log() {}

void Log::init(string key) {
    if (logs.find(key) == logs.end()) {
        logs[key] = { system_clock::now(), system_clock::now(), duration<double>::zero(), 0, 0, 0 };
    }
}

void Log::end(string key) {
    auto now = system_clock::now();
    if (logs.find(key) != logs.end()) {
        logs[key].endTime = now;
    }
}

void Log::incrementInstance(string key, int value) {
    auto start = system_clock::now();
    auto log = logs.find(key);
    if (log != logs.end()) {
        log->second.instacesCount += value;
        auto end = system_clock::now();
        log->second.timeSpentLogger += duration_cast<duration<double>>(end - start);
    }
}

void Log::incrementAttribuition(string key, int value) {
    auto start = system_clock::now();
    auto log = logs.find(key);
    if (log != logs.end()) {
        log->second.attribuitionCount += value;
        auto end = system_clock::now();
        log->second.timeSpentLogger += duration_cast<duration<double>>(end - start);
    }
}

void Log::incrementCompare(string key, int value) {
    auto start = system_clock::now();
    auto log = logs.find(key);
    if (log != logs.end()) {
        log->second.compareCount += value;
        auto end = system_clock::now();
        log->second.timeSpentLogger += duration_cast<duration<double>>(end - start);
    }
}

void Log::printLog(string key) {
    auto log = logs.find(key);
    if (log != logs.end()) {
        auto totalTime = duration_cast<milliseconds>((log->second.endTime - log->second.startTime) - log->second.timeSpentLogger).count();
        ofstream file("LogFile_PAA.txt", ios::app);

        if (file.is_open()) {
            file << "--------------------------------------------" << endl;
            file << "Log Key: " << key << endl;
            file << "Start Time: " << formatTime(log->second.startTime) << endl;
            file << "End Time: " << formatTime(log->second.endTime) << endl;
            file << "Operation Time: " << totalTime << " ms" << endl;
            file << "        ----------------------------        " << endl;
            file << "Instances Op: " << log->second.instacesCount << endl;
            file << "Attribuition Op: " << log->second.attribuitionCount << endl;
            file << "Compare Op: " << log->second.compareCount << endl;
            file << "Total Operations: " << (log->second.instacesCount + log->second.attribuitionCount + log->second.compareCount) << endl;
            file << "--------------------------------------------" << endl;
            file.close();
        }
    }
}

string Log::formatTime(const system_clock::time_point& tp) {
    std::time_t time = system_clock::to_time_t(tp);
    std::tm tm = *std::localtime(&time);

    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%d/%m/%Y %H:%M:%S", &tm);

    return string(buffer);
}
