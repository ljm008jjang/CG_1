#pragma once
#include "Surface.cpp"
#include <vector>
#include "Sphere.cpp"

using namespace glm;
using namespace std;

class Scene {
	//Scene Objects
	vector<Surface*> surfaces;

public:
	void clear() {
		surfaces.clear();
	}

	//Add Object
	void addSurface(Surface* surface) {
		surfaces.push_back(surface);
	}

	//Check intersected Objects and return color of pixel
	vec3 trace(Ray* ray, float tMin, float tMax) {
		//set default color
		vec3 color = vec3(0.0f, 0.0f, 0.0f);

		for (int i = 0; i < surfaces.size(); i++) {
			if (surfaces[i]->intersect(ray, tMin, tMax)) {
				color = vec3(1.0f, 1.0f, 1.0f);
			}
		}
		return color;
	}
};