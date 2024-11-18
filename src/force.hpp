#pragma once


#include <cassert>

#include "vectors.hpp"


namespace PHE {

class Force {
public:
    Force(Vector2f _vector, Vector2f _origin, void (*_eval)(Vector2f&)): vector(_vector), origin(_origin), eval(_eval) {};
    Force(Vector2f _origin, void (*_eval)(Vector2f&)): origin(_origin), eval(_eval) {};
    Force(const Force& other): vector(other.vector), origin(other.origin), eval(other.eval) {};
    
    inline const Vector2f& getVector() const { return vector; }
    inline const Vector2f& getOrigin() const { return origin; }
    
    inline void move(const Vector2f& new_origin) { origin = new_origin; }

    inline void update() { eval(vector); }
    
private:
    Vector2f vector; // force vector
    Vector2f origin; // point of application
    void (*eval)(Vector2f&);
};

} // namespace PHE
