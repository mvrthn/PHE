#pragma once


#include <functional>

#include "vectors.hpp"


namespace PHE {

class Object;

class Force {
public:
    Force(Vector2f _vector, Vector2f _origin, std::function<void(Vector2f&, const Object&)> _eval): vector(_vector), eval(_eval) { move(_origin); };
    Force(Vector2f _origin, std::function<void(Vector2f&, const Object&)> _eval): eval(_eval) { move(_origin); };
    Force(const Force& other): vector(other.vector), eval(other.eval) { move(other.origin); };
    
    void move(const Vector2f& _origin);

    void update(const Object& obejct, Vector2f& prog, float& rot);
    
private:
    Vector2f vector; // force vector
    Vector2f origin; // point of application
    std::function<void(Vector2f&, const Object&)> eval; //evaluation function

    float dv;
    float e;
    float dx2;
    float dy2;
    float dxdy;
};

} // namespace PHE
