/* Any copyright is dedicated to the Public Domain.
 * https://creativecommons.org/publicdomain/zero/1.0/ */

#include "Fixed.hpp"
#include <iostream>

#define VERBOSE

Fixed::Fixed()
    : value()
{
#ifdef VERBOSE
    std::cout << "Default constructor called" << std::endl;
#endif
}

Fixed::Fixed(const Fixed& that)
{
#ifdef VERBOSE
    std::cout << "Copy constructor called" << std::endl;
#endif
    *this = that;
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
