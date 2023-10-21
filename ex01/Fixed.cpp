/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:45:36 by tkuramot          #+#    #+#             */
/*   Updated: 2023/10/21 17:05:18 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by k.t. on 2023/10/20.
//

#include <iostream>
#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::Fixed() : fixedPointNumber(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int integer) {
	std::cout << "Int constructor called" << std::endl;
	this->fixedPointNumber = (integer << Fixed::fractionalBits);
}

Fixed::Fixed(const float floatingPointNumber) {
	std::cout << "Float constructor called" << std::endl;
	float shifted = floatingPointNumber * static_cast<float>(1 << Fixed::fractionalBits);
	this->fixedPointNumber = static_cast<int>(roundf(shifted));
}

Fixed::Fixed(const Fixed &obj) {
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed &Fixed::operator=(const Fixed &obj) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &obj)
		return (*this);
	this->fixedPointNumber = obj.fixedPointNumber;
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedPointNumber);
}

void Fixed::setRawBits(const int row) {
	std::cout << "setRawBits member function called" << std::endl;
	this->fixedPointNumber = row;
}

int Fixed::toInt() const {
	return (this->fixedPointNumber >> Fixed::fractionalBits);
}

float Fixed::toFloat() const {
	return (static_cast<float>(this->fixedPointNumber) / (1 << Fixed::fractionalBits));
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
	os << fixed.toFloat();
	return os;
}
