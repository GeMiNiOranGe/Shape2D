#pragma once
#ifndef POINT2D_HPP
#define POINT2D_HPP

#include <cmath>
#include <iostream>

class Point2D {
private:
    double x_coord;
    double y_coord;

public:
    Point2D(double _x_coord = 0, double _y_coord = 0);

    const double &get_x_coordinates() const;
    const double &get_y_coordinates() const;

    void set_x_coordinates(const double &_x_coord);
    void set_y_coordinates(const double &_y_coord);

    double calculate_distance_to(const Point2D &_other) const;
};

std::istream &operator>>(std::istream &_istr, Point2D &_val);
std::ostream &operator<<(std::ostream &_ostr, const Point2D &_val);

#endif // end POINT2D_HPP