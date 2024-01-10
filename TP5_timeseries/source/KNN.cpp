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
    return dtw[a.size() - 1][b.size() - 1];
}

double KNN::evaluate(TimeSeriesDataset trainData, TimeSeriesDataset testData, vector<int> ground_truth) {
    double accuracy = 0;
    vector<double> trainSamples = trainData.data;
    vector<double> testSamples = testData.data;
    vector<int> trainLabels = trainData.labels;
    vector<int> testLabels = testData.labels;
    vector<vector<double>> trainSamples2D = trainData.data2D;

    int maxLength = max(trainData.maxLength, testData.maxLength);
    int numberOfSamples = testData.numberOfSamples;

    vector<double> distances = {};
    distances.reserve(trainSamples2D.size());
    for (int i=0; i<trainSamples2D.size(); i++) {
        if (similarity_measure == "euclidean") {
            distances.push_back(euclidean_distance(testSamples, trainSamples2D[i]));
        } else if (similarity_measure == "dtw") {
            distances.push_back(dtw(testSamples, trainSamples2D[i]));
        }
        sort(distances.begin(), distances.end());
        vector<double> neighbors = {};
        neighbors.reserve(k);
        for (int j = 0; j < k; j++) {
            neighbors.push_back(distances[j]);
        }
        vector<int> neighborLabels = {};
        for (int j = 0; j < k; j++) {
            neighborLabels.push_back(trainLabels[j]);
        }
        int maxCount = 0;
        int maxLabel = 0;
        for (int j = 0; j < neighborLabels.size(); j++) {
            int count = 0;
            if (neighborLabels[j] == ground_truth[i]) {
                count++;
            }
            if (count > maxCount) {
                maxCount = count;
                maxLabel = neighborLabels[j];
            }
        }
        if (maxLabel == ground_truth[i]) {
            accuracy++;
        }
    }
    return accuracy / numberOfSamples;
}