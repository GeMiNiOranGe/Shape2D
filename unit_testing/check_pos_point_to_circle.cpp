#include <cassert>

#include <circle2d.hpp>

bool is_center();
bool is_inside();
bool is_on();
bool is_outside();

int main(int argc, char const *argv[]) {
    assert(is_center());
    std::cout << "Point is the center of the circle: Pass" << std::endl;

    assert(is_inside());
    std::cout << "Point lies inside the circle:      Pass" << std::endl;

    assert(is_on());
    std::cout << "Point lies on the circle:          Pass" << std::endl;

    assert(is_outside());
    std::cout << "Point lies outside the circle:     Pass" << std::endl;

    return 0;
}

bool is_center() {
    shape2d::Point2D point(0, 0);
    shape2d::Circle2D circle(0, 0, 4);
    shape2d::PointPosition point_pos = circle.determine_relative_position(point);

    return point_pos == shape2d::PointPosition::CENTER;
}

bool is_inside() {
    shape2d::Point2D point(2, 2);
    shape2d::Circle2D circle(0, 0, 4);
    shape2d::PointPosition point_pos = circle.determine_relative_position(point);

    return point_pos == shape2d::PointPosition::INSIDE;
}

bool is_on() {
    shape2d::Point2D point(4, 0);
    shape2d::Circle2D circle(0, 0, 4);
    shape2d::PointPosition point_pos = circle.determine_relative_position(point);

    return point_pos == shape2d::PointPosition::ON;
}

bool is_outside() {
    shape2d::Point2D point(4, 4);
    shape2d::Circle2D circle(0, 0, 4);
    shape2d::PointPosition point_pos = circle.determine_relative_position(point);

    return point_pos == shape2d::PointPosition::OUTSIDE;
}
