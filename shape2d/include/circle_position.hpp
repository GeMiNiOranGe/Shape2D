#pragma once
#ifndef CIRCLE_POSITION_HPP
#define CIRCLE_POSITION_HPP

#include <macros.hpp>

SHAPE2D_BEGIN
enum class CirclePosition {
    CONCENTRIC,
    LIE_INSIDE,
    TOUCH_INTERNAL,
    INTERSECT,
    TOUCH_EXTERNAL,
    LIE_OUTSIDE,
};
SHAPE2D_END

#endif // end CIRCLE_POSITION_HPP