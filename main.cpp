#include <circle2d.hpp>

int main() {
    shape2d::Circle2D t1, t2;
    std::cin >> t1 >> t2;
    std::cout << "duong tron 1 co chu vi la: " << t1.calculate_perimeter() << std::endl;
    std::cout << "duong tron 1 co dien tich la: " << t1.calculate_area() << std::endl;
    std::cout << "duong tron 2 co chu vi la: " << t2.calculate_perimeter() << std::endl;
    std::cout << "duong tron 2 co dien tich la: " << t2.calculate_area() << std::endl;
    t1.xacDinhViTriTuongDoi(t2);
    std::cout << std::endl
              << t1 << std::endl;
    return 0;
}
