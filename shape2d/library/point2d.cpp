#include <point2d.hpp>

SHAPE2D_BEGIN
Point2D::Point2D(double x_coord, double y_coord)
    : x_coord_(x_coord),
      y_coord_(y_coord) {}

const double &Point2D::get_x_coord() const {
    return this->x_coord_;
}

const double &Point2D::get_y_coord() const {
    return this->y_coord_;
}

void Point2D::set_x_coord(const double &value) {
    this->x_coord_ = value;
}

void Point2D::set_y_coord(const double &value) {
    this->y_coord_ = value;
}

// Pythagorean theorem
double Point2D::calculate_distance_to(const Point2D &other) const {
    double distance_x = this->x_coord_ - other.x_coord_;
    double distance_y = this->y_coord_ - other.y_coord_;
    return hypot(distance_x, distance_y);
}

std::istream &operator>>(std::istream &istr, Point2D &value) {
    double x_coord, y_coord;
    istr >> x_coord >> y_coord;
    value = {x_coord, y_coord};
    return istr;
}

std::ostream &operator<<(std::ostream &ostr, const Point2D &value) {
    ostr << "(" << value.get_x_coord() << ", " << value.get_y_coord() << ")";
    return ostr;
}
SHAPE2D_END