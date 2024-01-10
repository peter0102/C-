//
// Created by Istiak on 10/01/2024.
//

#ifndef TP5_TIMESERIES_TIMESERIESDATASET_H
#define TP5_TIMESERIES_TIMESERIESDATASET_H

#include "TimeSeriesGenerator.h"

class TimeSeriesDataset {
public:
    TimeSeriesDataset();
    TimeSeriesDataset(bool needNormalize, bool train);
    bool znormalize;
    bool isTrain;
    vector<double> data;
    vector<int> labels;
    int maxLength;
    int numberOfSamples;
    void znormalization(vector<double> &timeSeries);
    void addTimeSeries(vector<double> timeSeries, int label);
};


#endif //TP5_TIMESERIES_TIMESERIESDATASET_H
