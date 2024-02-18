#include <Model.h>

namespace model::formula 
{
    std::random_device rd;
    std::mt19937 gen(rd());
    
    double getNewStockPrice(const parameters& p, double price, double t)
    {
        // discretization of the geometric brownian motion.
        // S_{t + delta_t} = S_t + delta_S_t = S_t + sigma * dW_t
        // dW_t can be approximated by a normal random variable,
        // with mean 0 and variance delta_t, as it is normally distributed.
        // hence, S_{t + delta_t} = S_t + sigma * N(0, delta_t).
        std::normal_distribution<double> d(0, 1);
        return price + p.sigma * (d(gen) * sqrt(p.dt));
    }

    double getNewReservationPrice(const parameters& p, double price, double quantity, double t)
    {
        // equation #29 on paper.
        return price - quantity * p.gamma * std::pow(p.sigma, 2) * (p.T - t);
    }

    double getNewSpread(const parameters& p, double t)
    {
        // equation #30 on paper.
        return p.gamma * std::pow(p.sigma, 2) * (p.T - t) 
               + (2 / p.gamma) * log(1 + p.gamma / p.k);
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