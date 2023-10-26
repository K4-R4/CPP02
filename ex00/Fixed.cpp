/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:45:36 by tkuramot          #+#    #+#             */
/*   Updated: 2023/10/26 21:04:08 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by k.t. on 2023/10/20.
//

#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed() : fixed_point_number_(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj) {
  std::cout << "Copy constructor called" << std::endl;
  *this = obj;
}

Fixed &Fixed::operator=(const Fixed &obj) {
  std::cout << "Copy assignment operator called" << std::endl;
  fixed_point_number_ = obj.GetRawBits();
  return *this;
}

Fixed::~Fixed() {
  std::cout << "Destructor called" << std::endl;
}

int Fixed::GetRawBits() const {
  std::cout << "getRawBits member function called" << std::endl;
  return fixed_point_number_;
}

void Fixed::SetRawBits(const int row) {
  std::cout << "setRawBits member function called" << std::endl;
  fixed_point_number_ = row;
}