#ifndef TIMESTORER_H
#define TIMESTORER_H

#include <string>
#include <vector>
#include <chrono>
using namespace std;

// holds the timing result for one sort run
struct SortResult
{
    string algorithmName;
    double elapsedMs;
    int    arraySize;
};

class TimeStorer
{
    private:
    // the point when the timer was started
    chrono::high_resolution_clock::time_point startTime;
//the results of all the sorts
    vector<SortResult> results;
    
public:

    void startTimer();

    // stopping the timeer and reutnign the time
    double stopTimer();

    // ssaving the result in a vector array
    void saveResult(string name, double ms, int size);

    // printing all the results
    void printAll() const;


};

#endif
