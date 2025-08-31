#include <circle2d.hpp>

SHAPE2D_BEGIN
Circle2D::Circle2D(double x_coord, double y_coord, double radius)
    : center_(x_coord, y_coord),
      radius_(radius) {}

Circle2D::Circle2D(Point2D center, double radius)
    : center_(center),
      radius_(radius) {}

const Point2D &Circle2D::get_center() const {
    return this->center_;
}

const double &Circle2D::get_radius() const {
    return this->radius_;
}

void Circle2D::set_center(const Point2D &point) {
    this->center_ = point;
}

void Circle2D::set_radius(const double &radius) {
    this->radius_ = radius;
}

PointPosition Circle2D::determine_relative_position(const Point2D &point) const {
    double distance = this->center_.calculate_distance_to(point);

    if (distance == 0) {
        return PointPosition::CENTER;
    }
    if (distance < this->radius_) {
        return PointPosition::INSIDE;
    }
    if (distance == this->radius_) {
        return PointPosition::ON;
    }
    return PointPosition::OUTSIDE;
}

CirclePosition Circle2D::determine_relative_position(const Circle2D &circle) const {
    double distance_centers = this->center_.calculate_distance_to(circle.center_);
    double difference_radius = abs(this->radius_ - circle.radius_);
    double sum_radius = this->radius_ + circle.radius_;

    if (distance_centers == 0) {
        return CirclePosition::CONCENTRIC;
    }
    if (distance_centers < difference_radius) {
        return CirclePosition::LIE_INSIDE;
    }
    if (distance_centers == difference_radius) {
        return CirclePosition::TOUCH_INTERNAL;
    }
    if (difference_radius < distance_centers && distance_centers < sum_radius) {
        return CirclePosition::INTERSECT;
    }
    if (distance_centers == sum_radius) {
        return CirclePosition::TOUCH_EXTERNAL;
    }
    return CirclePosition::LIE_OUTSIDE;
}

double Circle2D::calculate_perimeter() const {
    return std::numbers::pi_v<double> * this->radius_ * 2;
}

double Circle2D::calculate_area() const {
    return std::numbers::pi_v<double> * this->radius_ * this->radius_;
}

std::istream &operator>>(std::istream &istr, Circle2D &value) {
    Point2D center;
    double radius;
    std::cout << "Input center: ";
    istr >> center;
    std::cout << "Input radius: ";
    istr >> radius;
    value = {center, radius};
    return istr;
}

std::ostream &operator<<(std::ostream &ostr, const Circle2D &value) {
    ostr << "Center: " << value.get_center() << ", radius: " << value.get_radius();
    return ostr;
}
SHAPE2D_END