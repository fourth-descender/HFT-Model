#include <Arrival.h>

PoissonArrival::PoissonArrival(model::parameters &p) : A(p.A), k(p.k), gen(rd()), d(0, 1)
{
}

bool PoissonArrival::arrives(double delta, double dt)
{
    double lambda = A * exp(-k * delta);
    double p = lambda * dt; // standard poisson probability of arrival.
    double u = d(gen);      // uniform random number between 0 and 1.

    return u < p;
}