#ifndef MODEL_H
#define MODEL_H

// Standard library headers
#include <random>
#include <cmath>

// Model namespace
namespace model::formula 
{
    // Random number generation.
    extern std::random_device rd;
    extern std::mt19937 gen;

    // Parameters for the model.
    struct Parameters
    {
        double k;       // intensity
        double sigma;   // volatility
        double gamma;   // risk aversion
        double A;       // likelihood of arrival
        double T = 1;   // time
    };

    // Alias for const reference to Parameters.
    using parameter = const Parameters&;

    // Model functions.
    double getNewStockPrice(parameter p, double price, double t);
    double getNewReservationPrice(parameter p, double price, double quantity, double t);
    double getNewSpread(parameter p, double t);
    double getNewBidPrice(double reservationPrice, double spread);
    double getNewAskPrice(double reservationPrice, double spread);
}

#endif