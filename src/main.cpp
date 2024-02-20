#include <Simulator.h>
#include <Parameters.h>
#include <Statistics.h>
#include <Writer.h>

int main() {
    parameters p = initializeParameters();

    // simulates order arrivals.
    PoissonArrival arrivals(p);

    Simulator s(p, arrivals, NUMBER_OF_SIMULATIONS);
    s.run();

    calculateAndPrintStatistics(s);
    writeDataToCSV(s, p);
}