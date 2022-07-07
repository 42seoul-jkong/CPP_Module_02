/* Any copyright is dedicated to the Public Domain.
 * https://creativecommons.org/publicdomain/zero/1.0/ */

#include "Point.hpp"
#include <cmath>
#include <iostream>

Point::Point()
    : x(0), y(0)
{
    // No-OP
}

Point::Point(const float x, const float y)
    : x(x), y(y)
{
    // No-OP
}

Point::Point(const Point& that)
{
    *this = that;
}

Point& Point::operator=(const Point& that)
{
    if (this != &that)
    {
        const_cast<Fixed&>(this->x) = that.x;
        const_cast<Fixed&>(this->y) = that.y;
    }
    return *this;
}

Point::~Point()
{
    // No-OP
}
