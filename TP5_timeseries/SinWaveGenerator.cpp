//
// Created by Istiak on 10/01/2024.
//

#include "SinWaveGenerator.h"
#include <cmath>

using namespace std;

SinWaveGenerator::SinWaveGenerator() {
    amplitude = 1;
    frequency = 1;
    phase = 0;
}

SinWaveGenerator::SinWaveGenerator(int seed) : TimeSeriesGenerator(seed) {
    amplitude = 1;
    frequency = 1;
    phase = 0;
}

vector<double> SinWaveGenerator::generateTimeSeries(int length) {
    vector<double> timeSeries;
    for (int i = 0; i < length; i++) {
        frequency = i;
        timeSeries.push_back(amplitude * sin(M_PI * frequency + phase));
    }
    return timeSeries;
}
