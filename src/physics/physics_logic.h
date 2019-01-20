#ifndef PHYSICS_LOGIC_H
#define PHYSICS_LOGIC_H
#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include "DataStructures.h"

bool DetectSphereCollision(Sphere *sphere1, Sphere *sphere2);
glm::vec3 projectUonV(glm::vec3 u, glm::vec3 v);
bool CollideSphereWithPlane(Sphere *sphere, Plane *plane);
bool CollideSpheres(Sphere *sphere1, Sphere *sphere2);
void CheckCollisionType(Shape *shape1, Shape *shape2);

#endif