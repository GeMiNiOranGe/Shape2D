#pragma once
#ifndef GEOMETRY2D_HPP
#define GEOMETRY2D_HPP

class Geometry2D {
public:
    virtual double calculate_perimeter() const = 0;
    virtual double calculate_area() const = 0;
};

#endif // end GEOMETRY2D_HPP