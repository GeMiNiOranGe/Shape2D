#include <circle2d.hpp>

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

void Circle2D::xacDinhViTriTuongDoiDiem(Point2D diemCanXacDinh) {
    double khoangCachTamVaDiem = this->center.calculate_distance_to(diemCanXacDinh);

    if (khoangCachTamVaDiem > this->radius) {
        std::cout << "Diem nam ngoai duong tron";
    } else if (khoangCachTamVaDiem == this->radius) {
        std::cout << "Diem nam tren duong tron";
    } else {
        std::cout << "Diem nam trong duong tron";
    }
}
void Circle2D::xacDinhViTriTuongDoi(Circle2D duongTronCanXacDinh) {
    double khoangCach2Tam = this->center.calculate_distance_to(duongTronCanXacDinh.get_center());
    double banKinh2TamTru = abs(get_radius() - duongTronCanXacDinh.get_radius());
    double banKinh2TamCong = get_radius() + duongTronCanXacDinh.get_radius();

    if (banKinh2TamTru < khoangCach2Tam && khoangCach2Tam < banKinh2TamCong) {
        std::cout << "2 duong tron cat nhau";
    } else if (khoangCach2Tam == banKinh2TamCong) {
        std::cout << "2 duong tron tiep xuc ngoai";
    } else if (khoangCach2Tam == banKinh2TamTru) {
        std::cout << "2 duong tron tiep xuc trong";
    } else if (khoangCach2Tam > banKinh2TamCong) {
        std::cout << "2 duong tron ngoai nhau";
    } else if (khoangCach2Tam < banKinh2TamTru) {
        std::cout << "2 duong tron chua nhau";
    } else if (khoangCach2Tam == 0) {
        std::cout << "2 duong tron dong tam";
    }
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
    std::cout << "Nhap toa do tam duong tron: ";
    _istr >> center;
    std::cout << "Nhap ban kinh duong tron: ";
    _istr >> radius;
    _val = {center, radius};
    return _istr;
}
std::ostream &operator<<(std::ostream &_ostr, const Circle2D &_val) {
    _ostr << "Toa do tam duong tron la: " << _val.get_center() << std::endl;
    _ostr << "Ban kinh: " << _val.get_radius();
    return _ostr;
}
