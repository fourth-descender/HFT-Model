#ifndef ARRIVAL_H
#define ARRIVAL_H

#include <random>
#include <cmath>

class PoissonArrival
{
    public:
        PoissonArrival(
            double A,       // likelihood of arrival.
            double k        // intensity of arrival.
        );
        bool arrives(
            double delta,   // gap between stock price and bid/ask price.
            double dt       // time step.
        );
    private:
        double k;
        double A;
        std::random_device rd;
        std::mt19937 gen;
        std::uniform_real_distribution<int> d;
};

#endif