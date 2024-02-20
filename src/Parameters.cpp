// Parameters.cpp
#include "Parameters.h"

parameters initializeParameters() {
    parameters p = 
    {
        .k = 1.5,
        .sigma = 2.0,
        .gamma = 0.1,
        .S0 = 100.0,
        .T = TERMINAL_TIME,
        .N = NUMBER_OF_TIME_STEPS,
        .dt = TERMINAL_TIME / NUMBER_OF_TIME_STEPS,
        .A = 140.0,
        .Q0 = 0.0
    };
    return p;
}