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

//This is required for sphere collision.
glm::vec3 projectUonV(glm::vec3 u, glm::vec3 v){
    glm::vec3 r;
    double scale = (double) glm::dot(u,v) / (double) glm::dot(v,v);
    r = v * scale;
    return r;
}


bool CollideSpheres(Sphere *sphere1, Sphere *sphere2) {
    if (DetectSphereCollision){
        //glm::vec3 collisionVector = sphere1->centerPoint - sphere2->centerPoint;
        glm::vec3 nv1; // new velocity for sphere 1
        glm::vec3 nv2; // new velocity for sphere 2

        // this is some VOODOO MAGIC from stack overflow that I had to convert back to glfw / glad. 

        // this can probably be optimised a bit, but it basically swaps the velocity amounts
        // that are perpendicular to the surface of the collistion.
        // If the spheres had different masses, then u would need to scale the amounts of
        // velocities exchanged inversely proportional to their masses.
        // nv1 = s1.velocity;
        // nv1 += projectUonV(s2.velocity, minus(s2.position, s1.position));
        // nv1 -= projectUonV(s1.velocity, minus(s1.position, s2.position));
        // nv2 = s2.velocity;
        // nv2 += projectUonV(s1.velocity, minus(s2.position, s1.position));
        // nv2 -= projectUonV(s2.velocity, minus(s1.position, s2.position));
        // s1.velocity = nv1;
        // s2.velocity = nv2;


        nv1 = sphere1->velocity;
        nv1 += projectUonV(sphere2->velocity, sphere2->position - sphere1->position);
        nv1 -= projectUonV(sphere1->velocity, sphere1->position - sphere2->position);
        nv2 = sphere2->velocity;
        nv2 += projectUonV(sphere1->velocity, sphere2->position - sphere1->position);
        nv2 -= projectUonV(sphere2->velocity, sphere1->position - sphere2->position);

        sphere1->velocity = nv1;
        sphere2->velocity = nv2;

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

