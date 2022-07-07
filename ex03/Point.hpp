/* Any copyright is dedicated to the Public Domain.
 * https://creativecommons.org/publicdomain/zero/1.0/ */

#pragma once

#include "Fixed.hpp"

class Point
{
private:
    const Fixed x;
    const Fixed y;

public:
    Point();
    Point(const float x, const float y);
    Point(const Point& that);
    Point(const int value);
    Point(const float value);
    Point& operator=(const Point& that);
    ~Point();
};

bool bsp(const Point a, const Point b, const Point c, const Point point);
