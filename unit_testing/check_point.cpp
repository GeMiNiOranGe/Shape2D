#include <cassert>

#include <point2d.hpp>

bool nearly_equal(double a, double b, double eps = 1e-9);

int main(int argc, char const *argv[]) {
    shape2d::Point2D point_a(-4, 2);
    shape2d::Point2D point_b(2, 1);

    double expected = std::sqrt(37.0);

    double result1 = point_a.calculate_distance_to(point_b);
    assert(nearly_equal(result1, expected));
    std::cout << "Distance from A to B: Pass" << std::endl;

    double result2 = point_b.calculate_distance_to(point_a);
    assert(nearly_equal(result2, expected));
    std::cout << "Distance from B to A: Pass" << std::endl;
}

bool nearly_equal(double a, double b, double eps = 1e-9) {
    return std::fabs(a - b) < eps;
};
