#ifndef PLOTTER_H
#define PLOTTER_H

#include <Parameters.h>
#include <Simulator.h>

namespace model
{
using PRICES = std::vector<double>;
using TIMESTAMPS = std::vector<double>;

TIMESTAMPS generateTimestamps(const model::parameters &p);
PRICES getLastNPrices(const PRICES &prices, const model::parameters &p);
void plot(const Simulator &s, const model::parameters &p);
} // namespace model

#endif // PLOTTER_H