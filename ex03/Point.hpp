/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 23:14:07 by tkuramot          #+#    #+#             */
/*   Updated: 2023/10/24 01:55:37 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by k.t. on 2023/10/23.
//

#ifndef EX03_POINT_HPP
#define EX03_POINT_HPP

#include "Fixed.hpp"


typedef class Point Vector2D;

class Point
{
public:
	Point(float x, float y);

	Point(const Point &obj);

	Point operator-(Point obj) const;

	Point &operator=(const Point &obj);

	~Point();

	static float crossProduct(const Vector2D &v1, const Vector2D &v2);

private:
	Fixed m_x;
	Fixed m_y;
};


#endif //EX03_POINT_HPP
