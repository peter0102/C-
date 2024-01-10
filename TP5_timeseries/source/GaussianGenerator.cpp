//
// Created by Istiak on 09/01/2024.
//

#include "../headers/GaussianGenerator.h"
#include <iostream>
#include <vector>
#include <cmath>


using namespace std;

GaussianGenerator::GaussianGenerator() {
    mean = 0;
    variance = 1;
}

GaussianGenerator::GaussianGenerator(int seed) {
    mean = 0;
    variance = 1;
    srand(seed);
}

vector<double> GaussianGenerator::generateTimeSeries(int n) {
    vector<double> timeSeries;
    for (int i = 0; i < n; i++) {
        double u1 = (double) rand() / RAND_MAX;
        double u2 = (double) rand() / RAND_MAX;
        boxMuller(u1, u2);
        timeSeries.push_back(u1);
    }
    return timeSeries;
}

void GaussianGenerator::boxMuller(double& u1, double& u2) {
    double r = sqrt(-2 * log(u1));
    double theta = 2 * M_PI * u2;
    u1 = r * cos(theta);
    u2 = r * sin(theta);
}


