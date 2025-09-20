#pragma once
#ifndef POINT2D_HPP
#define POINT2D_HPP

#include <cmath>
#include <iostream>

#include <macros.hpp>

SHAPE2D_BEGIN
class Point2D {
private:
    double x_coord_;
    double y_coord_;

public:
    Point2D(double x_coord = 0.0, double y_coord = 0.0);

    const double &get_x_coord() const;
    const double &get_y_coord() const;

    void set_x_coord(const double &value);
    void set_y_coord(const double &value);

    double calculate_distance_to(const Point2D &other) const;
};

inline bool operator==(const Point2D &left, const Point2D &right) {
    return left.get_x_coord() == right.get_x_coord()
        && left.get_y_coord() == right.get_y_coord();
}

inline bool operator!=(const Point2D &left, const Point2D &right) {
    return !operator==(left, right);
}

std::istream &operator>>(std::istream &istr, Point2D &value);
std::ostream &operator<<(std::ostream &ostr, const Point2D &value);
SHAPE2D_END

#endif // end POINT2D_HPP