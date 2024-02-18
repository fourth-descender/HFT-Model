#ifndef MODEL_H
#define MODEL_H

// standard library headers
#include <random>
#include <cmath>

// model namespace
namespace model::formula 
{
    // random number generation
    extern std::random_device rd;
    extern std::mt19937 gen;

    struct Parameters
    {
        double k;       // intensity
        double sigma;   // volatility
        double gamma;   // risk aversion
        double A;       // likelihood of arrival
        double T;       // terminal time
        double S0;      // initial stock price
        double Q0;      // initial quantity
        double dt;      // time step
        double N;       // number of time steps
    };

    using parameters = const Parameters;

    // Model functions
    double getNewStockPrice      (const parameters& p, double price, double t);
    double getNewReservationPrice(const parameters& p, double price, double quantity, double t);
    double getNewSpread          (const parameters& p, double t);
    double getNewBidPrice        (double reservationPrice, double spread);
    double getNewAskPrice        (double reservationPrice, double spread);
}

#endif