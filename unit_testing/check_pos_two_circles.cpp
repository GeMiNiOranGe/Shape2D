#include <cassert>

#include <circle2d.hpp>

bool is_concentric();
bool is_lying_inside();
bool is_touching_internally();
bool is_intersection();
bool is_touching_externally();
bool is_lying_outside();

int main(int argc, char const *argv[]) {
    assert(is_concentric());
    std::cout << "2 concentric circles:                              Pass" << std::endl;

    assert(is_lying_inside());
    std::cout << "One circle lying inside another:                   Pass" << std::endl;

    assert(is_touching_internally());
    std::cout << "Two circles touching each other internally:        Pass" << std::endl;

    assert(is_intersection());
    std::cout << "Two circles intersecting each other at two points: Pass" << std::endl;

    assert(is_touching_externally());
    std::cout << "Two circles touching each other externally:        Pass" << std::endl;

    assert(is_lying_outside());
    std::cout << "Two circles lying outside each other:              Pass" << std::endl;

    return 0;
}

bool is_concentric() {
    shape2d::Circle2D big_circle(0, 0, 6), small_circle(0, 0, 4);
    shape2d::CirclePosition circle_pos = big_circle.determine_relative_position(small_circle);

    return circle_pos == shape2d::CirclePosition::CONCENTRIC;
}

bool is_lying_inside() {
    shape2d::Circle2D big_circle(0, 0, 6), small_circle(1, 0, 4);
    shape2d::CirclePosition circle_pos = big_circle.determine_relative_position(small_circle);

    return circle_pos == shape2d::CirclePosition::LIE_INSIDE;
}

bool is_touching_internally() {
    shape2d::Circle2D big_circle(0, 0, 6), small_circle(2, 0, 4);
    shape2d::CirclePosition circle_pos = big_circle.determine_relative_position(small_circle);

    return circle_pos == shape2d::CirclePosition::TOUCH_INTERNAL;
}

bool is_intersection() {
    shape2d::Circle2D big_circle(0, 0, 6), small_circle(7, 0, 4);
    shape2d::CirclePosition circle_pos = big_circle.determine_relative_position(small_circle);

    return circle_pos == shape2d::CirclePosition::INTERSECT;
}

bool is_touching_externally() {
    shape2d::Circle2D big_circle(0, 0, 6), small_circle(10, 0, 4);
    shape2d::CirclePosition circle_pos = big_circle.determine_relative_position(small_circle);

    return circle_pos == shape2d::CirclePosition::TOUCH_EXTERNAL;
}

bool is_lying_outside() {
    shape2d::Circle2D big_circle(0, 0, 6), small_circle(12, 0, 4);
    shape2d::CirclePosition circle_pos = big_circle.determine_relative_position(small_circle);

    return circle_pos == shape2d::CirclePosition::LIE_OUTSIDE;
}
