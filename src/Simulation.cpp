#include <Simulation.h>

Simulation::Simulation(
    const parameters& p, 
    PoissonArrival& arrivals
)
    : p(&p), 
      bids(&arrivals), 
      asks(&arrivals), 
      price(p.S0), 
      quantity(0), 
      wealth(0),
      reservationPrice(p.S0), 
      spread(0) 
{}

void Simulation::simulate(double t)
{
    price = model::formula::getNewStockPrice(*p, price, t);

    reservationPrice = model::formula::getNewReservationPrice(*p, price, quantity, t);
    spread           = model::formula::getNewSpread(*p, t);

    bid = model::formula::getNewBidPrice(reservationPrice, spread);
    ask = model::formula::getNewAskPrice(reservationPrice, spread);

    double deltaBid = price - bid;
    double deltaAsk = ask - price;

    if (bids->arrives(deltaBid, p->dt))
    {
        quantity += 1;
        wealth   -= bid;
    }

    if (asks->arrives(deltaAsk, p->dt))
    {
        quantity -= 1;
        wealth   += ask;
    }
}