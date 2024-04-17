#include <Writer.h>
#include <fstream>

void writeDataToCSV(const Simulator &s, const model::parameters &p)
{
    // retrieve the data from the simulator.
    std::vector<double> bidPrices = s.getBidPrices();
    std::vector<double> askPrices = s.getAskPrices();
    std::vector<double> stockPrices = s.getStockMidPrices();

    std::ofstream file("plot/points.csv");

    // write the header to the file.
    file << "BidPrices,AskPrices,StockMidPrices\n";

    // write the data to the file.
    for (int i = 0; i < p.N; i++)
    {
        file << bidPrices[i] << "," << askPrices[i] << "," << stockPrices[i] << "\n";
    }

    // close the file.
    file.close();
}