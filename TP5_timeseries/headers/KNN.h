//
// Created by Istiak on 10/01/2024.
//

#ifndef TP5_TIMESERIES_KNN_H
#define TP5_TIMESERIES_KNN_H

#include "TimeSeriesDataset.h"
#include <iostream>

using namespace std;

class KNN {
public:
    int k;
    string similarity_measure;
    KNN(int k,const string& similarity_measure);
    double euclidean_distance(const vector<double> &a, const vector<double> &b);
    double dtw(const vector<double> &a, const vector<double> &b);
    double evaluate(TimeSeriesDataset trainData, TimeSeriesDataset testData, vector<int> ground_truth);


};


#endif //TP5_TIMESERIES_KNN_H
