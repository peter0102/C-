#import "../headers/TimeSeriesGenerator.h"
#import <vector>
#import <iostream>

using namespace std;

TimeSeriesGenerator::TimeSeriesGenerator() {
    this->seed = 0;
}

TimeSeriesGenerator::TimeSeriesGenerator(int seed) {
    this->seed = seed;
}

void TimeSeriesGenerator::printTimeSeries(const vector<double> &timeSeries) {
    for (int i = 0; i < timeSeries.size(); i++) {
        cout << timeSeries[i] << endl;
    }
}