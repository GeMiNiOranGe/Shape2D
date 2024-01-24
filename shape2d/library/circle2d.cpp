#include <circle2d.hpp>

SHAPE2D_BEGIN
Circle2D::Circle2D(double _x_coord, double _y_coord, double _radius) {
    this->center = {_x_coord, _y_coord};
    this->radius = _radius;
}

Circle2D::Circle2D(Point2D _center, double _radius) {
    this->center = _center;
    this->radius = _radius;
}

const Point2D &Circle2D::get_center() const {
    return this->center;
}
const double &Circle2D::get_radius() const {
    return this->radius;
}

void Circle2D::set_center(const Point2D &_point) {
    this->center = _point;
}
void Circle2D::set_radius(const double &_radius) {
    this->radius = _radius;
}

PointPosition Circle2D::determine_relative_position(const Point2D &_point) const {
    double distance = this->center.calculate_distance_to(_point);

    if (distance == 0)
        return PointPosition::CENTER;
    if (distance < this->radius)
        return PointPosition::INSIDE;
    if (distance == this->radius)
        return PointPosition::ON;
    return PointPosition::OUTSIDE;
}
CirclePosition Circle2D::determine_relative_position(const Circle2D &_circle) const {
    double distance_centers = this->center.calculate_distance_to(_circle.get_center());
    double difference_radius = abs(get_radius() - _circle.get_radius());
    double sum_radius = get_radius() + _circle.get_radius();

    if (distance_centers == 0)
        return CirclePosition::CONCENTRIC;
    if (distance_centers < difference_radius)
        return CirclePosition::LIE_INSIDE;
    if (distance_centers == difference_radius)
        return CirclePosition::TOUCH_INTERNAL;
    if (difference_radius < distance_centers && distance_centers < sum_radius)
        return CirclePosition::INTERSECT;
    if (distance_centers == sum_radius)
        return CirclePosition::TOUCH_EXTERNAL;
    return CirclePosition::LIE_OUTSIDE;
}

double Circle2D::calculate_perimeter() const {
    return std::numbers::pi_v<double> * this->radius * 2;
}
double Circle2D::calculate_area() const {
    return std::numbers::pi_v<double> * this->radius * this->radius;
}

std::istream &operator>>(std::istream &_istr, Circle2D &_val) {
    Point2D center;
    double radius;
    std::cout << "Input center: ";
    _istr >> center;
    std::cout << "Input radius: ";
    _istr >> radius;
    _val = {center, radius};
    return _istr;
}
std::ostream &operator<<(std::ostream &_ostr, const Circle2D &_val) {
    _ostr << "Center: " << _val.get_center() << ", radius: " << _val.get_radius();
    return _ostr;
}
SHAPE2D_END