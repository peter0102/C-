#include <iostream>
#include <vector>
#include 'TimeSeriesGenerator.h'

class GaussianGenerator {
    public TimeSeriesGenerator {
        public:
            GaussianGenerator();
            GaussianGenerator(int seed);
            vector<double> generateTimeSeries(int);

            int mean;
            int std;
    }
};


#endif
