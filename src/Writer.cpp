#include <Writer.h>

void writeDataToCSV(const Simulator& s, const parameters& p) {
    // retrieve the data from the simulator.
    std::vector<double> bidPrices = s.getBidPrices();
    std::vector<double> askPrices = s.getAskPrices();
    std::vector<double> stockPrices = s.getStockPrices();

    std::ofstream file("plot/points.csv");

    // write the header to the file.
    file << "BidPrices,AskPrices,StockPrices\n";

    // write the data to the file.
    for (int i = 0; i < p.N; i++)
    {
        file << bidPrices[i] << "," << askPrices[i] << "," << stockPrices[i] << "\n";
    }

    // close the file.
    file.close();
}