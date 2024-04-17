#include <Plotter.h>
#include <Simulator.h>
#include <gnuplot-iostream.h>

namespace model
{
void plot(const Simulator &s)
{
    using PRICES = const std::vector<double> &;
    using TIMESTAMPS = std::vector<double>;

    PRICES bids = s.getBidPrices();
    PRICES asks = s.getAskPrices();
    PRICES stockMidPrices = s.getStockMidPrices();

    // Normalize x-axis values to range from 0 to 1
    TIMESTAMPS times;
    for (size_t i = 0; i < bids.size(); ++i)
    {
        double normalized_x = static_cast<double>(i) / (bids.size() - 1);
        times.push_back(normalized_x);
    }

    // Create a Gnuplot object
    Gnuplot gp;

    // Plot the data
    gp << "set title 'Bid, Ask, and Stock Mid Prices'\n";
    gp << "set xlabel 'Time'\n";
    gp << "set ylabel 'Price'\n";
    gp << "plot '-' with linespoints title 'Bids', '-' with linespoints title 'Asks', '-' with linespoints title "
          "'Stock Mid Prices'\n";
    gp.send1d(std::make_tuple(times, bids));
    gp.send1d(std::make_tuple(times, asks));
    gp.send1d(std::make_tuple(times, stockMidPrices));
}
} // namespace model