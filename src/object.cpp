#include "object.hpp"


namespace PHE {

template<int size>
Object<size>::Object(float m, float i, Vector2f p, std::array<Vector2f, size> f): mass(m), inertia(i), center(p), forces(f) {
    position = {0, 0};
    velocity = {0, 0};
    rotationAngle = 0;
    rotationSpeed = 0;
}

template<int size>
void Object<size>::update() {
    Vector2f resultant(0, 0);
    float rotation = 0;

    for(Force& force : forces) {
        force.update();

        const Vector2f& f = force.getVector();
        const Vector2f& d = force.getOrigin();

        const float dv = d();
        const float e = 1 / (dv * dv);
        const float dx2 = d.x * d.x * e;
        const float dy2 = d.y * d.y * e;
        const float dxdy = d.x * d.y * e;

        resultant += Vector2f(dx2 * f.x, dxdy * f.x); 
        resultant += Vector2f(dxdy * f.y, dy2 * f.y);

        rotation -= dv * d.y * f.x * e;
        rotation += dv * d.x * f.y * e;
    }
    
    resultant /= mass;
    velocity += resultant;
    position += velocity;

    rotation /= inertia;
    rotationSpeed += rotation;
    rotationAngle += rotationSpeed;
}

} // namespace PHE