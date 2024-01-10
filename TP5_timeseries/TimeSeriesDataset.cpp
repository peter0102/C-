//
// Created by Istiak on 10/01/2024.
//

#include "TimeSeriesDataset.h"
#include <cmath>

TimeSeriesDataset::TimeSeriesDataset() {
    znormalize = false;
    isTrain = false;
    maxLength = 0;
    numberOfSamples = 0;
}

TimeSeriesDataset::TimeSeriesDataset(bool needNormalize, bool train) {
    znormalize = needNormalize;
    isTrain = train;
    maxLength = 0;
    numberOfSamples = 0;
}

void TimeSeriesDataset::znormalization(vector<double> &timeSeries) {
    double mean = 0;
    double std = 0;
    for (int i = 0; i < timeSeries.size(); i++) {
        mean += timeSeries[i];
    }
    mean /= timeSeries.size();
    for (int i = 0; i < timeSeries.size(); i++) {
        std += pow(timeSeries[i] - mean, 2);
    }
    std /= timeSeries.size();
    std = sqrt(std);

    for (int i = 0; i < timeSeries.size(); i++) {
        timeSeries[i] = (timeSeries[i] - mean) / std;
    }
}

void TimeSeriesDataset::addTimeSeries(TimeSeriesGenerator *generator, int label) {
    vector<double> timeSeries = generator->generateTimeSeries(100);
    if (znormalize) {
        znormalization(timeSeries);
    }
    data.insert(data.end(), timeSeries.begin(), timeSeries.end());
    labels.push_back(label);
    if (timeSeries.size() > maxLength) {
        maxLength = timeSeries.size();
    }
    numberOfSamples++;
}