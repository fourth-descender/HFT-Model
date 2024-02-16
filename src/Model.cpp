#include <Model.h>

namespace model::formula 
{

    std::random_device rd;
    std::mt19937 gen(rd());
    
    double getNewStockPrice(parameter p, double price, double t)
    {
        std::normal_distribution<double> d(0, 1); // sampled for disturbance.
        return price * exp((p.gamma - 0.5 * p.sigma * p.sigma) * (p.T - t) + p.sigma * sqrt(p.T - t) * d(gen));
    }

    double getNewReservationPrice(parameter p, double price, double quantity, double t)
    {
        // equation #29 on paper.
        return price - quantity * p.gamma * std::pow(p.sigma, 2) * (p.T - t);
    }

    double getNewSpread(parameter p, double t)
    {
        // equation #30 on paper.
        return p.gamma * std::pow(p.sigma, 2) * (p.T - t) + (2 / p.gamma) * log(1 + p.gamma / p.k);
    }

    // since symmetric spread -> equation #29 and #30 yields the following bid and ask prices.

    double getNewBidPrice(double reservationPrice, double spread)
    {
        return reservationPrice - spread / 2;
    }

    double getNewAskPrice(double reservationPrice, double spread)
    {
        return reservationPrice + spread / 2;
    }

} // namespace model::formula