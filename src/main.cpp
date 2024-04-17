#include <Parameters.h>
#include <Plotter.h>
#include <Simulator.h>
#include <Statistics.h>

int main()
{
    model::parameters p = model::initializeParameters();

    // simulates order arrivals.
    PoissonArrival arrivals(p);

    Simulator s(p, arrivals, NUMBER_OF_SIMULATIONS);
    s.run();

    calculateAndPrintStatistics(s);
    model::plot(s, p);
}