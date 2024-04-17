#include <Plotter.h>
#include <Simulator.h>
#include <algorithm>
#include <gnuplot-iostream.h>
#include <numeric>
#include <tuple>
#include <vector>

namespace model
{
using PRICES = std::vector<double>;
using TIMESTAMPS = std::vector<double>;
using V_PRICES = std::vector<PRICES>;

void gnuHelper(Gnuplot &gp)
{
    gp << "set terminal qt enhanced font 'SpaceMono Nerd Font Propo,12'\n";
    gp << "set grid\n";
    gp << "set xlabel 'Time'\n";
    gp << "set ylabel 'Price'\n";
    gp << "plot '-' with lines title 'Bid Prices', '-' with lines title 'Ask Prices', '-' with lines title 'Stock Mid "
          "Prices'\n";
}

void plot(const Simulator &s, const model::parameters &p)
{
    // prices to plot.
    V_PRICES prices = {s.getBidPrices(), s.getAskPrices(), s.getStockMidPrices()};

    // time stamps for the x-axis.
    TIMESTAMPS times(p.N);
    std::iota(times.begin(), times.end(), 0);
    std::for_each(times.begin(), times.end(), [&p](double &n) { n /= (p.N - 1); });

    Gnuplot gp;
    gnuHelper(gp);
    for (const PRICES &price : prices)
    {
        // cut off the last N prices.
        PRICES lastPrices(price.end() - p.N, price.end());
        gp.send1d(std::make_tuple(times, lastPrices));
    }

    gp << "pause mouse close\n";
}
} // namespace model