#include <Simulation.h>

Simulation::Simulation(
    const parameters& p, 
    PoissonArrival& bids,
    PoissonArrival& asks
)
    : p(&p), 
      bids(&bids), 
      asks(&asks), 
      price(p.S0), 
      quantity(0), 
      wealth(0),
      reservationPrice(p.S0), 
      spread(0) 
{}

void Simulation::simulate()
{
    price = model::formula::getNewStockPrice(*p, price, 0);

    reservationPrice = model::formula::getNewReservationPrice(*p, price, quantity, 0);
    spread           = model::formula::getNewSpread(*p, 0);

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