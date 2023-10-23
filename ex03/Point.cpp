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

Point::Point(const float x, const float y) : m_x(x), m_y(y)
{
}

Point::Point(const Point &obj) : m_x(obj.m_x), m_y(obj.m_y)
{
}

Point Point::operator-(Point obj) const
{
	obj.m_x = m_x - obj.m_x;
	obj.m_y = m_y - obj.m_y;
	return obj;
}

Point &Point::operator=(const Point &obj)
{
	m_x = obj.m_x;
	m_y = obj.m_y;
	return *this;
}

Point::~Point()
{
}

float Point::crossProduct(const Vector2D &v1, const Vector2D &v2)
{
	return (v1.m_x * v2.m_y - v1.m_y * v2.m_x).toFloat();
}