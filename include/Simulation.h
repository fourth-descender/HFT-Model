#ifndef SIMULATION_H
#define SIMULATION_H

#include <Model.h>
#include <Arrival.h>

using parameters = const model::formula::Parameters;

class Simulation
{
    public:
        Simulation(
            const parameters& p, 
            PoissonArrival& arrivals
        );

        // simulate method performs one step of the simulation.
        void simulate(double t);

        // get methods.
        double getBidPrice()         { return bid; }
        double getAskPrice()         { return ask; }
        double getSpread()           { return spread; }
        double getStockPrice()       { return price; }
        double getReservationPrice() { return reservationPrice; }
        double getQuantity()         { return quantity; }
        double getWealth()           { return wealth; }

    private:
        double          price;              // current stock price.
        double          quantity;           // current quantity of stocks.
        double          bid;                // current bid price.
        double          ask;                // current ask price.
        double          wealth;             // current wealth.
        double          reservationPrice;   // current reservation price.
        double          spread;             // current spread.
        parameters*     p;                  // parameters of the simulation.
        PoissonArrival* bids;               // poisson arrival for bids.
        PoissonArrival* asks;               // poisson arrival for asks.
};

#endif