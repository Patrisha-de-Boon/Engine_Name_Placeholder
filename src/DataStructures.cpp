#include <glm/vec3.hpp>

class Shape {
    protected:
        glm::vec3 centerPoint;
        glm::vec3 velocity;

    public:
        glm::vec3 getCenterPoint(){ return centerPoint; }
        virtual bool setCenterPoint(){}
        glm::vec3 getVelocity(){ return velocity; }
        virtual bool setCenterPoint(){}
};

class DrawableShape{
    public:
        Shape collidable;
        virtual void draw(){};
};

class MoveableShape : Shape{
    public:
        bool setCenterPoint(glm::vec3 centerPoint){
            this->centerPoint = centerPoint;
            return true;
        }

        bool setVelocity(glm::vec3 velocity){
            this->velocity = velocity;
            return true;
        }
};

class ImmoveableShape : Shape{
    public:
        bool setCenterPoint(glm::vec3 centerPoint){
            this->centerPoint = centerPoint;
            return false;
        }

        bool setVelocity(glm::vec3 velocity){
            this->velocity = velocity;
            return false;
        }
};

class Sphere : MoveableShape{
    public:
        float radius;
        
        Sphere(float radius, glm::vec3 centerPoint, glm::vec3 velocity) {
            setCenterPoint(centerPoint);
            setVelocity(velocity);
            this->radius = radius;
        }

        
};

class Box : MoveableShape {
    public:
        float width;
        float height;

        Box(float width, float height, glm::vec3 centerPoint, glm::vec3 velocity) {
            setCenterPoint(centerPoint);
            setVelocity(velocity);
            this->width = width;
            this->height = height;
        }
};s