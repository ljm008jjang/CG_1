#pragma once
#include "Ray.cpp"


class Surface {
public:
	virtual bool intersect(Ray* ray, float tMin, float tMax, vec3* pixelColor) = 0;

protected:
	vec3 color = vec3(1.0f, 1.0f, 1.0f);
};