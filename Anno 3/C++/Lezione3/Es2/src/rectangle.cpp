#include "rectangle.h"
#include <math.h>

int width(rectangle r) {
	return std::abs(r.br.x - r.tl.x);
}

int height(rectangle r) {
	return std::abs(r.tl.y - r.br.y);
}

int area(rectangle r) {
	return width(r) * height(r);
}
