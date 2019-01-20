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
    float scale = glm::dot(u,v) / glm::dot(v,v);
    r = v * scale;
    return r;
}

bool DetectSpherePlaneCollision(Sphere *sphere, Plane *plane){
    double d = glm::dot(sphere->centerPoint - plane->point, glm::cross(plane->vector1, plane->vector2));
    if (d <= sphere->radius){
        return true;
    }
    return false;
}


bool CollideSphereWithPlane(Sphere* sphere, Plane* plane){
    if (DetectSpherePlaneCollision(sphere, plane)){
        sphere->velocity = glm::reflect(sphere->velocity, glm::cross(plane->vector1, plane->vector2));
        return true;
    } 
    else {
        return false;
    }
}

bool CollideSpheres(Sphere *sphere1, Sphere *sphere2) {
    if (DetectSphereCollision(sphere1, sphere2)){
        
        // this can probably be optimised a bit, but it basically swaps the velocity amounts
        // that are perpendicular to the surface of the collistion.

        // this is some VOODOO MAGIC from stack overflow that I had to convert back to glfw / glad.
	    // https://stackoverflow.com/questions/3232318/sphere-sphere-collision-detection-reaction 
        
        glm::vec3 nv2; // new velocity for sphere 2
        glm::vec3 nv1; // new velocity for sphere 1

        nv1 = sphere1->velocity;
        nv2 = sphere2->velocity;
        
        nv1 += projectUonV(sphere2->velocity, sphere2->centerPoint - sphere1->centerPoint);
        nv1 -= projectUonV(sphere1->velocity, sphere1->centerPoint - sphere2->centerPoint);
        nv2 += projectUonV(sphere1->velocity, sphere2->centerPoint - sphere1->centerPoint);
        nv2 -= projectUonV(sphere2->velocity, sphere1->centerPoint - sphere2->centerPoint);
        
        sphere1->velocity = nv1;
        sphere2->velocity = nv2;        

        return true;
    }
    else {
        return false;
    }
}

void CollideShapes(Shape *shape1, Shape *shape2){
    int WhoIs1 = shape1->getWhoAmI();
    int WhoIs2 = shape2->getWhoAmI();
	if ( WhoIs1 == 1 && WhoIs2== 1) {
        CollideSpheres((Sphere*)shape1, (Sphere*)shape2);
    }
    else if ( WhoIs1 == 6 && WhoIs2 == 6){

    }
    else if ( WhoIs1 == 1 && WhoIs2 == 6) {

    }
    else if ( WhoIs1 == 6 && WhoIs2 == 1) {

    }
}
