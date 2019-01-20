#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include "DataStructures.h"

bool DetectSphereCollision(Sphere *sphere1, Sphere *sphere2){
    float distance = glm::distance(sphere1->centerPoint, sphere2->centerPoint);
    if (distance <= (sphere1->radius + sphere2->radius)){
        return true;
    }
    return false;
}

bool CollideSpheres(Sphere *sphere1, Sphere *sphere2) {
    if (DetectSphereCollision){
        glm::vec3 collisionVector = sphere1->centerPoint - sphere2->centerPoint;
        
        return true;
    }
    else {
        return false;
    }
}

void CheckCollisionType(Shape *shape1, Shape *shape2){
	if (shape1->getWhoAmI() == 1 && shape2->getWhoAmI() == 1) {
        CollideSpheres((Sphere*)shape1, (Sphere*)shape2);
    }
}

