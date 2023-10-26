/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 23:14:07 by tkuramot          #+#    #+#             */
/*   Updated: 2023/10/24 01:28:09 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by k.t. on 2023/10/23.
//

#include "Fixed.hpp"
#include "Point.hpp"

Point::Point(const float x, const float y) : x_(x), y_(y) {
}

Point::Point(const Point &obj) : x_(obj.x_), y_(obj.y_) {
}

Point Point::operator-(Point obj) const {
  obj.x_ = x_ - obj.x_;
  obj.y_ = y_ - obj.y_;
  return obj;
}

Point &Point::operator=(const Point &obj) {
  x_ = obj.x_;
  y_ = obj.y_;
  return *this;
}

Point::~Point() {
}

float Point::CrossProduct(const Point &v1, const Point &v2) {
  return (v1.x_ * v2.y_ - v1.y_ * v2.x_).ToFloat();
}