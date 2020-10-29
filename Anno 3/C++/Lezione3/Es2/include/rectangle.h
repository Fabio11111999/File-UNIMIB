#ifndef rectangle_h
#define rectangle_h

#include "point.h"

struct  rectangle {
	point tl;
	point br;
};

int width(rectangle r);
int height(rectangle r);
int area(rectangle r);

#endif
