#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <Arrival.h>
#include <Model.h>
#include <Parameters.h>
#include <Simulation.h>
#include <vector>

class Simulator
{
  public:
    Simulator(const model::parameters &p, PoissonArrival &arrivals, double numberOfSimulations);

    void run();

    // getter methods.
    std::vector<double> getBidPrices() const;
    std::vector<double> getAskPrices() const;
    std::vector<double> getSpreads() const;
    std::vector<double> getStockMidPrices() const;
    std::vector<double> getReservationPrices() const;
    std::vector<double> getQuantities() const;
    std::vector<double> getWealths() const;
    std::vector<double> getProfits() const;

  private:
    void simulate();
    void commit(Simulation &s);

    const model::parameters *p;
    PoissonArrival *arrivals;
    double numberOfSimulations;
    double numberOfSteps;
    std::vector<double> bidPrices;
    std::vector<double> askPrices;
    std::vector<double> spreads;
    std::vector<double> stockMidPrice;
    std::vector<double> reservationPrices;
    std::vector<double> quantities;
    std::vector<double> wealths;
    std::vector<double> profits;
};

#endif