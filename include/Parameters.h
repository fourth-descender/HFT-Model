// Parameters.h
#ifndef PARAMETERS_H
#define PARAMETERS_H

#define TERMINAL_TIME 1.0
#define NUMBER_OF_SIMULATIONS 1000
#define NUMBER_OF_TIME_STEPS 200

namespace model
{

struct parameters
{
    double k;     // intensity
    double sigma; // volatility

    double gamma; /* risk aversion
                     risk aversion here refers to how much the market maker
                     is willing to expose his/her inventory to risk. */

    double A; // likelihood of arrival (for bid/ask orders)
    double T; // terminal time (end of trading day)

    double Q0; /* initial inventory state
                  inventory state is ideal (meets the target) when it is zero.
                  inventory state is long (more stocks than target) when it is positive.
                  inventory state is short (less stocks than target) when it is negative.
                  typically, the market maker will issue bid orders above the mid price
                  (to attract sellers) to replenish his/her inventory when it is short,
                  and ask orders below the mid price (to attract buyers) to reduce
                  his/her inventory when it is long. */

    double S0; // initial stock mid price
    double dt; // time step
    double N;  // number of time steps
};

parameters initializeParameters();

} // namespace model

#endif // PARAMETERS_H