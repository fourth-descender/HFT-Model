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
            PoissonArrival& arrivals,
            double numberOfSimulations
        );

        void run();

        // getter methods.
        std::vector<double> getBidPrices() const;
        std::vector<double> getAskPrices() const;
        std::vector<double> getSpreads() const;
        std::vector<double> getStockPrices() const;
        std::vector<double> getReservationPrices() const;
        std::vector<double> getQuantities() const;
        std::vector<double> getWealths() const;
        std::vector<double> getProfits() const;

    private:
        void simulate();
        void commit(Simulation& s);

        parameters *p;
        PoissonArrival *arrivals;
        double numberOfSimulations;
        double numberOfSteps;
        std::vector<double> bidPrices;
        std::vector<double> askPrices;
        std::vector<double> spreads;
        std::vector<double> stockPrices;
        std::vector<double> reservationPrices;
        std::vector<double> quantities;
        std::vector<double> wealths;
        std::vector<double> profits;
};

#endif