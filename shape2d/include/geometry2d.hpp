#pragma once
#ifndef GEOMETRY2D_HPP
#define GEOMETRY2D_HPP

#include <macros.hpp>

SHAPE2D_BEGIN
class Geometry2D {
public:
    virtual double calculate_perimeter() const = 0;
    virtual double calculate_area() const = 0;
};
SHAPE2D_END

#endif // end GEOMETRY2D_HPP