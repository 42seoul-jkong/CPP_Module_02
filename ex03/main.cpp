/* Any copyright is dedicated to the Public Domain.
 * https://creativecommons.org/publicdomain/zero/1.0/ */

#include "Point.hpp"
#include <iostream>

int main(void)
{
    Point p = Point(0, 0);
    Point q = Point(0, 5);
    Point r = Point(5, 0);
    std::cout << "TRUE" << std::endl;
    std::cout << bsp(p, q, r, Point(1, 1)) << std::endl;
    std::cout << bsp(p, q, r, Point(1, 2)) << std::endl;
    std::cout << bsp(p, q, r, Point(1, 3)) << std::endl;
    std::cout << bsp(p, q, r, Point(2, 1)) << std::endl;
    std::cout << bsp(p, q, r, Point(2, 2)) << std::endl;
    std::cout << bsp(p, q, r, Point(3, 1)) << std::endl;
    std::cout << bsp(p, q, r, Point(5, 0)) << std::endl;
    std::cout << bsp(p, q, r, Point(1, 4)) << std::endl;
    std::cout << bsp(p, q, r, Point(2, 3)) << std::endl;
    std::cout << bsp(p, q, r, Point(3, 2)) << std::endl;
    std::cout << bsp(p, q, r, Point(4, 1)) << std::endl;
    std::cout << bsp(p, q, r, Point(0, 5)) << std::endl;
    std::cout << "FALSE" << std::endl;
    std::cout << bsp(p, q, r, Point(1, 5)) << std::endl;
    std::cout << bsp(p, q, r, Point(2, 4)) << std::endl;
    std::cout << bsp(p, q, r, Point(3, 3)) << std::endl;
    std::cout << bsp(p, q, r, Point(4, 2)) << std::endl;
    return 0;
}
