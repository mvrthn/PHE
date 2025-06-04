#pragma once


#include "object.hpp"


namespace PHE {

class Evaluator {
public:
    void evalForce(Vector2f&, const Object&) const;

protected:
    virtual void eval(Vector2f&, const Object&) const = 0;

private:
    static constexpr float DEG_TO_RAD = 0.01745329251;
};
    
} // namespace PHE