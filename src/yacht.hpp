#pragma once


#include "object.hpp"
#include "models.hpp"


class Yacht {
public:
    Yacht(const ModelX& _model): model(_model) {};
private:
    const Model* model;
    PHE::Object<model.mass> instance();
};