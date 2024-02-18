#include <Simulator.h>
#include <iostream>

#define TERMINAL_TIME 1.0
#define NUMBER_OF_SIMULATIONS 1000
#define NUMBER_OF_TIME_STEPS 200

int main()
{
    parameters p = 
    {
        .k = 1.5,
        .sigma = 2.0,
        .gamma = 0.1,
        .S0 = 100.0,
        .T = TERMINAL_TIME,
        .N = NUMBER_OF_TIME_STEPS,
        .dt = TERMINAL_TIME / NUMBER_OF_TIME_STEPS,
        .A = 140.0,
        .Q0 = 0.0
    };

    // the two symmetric poisson arrival processes.
    PoissonArrival bids(p.A, p.k);
    PoissonArrival asks(p.A, p.k);

    Simulator s(p, bids, asks, NUMBER_OF_SIMULATIONS);
    s.run();

    std::vector<double> bidPrices         = s.getBidPrices();
    std::vector<double> askPrices         = s.getAskPrices();
    std::vector<double> spreads           = s.getSpreads();
    std::vector<double> stockPrices       = s.getStockPrices();
    std::vector<double> reservationPrices = s.getReservationPrices();
    std::vector<double> quantities        = s.getQuantities();
    std::vector<double> wealths           = s.getWealths();
    std::vector<double> profits           = s.getProfits();


    double averageSpread = std::accumulate(spreads.begin(), spreads.end(), 0.0) / spreads.size();
    std::cout << "Average spread: " << averageSpread << std::endl;

    double averageProfit = std::accumulate(profits.begin(), profits.end(), 0.0) / profits.size();
    std::cout << "Average profit: " << averageProfit << std::endl;

    double meanProfit = std::accumulate(profits.begin(), profits.end(), 0.0) / profits.size();

    double stdDevProfit = std::sqrt(std::inner_product(profits.begin(), profits.end(), profits.begin(), 0.0) / profits.size() - meanProfit * meanProfit);
    std::cout << "Standard deviation of profit: " << stdDevProfit << std::endl;

    double averageQuantity = std::accumulate(quantities.begin(), quantities.end(), 0.0) / quantities.size();
    std::cout << "Average quantity: " << averageQuantity << std::endl;

    double stdDevQuantity = std::sqrt(std::inner_product(quantities.begin(), quantities.end(), quantities.begin(), 0.0) / quantities.size() - averageQuantity * averageQuantity);
    std::cout << "Standard deviation of quantity: " << stdDevQuantity << std::endl;
}