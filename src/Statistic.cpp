#include <Statistics.h>
#include <cmath>
#include <iostream>
#include <numeric>

void calculateAndPrintStatistics(const Simulator &s)
{
    // fetch the data from the simulator.
    std::vector<double> spreads = s.getSpreads();
    std::vector<double> profits = s.getProfits();
    std::vector<double> quantities = s.getQuantities();

    double averageSpread = std::accumulate(spreads.begin(), spreads.end(), 0.0) / spreads.size();
    std::cout << "Average spread: " << averageSpread << std::endl;

    double averageProfit = std::accumulate(profits.begin(), profits.end(), 0.0) / profits.size();
    std::cout << "Average profit: " << averageProfit << std::endl;

    double meanProfit = averageProfit; // this is the same as average profit.

    double stdDevProfit =
        std::sqrt(std::inner_product(profits.begin(), profits.end(), profits.begin(), 0.0) / profits.size() -
                  meanProfit * meanProfit);
    std::cout << "Standard deviation of profit: " << stdDevProfit << std::endl;

    double averageQuantity = std::accumulate(quantities.begin(), quantities.end(), 0.0) / quantities.size();
    std::cout << "Average quantity: " << averageQuantity << std::endl;

    double stdDevQuantity = std::sqrt(
        std::inner_product(quantities.begin(), quantities.end(), quantities.begin(), 0.0) / quantities.size() -
        averageQuantity * averageQuantity);
    std::cout << "Standard deviation of quantity: " << stdDevQuantity << std::endl;
}