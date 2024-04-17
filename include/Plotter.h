#ifndef PLOTTER_H
#define PLOTTER_H

#include <Parameters.h>
#include <Simulator.h>
#include <gnuplot-iostream.h>

namespace model
{
void gnuHelper(Gnuplot &gp);
void plot(const Simulator &s, const model::parameters &p);
} // namespace model

#endif // PLOTTER_H