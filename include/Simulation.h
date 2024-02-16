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
            PoissonArrival& bids,
            PoissonArrival& asks
        );

        // simulate method performs one step of the simulation.
        void simulate();

    private:
        double          price;              // current stock price.
        double          quantity;           // current quantity of stocks.
        double          bid;                // current bid price.
        double          ask;                // current ask price.
        double          wealth;             // current wealth.
        double          reservationPrice;   // current reservation price.
        double          spread;             // current spread.
        parameters*     p;                  // parameters of the simulation.
        PoissonArrival* bids;
        PoissonArrival* asks;
};

#endif