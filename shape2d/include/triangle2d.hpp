#pragma once
#ifndef TRIANGLE2D_HPP
#define TRIANGLE2D_HPP

#include <geometry2d.hpp>
#include <macros.hpp>
#include <point2d.hpp>
#include <polygon2d.hpp>

SHAPE2D_BEGIN
class Triangle2D : public Polygon2D, public Geometry2D {
private:
public:
    Triangle2D(const Point2D &A, const Point2D &B, const Point2D &C);

    const Point2D &get_vertex_a() const;
    const Point2D &get_vertex_b() const;
    const Point2D &get_vertex_c() const;

    double calculate_perimeter() const override;
    double calculate_area() const override;
};
SHAPE2D_END

#endif // end TRIANGLE2D_HPP