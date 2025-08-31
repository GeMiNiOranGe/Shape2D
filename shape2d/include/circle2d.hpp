#pragma once
#ifndef CIRCLE2D_HPP
#define CIRCLE2D_HPP

#include <iostream>
#include <numbers>

#include <geometry2d.hpp>
#include <macros.hpp>
#include <point2d.hpp>
#include <point_position.hpp>
#include <circle_position.hpp>

SHAPE2D_BEGIN
class Circle2D : public Geometry2D {
private:
    Point2D center_;
    double radius_;

public:
    Circle2D(double x_coord = 0.0, double y_coord = 0.0, double radius = 0.0);
    Circle2D(Point2D center, double radius = 0.0);

    const Point2D &get_center() const;
    const double &get_radius() const;

    void set_center(const Point2D &point);
    void set_radius(const double &radius);

    PointPosition determine_relative_position(const Point2D &point) const;
    CirclePosition determine_relative_position(const Circle2D &circle) const;

    double calculate_perimeter() const override;
    double calculate_area() const override;
};

std::istream &operator>>(std::istream &istr, Circle2D &value);
std::ostream &operator<<(std::ostream &ostr, const Circle2D &value);
SHAPE2D_END

#endif // end CIRCLE2D_HPP