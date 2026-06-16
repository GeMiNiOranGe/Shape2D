#include <triangle2d.hpp>

SHAPE2D_BEGIN
Triangle2D::Triangle2D(const Point2D &A, const Point2D &B, const Point2D &C)
    : Polygon2D({A, B, C}) {
    if (A == B || B == C || C == A) {
        throw std::invalid_argument("Three points must be distinct");
    }
    if (calculate_area() == 0) {
        throw std::invalid_argument("Points must not be collinear");
    }
}

const Point2D &Triangle2D::get_vertex_a() const {
    return this->vertices[0];
}

const Point2D &Triangle2D::get_vertex_b() const {
    return this->vertices[1];
}

const Point2D &Triangle2D::get_vertex_c() const {
    return this->vertices[2];
}

double Triangle2D::calculate_perimeter() const {
    return 0.0;
}

double Triangle2D::calculate_area() const {
    return 0.0;
}
SHAPE2D_END
