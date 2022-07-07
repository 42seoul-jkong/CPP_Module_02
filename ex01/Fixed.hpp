/* Any copyright is dedicated to the Public Domain.
 * https://creativecommons.org/publicdomain/zero/1.0/ */

#pragma once

#include <iostream>

class Fixed
{
private:
    static const int FRACTIONAL_BITS = 8;
    int value;

public:
    Fixed();
    Fixed(const Fixed& that);
    Fixed(const int value);
    Fixed(const float value);
    Fixed& operator=(const Fixed& that);
    ~Fixed();
    int getRawBits() const;
    void setRawBits(const int value);
    float toFloat() const;
    int toInt() const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
