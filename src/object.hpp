#pragma once


#include <vector>

#include "force.hpp"


namespace PHE {

class Object {
public:
    Object(float _mass, float _inertia, Vector2f _pos);

    const Vector2f& getPosition() const;
    const Vector2f& getVelocity() const;
    const float getRotationAngle() const;
    const float getRotationSpeed() const;

protected:
    void setForces(std::vector<Force>& _forces);

    void update(float dt);
    
private:
    Vector2f position;
    Vector2f velocity;

    float rotationAngle;
    float rotationSpeed;
    
    const float mass;
    const float inertia;

    std::vector<Force> forces;
};
    
} // namespace PHE 