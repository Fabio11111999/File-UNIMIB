#include <iostream> 
#include <cmath>

int main() {
	double left = 0, right = M_PI;
	int n;
	std::cout << "Inserire il numero di intervalli" << std::endl;
	std::cin >> n;
	double offset = right / n;
	double integral = 0;
	for(int i = 0; i < n; i++) {
		double start = i * offset;
		double end = start + offset;
		integral += (std::sin(start) + std::sin(end)) * offset / 2;
	}
	std::cout << integral << std::endl;
	return 0;
}
