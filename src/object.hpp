#pragma once


#include <vector>

#include "vectors.hpp"
#include "force.hpp"


namespace PHE {

class Object {
public:
    Object(float _mass, float _inertia, Vector2f _pos);

protected:
    void setForces(std::vector<Force>& _forces);

    void setPosition(const Vector2f& _position);
    const Vector2f& getPosition() const;

    const float getRotationAngle() const;

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