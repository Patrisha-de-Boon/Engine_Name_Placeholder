#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H

#include <glm/vec3.hpp>

class Shape {
    public:
        glm::vec3 centerPoint;
        glm::vec3 velocity;
        glm::vec3 orientation;
        bool isMovable;
        float mass;
        int getWhoAmI(){ return whoAmI; }

    protected: 
        int whoAmI;
};

class DrawableShape{
    public:
        Shape collidable;
        float vertices[];
};

class Sphere : public Shape{
    public:
        float radius;
        
        Sphere(glm::vec3 centerPoint, glm::vec3 velocity, glm::vec3 orientation, float radius, float mass = 1, float isMovable = true) {
            this->centerPoint = centerPoint;
            this->velocity = velocity;
            this->radius = radius;
            this->whoAmI = 1;
            this->mass = mass;
            this->isMovable = isMovable;
        }
};

class Box : public Shape {
    public:
        float width;
        float height;

        Box(glm::vec3 centerPoint, glm::vec3 velocity, glm::vec3 orientation, float width, float height, float mass = 1, float isMovable = true) {
            this->centerPoint = centerPoint;
            this->velocity = velocity;
            this->width = width;
            this->height = height;
            this->whoAmI = 6;
            this->mass = mass;
            this->isMovable = isMovable;
        }
};

struct Plane {
    glm::vec3 vector1;
    glm::vec3 vector2;
};

#endif