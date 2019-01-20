#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H

#include <glm/vec3.hpp>

class Shape {
    public:
        glm::vec3 centerPoint;
        glm::vec3 velocity;
        bool isMovable;
        float mass;
        int getWhoAmI(){ return whoAmI; }

    protected: 
        int whoAmI;
};

class DrawableShape{
    public:
        Shape collidable;
        virtual void draw(){};
};

class Sphere : public Shape{
    public:
        float radius;
        
        Sphere(float radius, glm::vec3 centerPoint, glm::vec3 velocity) {
            this->centerPoint = centerPoint;
            this->velocity = velocity;
            this->radius = radius;
            this->whoAmI = 1;
        }
};

class Box : public Shape {
    public:
        float width;
        float height;

        Box(float width, float height, glm::vec3 centerPoint, glm::vec3 velocity) {
            this->centerPoint = centerPoint;
            this->velocity = velocity;
            this->width = width;
            this->height = height;
            this->whoAmI = 6;
        }
};

#endif