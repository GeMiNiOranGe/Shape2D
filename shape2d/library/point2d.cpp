#include <point2d.hpp>

SHAPE2D_BEGIN
Point2D::Point2D(double _x_coord, double _y_coord) {
    this->x_coord = _x_coord;
    this->y_coord = _y_coord;
}

const double &Point2D::get_x_coord() const {
    return this->x_coord;
}
const double &Point2D::get_y_coord() const {
    return this->y_coord;
}

void Point2D::set_x_coord(const double &_x_coord) {
    this->x_coord = _x_coord;
}
void Point2D::set_y_coord(const double &_y_coord) {
    this->y_coord = _y_coord;
}

// Pythagorean theorem
double Point2D::calculate_distance_to(const Point2D &_other) const {
    double distance_x = this->x_coord - _other.get_x_coord();
    double distance_y = this->y_coord - _other.get_y_coord();
    return sqrt(distance_x * distance_x + distance_y * distance_y);
}

std::istream &operator>>(std::istream &_istr, Point2D &_val) {
    double _x_coord, _y_coord;
    _istr >> _x_coord >> _y_coord;
    _val = {_x_coord, _y_coord};
    return _istr;
}
std::ostream &operator<<(std::ostream &_ostr, const Point2D &_val) {
    _ostr << "(" << _val.get_x_coord() << ", " << _val.get_y_coord() << ")";
    return _ostr;
}
SHAPE2D_END