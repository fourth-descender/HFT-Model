#ifndef ARRIVAL_H
#define ARRIVAL_H

#include <random>
#include <cmath>
#include <Model.h>

class PoissonArrival
{
    public:
        PoissonArrival(parameters& p);

        bool arrives(
            double delta,   // gap between stock price and bid/ask price.
            double dt       // time step.
        );

    private:
        double                      k;  // intensity of arrival.
        double                      A;  // likelihood of arrival.
        std::random_device          rd;
        std::mt19937                gen;
        std::uniform_real_distribution<double> d;
};

#endif