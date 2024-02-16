#include <Simulator.h>

Simulator::Simulator(
    const model::formula::parameters& p, 
    PoissonArrival& bids,
    PoissonArrival& asks,
    double numberOfSimulations,
    double numberOfSteps
)
    : p(&p), 
      bids(&bids), 
      asks(&asks), 
      numberOfSimulations(numberOfSimulations), 
      numberOfSteps(numberOfSteps) 
{}

void Simulator::run()
{
    for (int i = 0; i < numberOfSimulations; i++)
    {
        Simulation s(*p, *bids, *asks);
        for (int j = 1; j <= numberOfSteps; j++)
        {
            s.simulate(p->T - j/numberOfSteps);
            bidPrices.push_back(         s.getBidPrice());
            askPrices.push_back(         s.getAskPrice());
            spreads.push_back(           s.getSpread());
            stockPrices.push_back(       s.getStockPrice());
            reservationPrices.push_back( s.getReservationPrice());
            quantities.push_back(        s.getQuantity());
            wealths.push_back(           s.getWealth());
        }
    }
}

std::vector<double> Simulator::getBidPrices()         { return bidPrices; }
std::vector<double> Simulator::getAskPrices()         { return askPrices; }
std::vector<double> Simulator::getSpreads()           { return spreads; }
std::vector<double> Simulator::getStockPrices()       { return stockPrices; }
std::vector<double> Simulator::getReservationPrices() { return reservationPrices; }
std::vector<double> Simulator::getQuantities()        { return quantities; }
std::vector<double> Simulator::getWealths()           { return wealths; }