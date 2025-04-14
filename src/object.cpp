#include "object.hpp"


#include <algorithm>


namespace PHE {

Object::Object(float m, float i, Vector2f p): mass(m), inertia(i), position(p) {
    velocity = {0, 0};
    rotationAngle = 0;
    rotationSpeed = 0;
}

void Object::setForces(std::vector<Force>& fs) {
    forces = std::move(fs);
}

const Vector2f& Object::getPosition() const {
    return position;
}

const Vector2f& Object::getVelocity() const {
    return velocity;
}

const float Object::getRotationAngle() const {
    return rotationAngle;
}

const float Object::getRotationSpeed() const {
    return rotationSpeed;
}

void Object::update(float dt) {
    Vector2f resultant(0, 0);
    float rotation = 0;

    for(Force& force : forces) {
        force.update(*this, resultant, rotation);
    }
    
    resultant /= mass;
    velocity += resultant * dt;
    position += velocity * dt;

    rotation /= inertia;
    rotationSpeed += rotation * dt;
    rotationAngle += rotationSpeed * dt;
}

} // namespace PHE