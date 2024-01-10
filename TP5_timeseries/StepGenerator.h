//
// Created by Istiak on 09/01/2024.
//

#ifndef TP5_TIMESERIES_STEPGENERATOR_H
#define TP5_TIMESERIES_STEPGENERATOR_H

#include "TimeSeriesGenerator.h"

using namespace std;


class StepGenerator : public TimeSeriesGenerator {
public:
    StepGenerator();
    StepGenerator(int seed);
    vector<double> generateTimeSeries(int);

};


#endif //TP5_TIMESERIES_STEPGENERATOR_H
