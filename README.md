<p align="center">
  <a href="https://code.visualstudio.com/">
    <img alt="Editor" src="https://img.shields.io/badge/Editor-VSCode-0066bb">
  </a>
  <a href="https://www.msys2.org/">
    <img alt="Compiler" src="https://img.shields.io/badge/Compiler-Mingw64_of_MSYS2-7F00FF">
  </a>
</p>

# Shape2D
Calculate the values of triangles, rectangles,... on 2D surfaces

## How to Install and Run the Project
Open terminal with Visual Studio Code and run the command line below
```cmd
mingw32-make build-and-run
```

## New features in the future
- Create a circle constructor that can initialize from the center point to another point, radius is the distance from the center to another point.
- Create copy constructor/copy-assignment operator and move constructor/move-assignment operator
- Add class Rectangle, Triangle, Square,...

## Sample code
### Calculate the circumference and area of a circle
```cpp
#include <iomanip>

#include <circle2d.hpp>

int main() {
    shape2d::Circle2D circle_one(0, 0, 5);

    std::cout << std::fixed << std::setprecision(3);
    std::cout << "Circle one: "
              << "Perimeter = " << circle_one.calculate_perimeter()
              << ", Area = " << circle_one.calculate_area() << std::endl;
    return 0;
}
```

Output: `Circle one: Perimeter = 31.416, Area = 78.540`

### Determine the relative positions of the two circles
```cpp
#include <iomanip>

#include <circle2d.hpp>

int main() {
    shape2d::Circle2D circle_one(0, 0, 5), circle_two(1, 0, 3);

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
```
Output: `One circle lying inside another`

### Full sample code in [main](main.cpp)