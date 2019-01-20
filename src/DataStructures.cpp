#include <glm/vec3.hpp>

class Shape {
    public:
        glm::vec3 centerPoint;
        glm::vec3 velocity;
        bool isMovable;
};

class DrawableShape{
    public:
        Shape collidable;
        virtual void draw(){};
};

class Sphere : Shape{
    public:
        float radius;
        
        Sphere(float radius, glm::vec3 centerPoint, glm::vec3 velocity) {
            this->centerPoint = centerPoint;
            this->velocity = velocity;
            this->radius = radius;
        }
};

class Box : Shape {
    public:
        float width;
        float height;

        Box(float width, float height, glm::vec3 centerPoint, glm::vec3 velocity) {
            this->centerPoint = centerPoint;
            this->velocity = velocity;
            this->width = width;
            this->height = height;
        }
};
