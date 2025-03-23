#pragma once
#include <glm/glm.hpp>
#include "Ray.cpp"

using namespace glm;
using namespace std;

class Camera {
public:
    glm::vec3 e;
    glm::vec3 w;
    glm::vec3 v;
    glm::vec3 u;


    float fov;
    float aspectRatio;
    float nearPlane;
    float farPlane;

    float l = -0.1f, r = 0.1f, b = -0.1f, t = 0.1f, d = 0.1f;


    Camera(glm::vec3 startPosition, glm::vec3 startUp, glm::vec3 startRight, glm::vec3 startForward, float startFov, float startAspectRatio, float startNearPlane, float startFarPlane)
        : e(startPosition), v(startUp), u(startRight),w(startForward), fov(startFov), aspectRatio(startAspectRatio), nearPlane(startNearPlane), farPlane(startFarPlane) {

    }

    glm::mat4 getViewMatrix() {
        return glm::lookAt(e, e - w, v);
    }

    glm::mat4 getProjectionMatrix() {
        return glm::perspective(glm::radians(fov), aspectRatio, nearPlane, farPlane);
    }

    Ray* getRay(int ix, int iy) {
		float u = l + (r - l) * (ix + 0.5f) / 512;
		float v = b + (t - b) * (iy + 0.5f) / 512;

        vec3 p = e;
        vec3 s = p + u * this->u + v * this->v - d * w;

        Ray* ray = new Ray(p, s - p);

        return ray;
    }
};