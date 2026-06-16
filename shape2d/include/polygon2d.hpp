#pragma once
#ifndef POLYGON2D_HPP
#define POLYGON2D_HPP

#include <vector>

#include <macros.hpp>
#include <point2d.hpp>

SHAPE2D_BEGIN
class Polygon2D {
protected:
    std::vector<Point2D> vertices;

public:
    Polygon2D(const std::vector<Point2D> &points = {});

    const std::vector<Point2D> &get_vertices() const;
    size_t vertex_count() const;

    const Point2D &centroid() const;
};
SHAPE2D_END

#endif // end POLYGON2D_HPP