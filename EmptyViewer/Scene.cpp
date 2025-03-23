#pragma once
#include "Surface.cpp"
#include <vector>
#include "Sphere.cpp"

using namespace glm;
using namespace std;

class Scene {
	vector<Surface*> surfaces;

public:
	void clear() {
		surfaces.clear();
	}

	void addSurface(Surface* surface) {
		surfaces.push_back(surface);
	}

	vec3 trace(Ray* ray, float tMin, float tMax) {
		vec3 color = vec3(0.0f, 0.0f, 0.0f);
		for (int i = 0; i < surfaces.size(); i++) {
			if (surfaces[i]->intersect(ray, tMin, tMax)) {
				//if (dynamic_cast<Sphere*>(surfaces[i])) {
				//	color = vec3(0.0f, 1.0f, 1.0f); // red color [0,1] in RGB channel
				//}
				//else {
				//	color = vec3(1.0f, 1.0f, 1.0f); // red color [0,1] in RGB channel
				//}
				color = vec3(1.0f, 1.0f, 1.0f); // red color [0,1] in RGB channel
			}
		}
		return color;
	}
};