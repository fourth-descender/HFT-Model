#ifndef SIMULATION_H
#define SIMULATION_H

#include <Arrival.h>
#include <Model.h>

class Simulation
{
  public:
    Simulation(const model::parameters &p, PoissonArrival &arrivals);

    // simulate method performs one step of the simulation.
    void simulate(double t);

    // get methods.
    double getBidPrice() const
    {
        return bid;
    }
    double getAskPrice() const
    {
        return ask;
    }
    double getSpread() const
    {
        return spread;
    }
    double getStockMidPrice() const
    {
        return price;
    }
    double getReservationPrice() const
    {
        return reservationPrice;
    }
    double getQuantity() const
    {
        return quantity;
    }
    double getWealth() const
    {
        return wealth;
    }

  private:
    double price;            // current stock price.
    double quantity;         // current quantity of stocks.
    double bid;              // current bid price.
    double ask;              // current ask price.
    double wealth;           // current wealth.
    double reservationPrice; // current reservation price.
                             // reservation price is the price at which the market maker
                             // is indifferent between buying and selling as the change
                             // in inventory is still within the risk tolerance.
    double spread;              // current spread.
    const model::parameters *p; // parameters of the simulation.
    PoissonArrival *bids;       // poisson arrival for bids.
    PoissonArrival *asks;       // poisson arrival for asks.
};

#endif