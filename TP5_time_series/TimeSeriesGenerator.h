#ifndef TIME_SERIES_GENERATOR_H
#define TIME_SERIES_GENERATOR_H
#include <vector>

using namespace std;

class TimeSeriesGenerator {
public:
    int seed;
    TimeSeriesGenerator();
    TimeSeriesGenerator(int seed);
    virtual vector<double> generateTimeSeries(int) = 0;
    void printTimeSeries(const vector<double>);
};


#endif
