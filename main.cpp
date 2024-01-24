#include <circle2d.hpp>

int main() {
    // shape2d::Point2D point(0, 2);
    shape2d::Circle2D c1(0, 0, 4), c2(1, 0, 2);
    // std::cin >> c1 >> c2;
    // std::cout << "Circle one: "
    //           << "Perimeter = " << c1.calculate_perimeter() << ", Area = " << c1.calculate_area() << std::endl;
    // std::cout << "Circle two: "
    //           << "Perimeter = " << c2.calculate_perimeter() << ", Area = " << c2.calculate_area() << std::endl;

    shape2d::CirclePosition circle_pos = c1.determine_relative_position(c2);
    switch (circle_pos) {
    case shape2d::CirclePosition::CONCENTRIC:
        std::cout << "Concentric";
        break;
    case shape2d::CirclePosition::LIE_INSIDE:
        std::cout << "One lying inside other";
        break;
    case shape2d::CirclePosition::TOUCH_INTERNAL:
        std::cout << "Touching internally";
        break;
    case shape2d::CirclePosition::INTERSECT:
        std::cout << "Intersecting at two points";
        break;
    case shape2d::CirclePosition::TOUCH_EXTERNAL:
        std::cout << "Touching externally";
        break;
    default:
        std::cout << "Lying outside each other";
        break;
    }

    // shape2d::PointPosition position = c1.determine_relative_position(point);
    // switch (position) {
    // case shape2d::PointPosition::OUTSIDE:
    //     std::cout << "Diem nam ngoai duong tron";
    //     break;
    // case shape2d::PointPosition::ON:
    //     std::cout << "Diem nam tren duong tron";
    //     break;
    // case shape2d::PointPosition::INSIDE:
    //     std::cout << "Diem nam trong duong tron";
    //     break;
    // }
    return 0;
}
