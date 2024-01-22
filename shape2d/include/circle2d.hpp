#pragma once
#ifndef CIRCLE2D_HPP
#define CIRCLE2D_HPP

#include <iostream>
#include <numbers>

#include <geometry2d.hpp>
#include <macros.hpp>
#include <point2d.hpp>

SHAPE2D_BEGIN
class Circle2D : public Geometry2D {
private:
    Point2D center;
    double radius;

public:
    Circle2D(double _x_coord = 0.0, double _y_coord = 0.0, double _radius = 0.0);
    Circle2D(Point2D _center, double _radius = 0.0);

    const Point2D &get_center() const;
    const double &get_radius() const;

    void set_center(const Point2D &_point);
    void set_radius(const double &_radius);

    void xacDinhViTriTuongDoiDiem(Point2D);
    void xacDinhViTriTuongDoi(Circle2D);

    double calculate_perimeter() const override;
    double calculate_area() const override;
};

std::istream &operator>>(std::istream &_istr, Circle2D &_val);
std::ostream &operator<<(std::ostream &_ostr, const Circle2D &_val);
SHAPE2D_END

#endif // end CIRCLE2D_HPP