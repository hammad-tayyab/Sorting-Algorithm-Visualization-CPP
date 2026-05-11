#include "TimeStorer.h"
#include <iostream>

using namespace std;

// defination of startTimer()
void TimeStorer::startTimer()
{
    startTime = chrono::high_resolution_clock::now();
}

// this fucntion calculates the elapsed time
double TimeStorer::stopTimer()
{
    auto endTime = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> elapsed = endTime - startTime;
    return elapsed.count();
}

// storing the result
void TimeStorer::saveResult(string name, double ms, int size)
{
    SortResult result;
    result.algorithmName = name;
    result.elapsedMs     = ms;
    result.arraySize     = size;
    results.push_back(result);
}

// prints a formatted timing table of all runs so far
void TimeStorer::printAll() const
{
    cout << "\n ----------------------------------------" << endl;
    cout << "         Sorting Times This Session       " << endl;
    cout << " ----------------------------------------" << endl;
    cout << "Algorithm\tArray Size\tTime (ms)" << endl;
    cout << " ----------------------------------------" << endl;

    for (const SortResult& r : results)
    {
        cout << r.algorithmName << "\t" << r.arraySize << "\t" << r.elapsedMs << endl;
    }

    cout << " ----------------------------------------" << endl;
}
