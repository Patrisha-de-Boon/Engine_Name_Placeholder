#include "DataStructures.h"

void CheckCollisionType(Shape *shape1, Shape *shape2){
	if (shape1->getWhoAmI() == 1 && shape2->getWhoAmI() == 1) {
        CollideSpheres((Sphere*)shape1, (Sphere*)shape2);
    }
}

void CollideSpheres(Sphere *sphere1, Sphere *sphere2) {
    int temp = sphere1->getWhoAmI();
}