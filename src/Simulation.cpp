#include <Simulation.h>

Simulation::Simulation(const model::parameters &p, PoissonArrival &arrivals)
    : p(&p), bids(&arrivals), asks(&arrivals), price(p.S0), quantity(0), wealth(0), reservationPrice(p.S0), spread(0)
{
}

void Simulation::simulate(double t)
{
    price = model::formulas::getNewStockMidPrice(*p, price, t);

    reservationPrice = model::formulas::getNewReservationPrice(*p, price, quantity, t);
    spread = model::formulas::getNewSpread(*p, t);

    bid = model::formulas::getNewBidPrice(reservationPrice, spread);
    ask = model::formulas::getNewAskPrice(reservationPrice, spread);

    double deltaBid = price - bid;
    double deltaAsk = ask - price;

    // for bids to be hit, the price must be <= deltaBid.
    if (bids->arrives(deltaBid, p->dt))
    {
        // inventory becomes skewed (q > 0) -> market maker enters a short inventory position.
        quantity += 1;
        wealth -= bid;
    }

    // for asks to be hit, the price must be >= deltaAsk.
    if (asks->arrives(deltaAsk, p->dt))
    {
        // inventory becomes skewed (q < 0) -> market maker enters a long inventory position.
        quantity -= 1;
        wealth += ask;
    }
}