#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <Model.h>
#include <Arrival.h>
#include <Simulation.h>
#include <vector>

class Simulator
{
    public:
        Simulator(
            const model::formula::parameters& p, 
            PoissonArrival& bids,
            PoissonArrival& asks,
            double numberOfSimulations,
            double numberOfSteps
        );

        void run();

        std::vector<double> getBidPrices();
        std::vector<double> getAskPrices();
        std::vector<double> getSpreads();
        std::vector<double> getStockPrices();
        std::vector<double> getReservationPrices();
        std::vector<double> getQuantities();
        std::vector<double> getWealths();

    private:
        parameters *p;
        PoissonArrival *bids;
        PoissonArrival *asks;
        double numberOfSimulations;
        double numberOfSteps;
        std::vector<double> bidPrices;
        std::vector<double> askPrices;
        std::vector<double> spreads;
        std::vector<double> stockPrices;
        std::vector<double> reservationPrices;
        std::vector<double> quantities;
        std::vector<double> wealths;
};

#endif