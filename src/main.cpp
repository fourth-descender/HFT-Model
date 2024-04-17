#include <Parameters.h>
#include <Simulator.h>
#include <Statistics.h>
#include <Writer.h>
#include <Plotter.h>

int main()
{
    model::parameters p = model::initializeParameters();

    // simulates order arrivals.
    PoissonArrival arrivals(p);

    Simulator s(p, arrivals, NUMBER_OF_SIMULATIONS);
    s.run();

    model::plot(s);
    calculateAndPrintStatistics(s);
    writeDataToCSV(s, p);
}