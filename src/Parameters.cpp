// Parameters.cpp

#include <Parameters.h>

namespace model
{

parameters initializeParameters()
{
    parameters p = {.k = 1.5,
                    .sigma = 2.0,
                    .gamma = 0.1,
                    .A = 140.0,
                    .T = TERMINAL_TIME,
                    .Q0 = 0.0,
                    .S0 = 100.0,
                    .dt = TERMINAL_TIME / NUMBER_OF_TIME_STEPS,
                    .N = NUMBER_OF_TIME_STEPS};
    return p;
}
} // namespace model