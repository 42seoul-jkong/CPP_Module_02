/* Any copyright is dedicated to the Public Domain.
 * https://creativecommons.org/publicdomain/zero/1.0/ */

#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed()
    : value()
{
#ifdef VERBOSE
    std::cout << "Default constructor called" << std::endl;
#endif
}

Fixed::Fixed(void* null, const int raw)
    : value(raw)
{
    (void)&null;
#ifdef VERBOSE
    std::cout << "Internal constructor called" << std::endl;
#endif
}

Fixed::Fixed(const Fixed& that)
{
#ifdef VERBOSE
    std::cout << "Copy constructor called" << std::endl;
#endif
    *this = that;
}

Fixed::Fixed(const int value)
{
#ifdef VERBOSE
    std::cout << "Int constructor called" << std::endl;
#endif
    this->value = value << FRACTIONAL_BITS;
}

Fixed::Fixed(const float value)
{
#ifdef VERBOSE
    std::cout << "Float constructor called" << std::endl;
#endif
    this->value = (int)roundf(value * (1 << FRACTIONAL_BITS));
}

Fixed& Fixed::operator=(const Fixed& that)
{
#ifdef VERBOSE
    std::cout << "Copy assignment operator called" << std::endl;
#endif
    if (this != &that)
    {
        this->setRawBits(that.getRawBits());
    }
    return *this;
}

bool Fixed::operator>(const Fixed& that) const
{
    return this->value > that.value;
}

bool Fixed::operator<(const Fixed& that) const
{
    return this->value < that.value;
}

bool Fixed::operator>=(const Fixed& that) const
{
    return this->value >= that.value;
}

bool Fixed::operator<=(const Fixed& that) const
{
    return this->value <= that.value;
}

bool Fixed::operator==(const Fixed& that) const
{
    return this->value == that.value;
}

bool Fixed::operator!=(const Fixed& that) const
{
    return this->value != that.value;
}

Fixed Fixed::operator+(const Fixed& that)
{
    return Fixed(NULL, this->value + that.value);
}

Fixed Fixed::operator-(const Fixed& that)
{
    return Fixed(NULL, this->value - that.value);
}

Fixed Fixed::operator*(const Fixed& that)
{
    return Fixed(NULL, (this->value * that.value) >> FRACTIONAL_BITS);
}

Fixed Fixed::operator/(const Fixed& that)
{
    return Fixed(NULL, (this->value / that.value) << FRACTIONAL_BITS);
}

Fixed& Fixed::operator++()
{
    ++this->value;
    return *this;
}

Fixed Fixed::operator++(int)
{
    this->value++;
    return Fixed(NULL, this->value);
}

Fixed& Fixed::operator--()
{
    --this->value;
    return *this;
}

Fixed Fixed::operator--(int)
{
    this->value--;
    return Fixed(NULL, this->value);
}

Fixed::~Fixed()
{
#ifdef VERBOSE
    std::cout << "Destructor called" << std::endl;
#endif
}

int Fixed::getRawBits() const
{
#ifdef VERBOSE
    std::cout << "getRawBits member function called" << std::endl;
#endif
    return this->value;
}

void Fixed::setRawBits(const int value)
{
    this->value = value;
}

float Fixed::toFloat() const
{
    return (float)this->value / (1 << FRACTIONAL_BITS);
}

int Fixed::toInt() const
{
    return this->value >> FRACTIONAL_BITS;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}
