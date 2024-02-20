#include <Simulator.h>

Simulator::Simulator(
    const model::formula::parameters& p, 
    PoissonArrival& arrivals,
    double numberOfSimulations
)
    : p(&p), 
      arrivals(&arrivals),
      numberOfSimulations(numberOfSimulations), 
      numberOfSteps(p.N) 
{}

void Simulator::run()
{
    for (int i = 0; i < numberOfSimulations; i++)
    {
        simulate();
    }
}

// perform a single simulation.
void Simulator::simulate()
{
    Simulation s(*p, *arrivals);

    // simulate the simulation for the number of steps provided.
    for (int j = 1; j <= numberOfSteps; j++)
    {
        s.simulate(j/numberOfSteps);
        commit(s);
    }

    // calculate profit and loss.
    profits.push_back(wealths.back() + stockPrices.back() * quantities.back());
}

// commit the results of a simulation
void Simulator::commit(Simulation& s)
{
    bidPrices.push_back(         s.getBidPrice());
    askPrices.push_back(         s.getAskPrice());
    spreads.push_back(           s.getSpread());
    stockPrices.push_back(       s.getStockPrice());
    reservationPrices.push_back( s.getReservationPrice());
    quantities.push_back(        s.getQuantity());
    wealths.push_back(           s.getWealth());
}

// getter methods.
std::vector<double> Simulator::getBidPrices() const         { return bidPrices; }
std::vector<double> Simulator::getAskPrices() const         { return askPrices; }
std::vector<double> Simulator::getSpreads() const           { return spreads; }
std::vector<double> Simulator::getStockPrices() const       { return stockPrices; }
std::vector<double> Simulator::getReservationPrices() const { return reservationPrices; }
std::vector<double> Simulator::getQuantities() const        { return quantities; }
std::vector<double> Simulator::getWealths() const           { return wealths; }
std::vector<double> Simulator::getProfits() const           { return profits; }