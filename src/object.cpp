#include "object.hpp"


#include <algorithm>


namespace PHE {

Object::Object(float m, float i, Vector2f p): mass(m), inertia(i), center(p) {
    position = {0, 0};
    velocity = {0, 0};
    rotationAngle = 0;
    rotationSpeed = 0;
}

void Object::setForces(std::vector<Force>& fs) {
    forces = std::move(fs);
}

void Object::setPosition(const Vector2f& _position) {
    position = _position;
}

const Vector2f& Object::getPosition() const {
    return position;
}

const float Object::getRotationAngle() const {
    return rotationAngle;
}

void Object::update(float dt) {
    Vector2f resultant(0, 0);
    float rotation = 0;

    for(Force& force : forces) {
        force.update(resultant, rotation);
    }
    
    resultant /= mass;
    velocity += resultant;
    position += velocity * dt;

    rotation /= inertia;
    rotationSpeed += rotation;
    rotationAngle += rotationSpeed * dt;
}

} // namespace PHE