//
// Created by Istiak on 10/01/2024.
//

#include "../headers/KNN.h"
#include <cmath>
#include <algorithm>

KNN::KNN(int k, const string& similarity_measure) {
    this->k = k;
    this->similarity_measure = similarity_measure;
}

double KNN::euclidean_distance (const vector <double > &a , const vector <double > &b ) {
    double sum = 0;
    for (int i = 0; i < a.size(); i++) {
        sum += pow(a[i] - b[i], 2);
    }
    return sqrt(sum);
}

double KNN::dtw (const vector <double > &a , const vector <double > &b ) {
    vector<vector<double>> dtw(a.size(), vector<double>(b.size(), 0));
    dtw[0][0] = 0;
    for (int i = 1; i < a.size(); i++) {
        dtw[i][0] = INFINITY;
    }
    for (int i = 1; i < b.size(); i++) {
        dtw[0][i] = INFINITY;
    }
    for (int i = 1; i < a.size(); i++) {
        for (int j = 1; j < b.size(); j++) {
            double d = pow(a[i] - b[j], 2);
            dtw[i][j] = d + min(dtw[i - 1][j], min(dtw[i][j - 1], dtw[i - 1][j - 1]));
        }
    }
}

double KNN::evaluate(TimeSeriesDataset trainData, TimeSeriesDataset testData, vector<int> ground_truth) {
    double accuracy = 0;
    vector<double> testSample = testData.data;
    vector<double> trainSample = trainData.data;
    vector<int> trainLabels = trainData.labels;
    vector<int> testLabels = testData.labels;
    int maxLength = max(trainData.maxLength, testData.maxLength);
    int numberOfSamples = testData.numberOfSamples;

}