/* Any copyright is dedicated to the Public Domain.
 * https://creativecommons.org/publicdomain/zero/1.0/ */

#include "Point.hpp"

static Fixed AreaOfTriangle(const Point& p1, const Point& p2, const Point& p3)
{
    Fixed area = (p1.GetX() * (p2.GetY() - p3.GetY()) + p2.GetX() * (p3.GetY() - p1.GetY()) + p3.GetX() * (p1.GetY() - p2.GetY())) / Fixed(2);
    if (area < 0)
    {
        area = Fixed() - area;
    }
    return area;
}

bool bsp(const Point a, const Point b, const Point c, const Point point)
{
    Fixed abc = AreaOfTriangle(a, b, c);
    Fixed pbc = AreaOfTriangle(point, b, c);
    Fixed pac = AreaOfTriangle(a, point, c);
    Fixed pab = AreaOfTriangle(a, b, point);
    return !(abc > pbc + pac + pab);
}
