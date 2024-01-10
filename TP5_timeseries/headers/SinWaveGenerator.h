//
// Created by Istiak on 10/01/2024.
//

#ifndef TP5_TIMESERIES_SINWAVEGENERATOR_H
#define TP5_TIMESERIES_SINWAVEGENERATOR_H

#include "TimeSeriesGenerator.h"

class SinWaveGenerator : public TimeSeriesGenerator {
public:
    SinWaveGenerator();
    SinWaveGenerator(int seed);
    vector<double> generateTimeSeries(int);
    double amplitude;
    double frequency;
    double phase;
};


#endif //TP5_TIMESERIES_SINWAVEGENERATOR_H
