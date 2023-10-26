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

const int Fixed::kFractionalBits = 8;

Fixed::Fixed() : fixed_point_number_(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int integer) {
  std::cout << "Int constructor called" << std::endl;
  SetRawBits(integer << Fixed::kFractionalBits);
}

Fixed::Fixed(const float floating_point_number) {
  std::cout << "Float constructor called" << std::endl;
  float shifted = floating_point_number * static_cast<float>(1 << Fixed::kFractionalBits);
  SetRawBits(static_cast<int>(roundf(shifted)));
}

Fixed::Fixed(const Fixed &obj) {
  std::cout << "Copy constructor called" << std::endl;
  *this = obj;
}

Fixed &Fixed::operator=(const Fixed &obj) {
  std::cout << "Copy assignment operator called" << std::endl;
  SetRawBits(obj.GetRawBits());
  return *this;
}

Fixed::~Fixed() {
  std::cout << "Destructor called" << std::endl;
}

int Fixed::GetRawBits() const {
  return fixed_point_number_;
}

void Fixed::SetRawBits(const int row) {
  fixed_point_number_ = row;
}

int Fixed::ToInt() const {
  return GetRawBits() >> Fixed::kFractionalBits;
}

float Fixed::ToFloat() const {
  return static_cast<float>(GetRawBits()) / (1 << Fixed::kFractionalBits);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
  os << fixed.ToFloat();
  return os;
}
