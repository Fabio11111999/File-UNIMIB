#include <iostream>
#include <cmath>
#include "nsqrt.h"

int main() {
	double x;
	std::cin >> x;
	std::cout << "Stima: " << nsqrt(x, 0.05) << ", Radice: " << sqrt(x);
	return 0;
}
