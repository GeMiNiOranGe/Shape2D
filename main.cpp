#include <circle2d.hpp>

int main() {
    shape2d::Point2D point(0, 0);
    shape2d::Circle2D circle_one(0, 0, 4), circle_two(1, 0, 2);

    std::cout << "Point: " << point << std::endl;
    std::cout << "Circle one: "
              << "Perimeter = " << circle_one.calculate_perimeter()
              << ", Area = " << circle_one.calculate_area() << std::endl;
    std::cout << "Circle two: "
              << "Perimeter = " << circle_two.calculate_perimeter()
              << ", Area = " << circle_two.calculate_area() << std::endl;

    shape2d::PointPosition position = circle_one.determine_relative_position(point);
    switch (position) {
    case shape2d::PointPosition::CENTER:
        std::cout << "Point is the center of the circle";
        break;
    case shape2d::PointPosition::INSIDE:
        std::cout << "Point lies inside the circle";
        break;
    case shape2d::PointPosition::ON:
        std::cout << "Point lies on the circle";
        break;
    default:
        std::cout << "Point lies outside the circle";
        break;
    }
    std::cout << std::endl;

    shape2d::CirclePosition circle_pos = circle_one.determine_relative_position(circle_two);
    switch (circle_pos) {
    case shape2d::CirclePosition::CONCENTRIC:
        std::cout << "2 concentric circles";
        break;
    case shape2d::CirclePosition::LIE_INSIDE:
        std::cout << "One circle lying inside another";
        break;
    case shape2d::CirclePosition::TOUCH_INTERNAL:
        std::cout << "Two circles touching each other internally";
        break;
    case shape2d::CirclePosition::INTERSECT:
        std::cout << "Two circles intersecting each other at two points";
        break;
    case shape2d::CirclePosition::TOUCH_EXTERNAL:
        std::cout << "Two circles touching each other externally";
        break;
    default:
        std::cout << "Two circles lying outside each other";
        break;
    }
    return 0;
}
