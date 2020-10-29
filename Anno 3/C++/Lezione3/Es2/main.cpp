#include <iostream> 
#include "rectangle.h"
#include "point.h"

int main() {
	std::cout << "Please enter x and y values for P1" << std::endl;
	int x, y;
	std::cin >> x >> y;
	point tl = {x, y};
	std::cout << "Please enter x and y values for P2" << std::endl;
	std::cin >> x >> y;
	point br = {x, y};
	
	rectangle r = {tl, br};
	std::cout << "The area is equal to: " << area(r) << std::endl;
	
	std::cout << "Please enter the x and y values for P1" << std::endl;
	std::cin >> x >> y;
	tl = move(tl, x, y);
	r.tl = tl;
	std::cout << "The area is equal to: " << area(r) << std::endl;
	return 0;
}
