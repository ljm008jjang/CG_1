#pragma once
#include "Surface.cpp"

using namespace glm;
using namespace std;

class Plane : public Surface{
public:
	Plane(float planeD) : PlaneD(planeD) {}

    float PlaneD;

public:

    virtual bool intersect(Ray* ray, float tMin, float tMax) override {
        // Plane equation: Ax + By + Cz + D = 0
        // For simplicity, we assume the plane is at y = 0 (ground plane)
        vec3 planeNormal = vec3(0.0f, 1.0f, 0.0f);

        // Calculate the denominator of the intersection formula
        float denom = dot(planeNormal, ray->direction);
        if (abs(denom) < 1e-6) {
            return false; // Ray is parallel to the plane
        }

        // Calculate the intersection point
        float t = -(dot(planeNormal, ray->origin) + PlaneD) / abs(denom);
        if (t < tMin || t > tMax) {
            return false; // Intersection is out of bounds
        }

        return true;
    }
};