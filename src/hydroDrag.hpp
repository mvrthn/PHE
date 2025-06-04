#pragma once


#include "evaluator.hpp"


namespace PHEApp {

class HydroDragProg : public PHE::Evaluator {
protected:
    void eval(PHE::Vector2f&, const PHE::Object&) const;
};

class HydroDragRot : public PHE::Evaluator {
protected:
    void eval(PHE::Vector2f&, const PHE::Object&) const;
};

} // namespace PHEApp
