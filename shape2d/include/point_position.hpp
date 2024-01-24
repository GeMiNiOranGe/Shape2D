#pragma once
#ifndef POINT_POSITION_HPP
#define POINT_POSITION_HPP

#include <macros.hpp>

SHAPE2D_BEGIN
enum class PointPosition {
    OUTSIDE,
    ON,
    INSIDE,
    CENTER
};
SHAPE2D_END

#endif // end POINT_POSITION_HPP