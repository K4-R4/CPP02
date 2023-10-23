/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:45:36 by tkuramot          #+#    #+#             */
/*   Updated: 2023/10/23 23:08:18 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by k.t. on 2023/10/20.
//

#include <iostream>
#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::Fixed() : m_fixedPointNumber(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int integer)
{
	std::cout << "Int constructor called" << std::endl;
	setRawBits(integer << Fixed::fractionalBits);
}

Fixed::Fixed(const float floatingPointNumber)
{
	std::cout << "Float constructor called" << std::endl;
	float shifted = floatingPointNumber * static_cast<float>(1 << Fixed::fractionalBits);
	setRawBits(static_cast<int>(roundf(shifted)));
}

Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

bool Fixed::operator>(const Fixed &obj) const
{
	return getRawBits() > obj.getRawBits();
}

bool Fixed::operator<(const Fixed &obj) const
{
	return getRawBits() < obj.getRawBits();
}

bool Fixed::operator>=(const Fixed &obj) const
{
	return getRawBits() >= obj.getRawBits();
}

bool Fixed::operator<=(const Fixed &obj) const
{
	return getRawBits() <= obj.getRawBits();
}

bool Fixed::operator==(const Fixed &obj) const
{
	return getRawBits() == obj.getRawBits();
}

bool Fixed::operator!=(const Fixed &obj) const
{
	return getRawBits() != obj.getRawBits();
}

Fixed Fixed::operator+(Fixed obj) const
{
	obj.setRawBits(getRawBits() + obj.getRawBits());
	return obj;
}

Fixed Fixed::operator-(Fixed obj) const
{
	obj.setRawBits(getRawBits() - obj.getRawBits());
	return obj;
}

Fixed Fixed::operator*(Fixed obj) const
{
	obj.setRawBits((getRawBits() * obj.getRawBits()) >> Fixed::fractionalBits);
	return obj;
}

Fixed Fixed::operator/(Fixed obj) const
{
	obj.setRawBits((getRawBits() / obj.getRawBits()) << Fixed::fractionalBits);
	return obj;
}

Fixed &Fixed::operator=(const Fixed &obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	setRawBits(obj.getRawBits());
	return *this;
}

Fixed &Fixed::operator++()
{
	setRawBits(getRawBits() + 1);
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	operator++();
	return temp;
}

Fixed &Fixed::operator--()
{
	setRawBits(getRawBits() - 1);
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	operator--();
	return temp;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
	return m_fixedPointNumber;
}

void Fixed::setRawBits(const int row)
{
	m_fixedPointNumber = row;
}

int Fixed::toInt() const
{
	return getRawBits() >> Fixed::fractionalBits;
}

float Fixed::toFloat() const
{
	return static_cast<float>(getRawBits()) / (1 << Fixed::fractionalBits);
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1 <= f2)
		return f1;
	return f2;
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2)
{
	if (f1 <= f2)
		return f1;
	return f2;
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1 >= f2)
		return f1;
	return f2;
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2)
{
	if (f1 >= f2)
		return f1;
	return f2;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}
