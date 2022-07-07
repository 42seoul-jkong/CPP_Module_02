/* Any copyright is dedicated to the Public Domain.
 * https://creativecommons.org/publicdomain/zero/1.0/ */

#pragma once

class Fixed
{
private:
    static const int FRACTIONAL_BITS = 8;
    int value;

public:
    Fixed();
    Fixed(const Fixed& that);
    Fixed& operator=(const Fixed& that);
    ~Fixed();
    int getRawBits() const;
    void setRawBits(const int value);
};
