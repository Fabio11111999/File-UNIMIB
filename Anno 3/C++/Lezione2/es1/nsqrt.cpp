#include "nsqrt.h"
#include <cmath>

double nsqrt(double x, double epsilon) {
	double stima = x / 2, vecchia_stima;
	while(std::abs(stima * stima - x) > epsilon) {
		vecchia_stima = stima;
		stima = (vecchia_stima * vecchia_stima + x) / (2 * vecchia_stima);
	}
	return stima;
}
