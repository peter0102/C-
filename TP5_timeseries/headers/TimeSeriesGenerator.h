#ifndef TP5_TIMESERIES_TIMESERIESGENERATOR_H
#define TP5_TIMESERIES_TIMESERIESGENERATOR_H

#include <vector>

using namespace std;

class TimeSeriesGenerator {
public:
    int seed;
    TimeSeriesGenerator();
    TimeSeriesGenerator(int seed);
    virtual vector<double> generateTimeSeries(int) = 0;
    void printTimeSeries(const vector<double>&);
};


#endif //TP5_TIMESERIES_TIMESERIESGENERATOR_H
