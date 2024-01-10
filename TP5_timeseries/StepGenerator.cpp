//
// Created by Istiak on 09/01/2024.
//

#include "StepGenerator.h"
#include <iostream>
#include <vector>

using namespace std;

StepGenerator::StepGenerator() {
    this->seed = 0;
}

StepGenerator::StepGenerator(int seed) {
    this->seed = seed;
}

vector<double> StepGenerator::generateTimeSeries(int n) {
    vector<double> timeSeries;
    timeSeries.push_back(0);
    for (int i = 1; i < n; i++) {
        double randomValue = rand() % 100;
        if (randomValue < 50) {
            timeSeries.push_back(timeSeries[i - 1]);
        } else {
            timeSeries.push_back(rand() % 100);
        }
    }
    return timeSeries;
}
