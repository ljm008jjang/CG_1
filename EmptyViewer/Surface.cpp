#pragma once
#include "Ray.cpp"


class Surface {
public:
	virtual bool intersect(Ray* ray, float tMin, float tMax) = 0;
};