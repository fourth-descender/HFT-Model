#include <Simulator.h>

Simulator::Simulator(
    const model::formula::parameters& p, 
    PoissonArrival& bids,
    PoissonArrival& asks,
    double numberOfSimulations
)
    : p(&p), 
      bids(&bids), 
      asks(&asks), 
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
    Simulation s(*p, *bids, *asks);

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
std::vector<double> Simulator::getBidPrices()         { return bidPrices; }
std::vector<double> Simulator::getAskPrices()         { return askPrices; }
std::vector<double> Simulator::getSpreads()           { return spreads; }
std::vector<double> Simulator::getStockPrices()       { return stockPrices; }
std::vector<double> Simulator::getReservationPrices() { return reservationPrices; }
std::vector<double> Simulator::getQuantities()        { return quantities; }
std::vector<double> Simulator::getWealths()           { return wealths; }
std::vector<double> Simulator::getProfits()           { return profits; }