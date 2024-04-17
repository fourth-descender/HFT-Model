#ifndef MODEL_H
#define MODEL_H

// standard library headers
#include <Parameters.h>
#include <random>

// model namespace
namespace model::formulas
{
// random number generation
extern std::random_device rd;
extern std::mt19937 gen;

// Model functionss
double getNewStockMidPrice(const parameters &p, double price, double t);
double getNewReservationPrice(const parameters &p, double price, double quantity, double t);
double getNewSpread(const parameters &p, double t);
double getNewBidPrice(double reservationPrice, double spread);
double getNewAskPrice(double reservationPrice, double spread);
} // namespace model::formulas

#endif