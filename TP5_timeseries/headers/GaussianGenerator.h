//
// Created by Istiak on 09/01/2024.
//

#ifndef TP5_TIMESERIES_GAUSSIANGENERATOR_H
#define TP5_TIMESERIES_GAUSSIANGENERATOR_H
#include <iostream>
#include <vector>
#include "TimeSeriesGenerator.h"

class GaussianGenerator : public TimeSeriesGenerator {
    public:
    GaussianGenerator();
    GaussianGenerator(int seed);
    vector<double> generateTimeSeries(int);
    void boxMuller(double& u1, double& u2);
    int mean;
    int variance;
};


#endif //TP5_TIMESERIES_GAUSSIANGENERATOR_H
