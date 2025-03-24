#pragma once
#include "Surface.cpp"

using namespace glm;
using namespace std;

class Plane : public Surface{
public:
	Plane(vec3 normal, float planeD) : Normal(normal), PlaneD(planeD) {}

    // Plane equation: Ax + By + Cz = D
    vec3 Normal; // ¹ý¼± º¤ÅÍ (a, b, c)
    // -2.0f
    float PlaneD;

public:
    //helped by Copilot
    virtual bool intersect(Ray* ray, float tMin, float tMax, vec3* pixelColor) override {
        // Calculate the denominator of the intersection formula
        float denom = dot(Normal, ray-> direction);
        if (abs(denom) < 1e-6) {
            return false; // Ray is parallel to the plane
        }

        // Calculate the intersection point
        float t = -(dot(Normal, ray->origin) - PlaneD) / denom;
        if (t < tMin || t > tMax) {
            return false; // Intersection is out of bounds
        }

        *pixelColor = color;
        return true;
    }
};