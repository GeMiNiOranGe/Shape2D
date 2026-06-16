#include <polygon2d.hpp>

SHAPE2D_BEGIN
Polygon2D::Polygon2D(const std::vector<Point2D> &points)
    : vertices(points) {}

const std::vector<Point2D> &Polygon2D::get_vertices() const {
    return vertices;
}

size_t Polygon2D::vertex_count() const {
    return vertices.size();
}

const Point2D &Polygon2D::centroid() const {
    double sum_of_x_coord, sum_of_y_coord;
    size_t count = this->vertex_count();

    for (auto &&vertex : this->vertices) {
        sum_of_x_coord += vertex.get_x_coord();
        sum_of_y_coord += vertex.get_y_coord();
    }

    double x_coord_of_centroid = sum_of_x_coord / count;
    double y_coord_of_centroid = sum_of_y_coord / count;
    return Point2D(x_coord_of_centroid, y_coord_of_centroid);
}
SHAPE2D_END
