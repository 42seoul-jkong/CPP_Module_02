/* Any copyright is dedicated to the Public Domain.
 * https://creativecommons.org/publicdomain/zero/1.0/ */

#pragma once

#include <iostream>

class Fixed
{
private:
    static const int FRACTIONAL_BITS = 8;
    int value;

    Fixed(void* null, const int raw);

public:
    Fixed();
    Fixed(const Fixed& that);
    Fixed(const int value);
    Fixed(const float value);
    Fixed& operator=(const Fixed& that);
    bool operator>(const Fixed& that) const;
    bool operator<(const Fixed& that) const;
    bool operator>=(const Fixed& that) const;
    bool operator<=(const Fixed& that) const;
    bool operator==(const Fixed& that) const;
    bool operator!=(const Fixed& that) const;
    Fixed operator+() const;
    Fixed operator-() const;
    Fixed operator+(const Fixed& that) const;
    Fixed operator-(const Fixed& that) const;
    Fixed operator*(const Fixed& that) const;
    Fixed operator/(const Fixed& that) const;
    Fixed& operator++();
    Fixed operator++(int);
    Fixed& operator--();
    Fixed operator--(int);
    ~Fixed();
    int getRawBits() const;
    void setRawBits(const int value);
    float toFloat() const;
    int toInt() const;

    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
