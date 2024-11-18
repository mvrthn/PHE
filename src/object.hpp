#pragma once


#include <array>

#include "vectors.hpp"
#include "force.hpp"


namespace PHE {

template<int size>
class Object {
public:
    Object(float mass, float inertia, Vector2f center, std::array<Vector2f, size> forces);

    inline void setPosition(Vector2f pos) { position = pos; }
    inline const Vector2f& getPosition() const { return position; }

    void update();
    
private:
    Vector2f position;
    Vector2f velocity;

    float rotationAngle;
    float rotationSpeed;
    
    const float mass;
    const float inertia;

    const Vector2f center; // center of mass

    const std::array<Vector2f, size> forces;
};
    
} // namespace PHE 