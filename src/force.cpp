#include "force.hpp"

namespace PHE {

void Force::move(const Vector2f& _origin) {
    origin = _origin;

    dv = origin();
    if(dv == 0) {
        dx2 = 1;
        dy2 = 1;
        dxdy = 1;
        e = 0;
    }
    else {
        e = 1 / (dv * dv);
        dx2 = origin.x * origin.x * e;
        dy2 = origin.y * origin.y * e;
        dxdy = origin.x * origin.y * e;
    }
}

void Force::update(const Object& object, Vector2f& resultant, float& rotation) {
    eval(vector, object);

    resultant += Vector2f(dx2 * vector.x, dxdy * vector.x); 
    resultant += Vector2f(dxdy * vector.y, dy2 * vector.y);

    rotation -= dv * origin.y * vector.x * e;
    rotation += dv * origin.x * vector.y * e;
} 
    
} // namespace PHE
