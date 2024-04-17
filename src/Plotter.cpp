#include <Plotter.h>
#include <Simulator.h>
#include <gnuplot-iostream.h>

namespace model
{
TIMESTAMPS generateTimestamps(const model::parameters &p)
{
    TIMESTAMPS times(p.N);
    std::iota(times.begin(), times.end(), 0);
    return times;
}

PRICES getLastNPrices(const PRICES &prices, const model::parameters &p)
{
    return PRICES(prices.end() - p.N, prices.end());
}

void plot(const Simulator &s, const model::parameters &p)
{
    PRICES bids = s.getBidPrices();
    PRICES asks = s.getAskPrices();
    PRICES stockMidPrices = s.getStockMidPrices();

    TIMESTAMPS times = generateTimestamps(p);

    PRICES lastNBids = getLastNPrices(bids, p);
    PRICES lastNAsks = getLastNPrices(asks, p);
    PRICES lastNStockMidPrices = getLastNPrices(stockMidPrices, p);

    Gnuplot gp;
    gp << "set xlabel 'Time'\n";
    gp << "set ylabel 'Price'\n";
    gp << "plot '-' with lines title 'Bid Prices', '-' with lines title 'Ask Prices', '-' with lines title 'Stock Mid "
          "Prices'\n";
    gp.send1d(std::make_tuple(times, lastNBids));
    gp.send1d(std::make_tuple(times, lastNAsks));
    gp.send1d(std::make_tuple(times, lastNStockMidPrices));
}
} // namespace model