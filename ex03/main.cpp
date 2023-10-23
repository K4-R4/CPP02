/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:39:31 by tkuramot          #+#    #+#             */
/*   Updated: 2023/10/24 01:56:05 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by k.t. on 2023/10/23.
//
#define MAX (2147483648.0f/256)
#define MIN (1.0f/256)

#include <iostream>
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Vector2D AB = b - a;
	Vector2D BC = c - b;
	Vector2D CA = a - c;
	Vector2D BP = point - b;
	Vector2D CP = point - c;
	Vector2D AP = point - a;

	// Cross product
	float c1 = Point::crossProduct(AB, BP);
	float c2 = Point::crossProduct(BC, CP);
	float c3 = Point::crossProduct(CA, AP);

	if ((c1 > 0 && c2 > 0 && c3 > 0) || (c1 < 0 && c2 < 0 && c3 < 0))
		return true;
	return false;
}

int main()
{
	Point A(1.0f, 3.0f);
	Point B(-1.0f, -1.0f);
	Point C(5.0f, 1.0f);
	Point tests[] = {
			Point(1.34f, 1.1f), // true
			Point(1.44f, 2.02f), // true
			Point(-1.22f, 2.04f), // false
			Point(2.8f, 0.86f), // true
			Point(0.532f, 2.064f), // false
			A, // false
			B, // false
			C, // false
	};

	for (size_t i = 0; i < sizeof tests / sizeof(class Point); i++)
	{
		std::cout << std::boolalpha
				  << "Test " << i << " : " << bsp(A, B, C, tests[i]) << std::endl;
	}


	Point a(0, 0);
	Point b(MAX, MAX);
	Point c(MAX, 0);
	Point pt1(-1, -1);

	std::cout << std::boolalpha
			  << bsp(a, b, c, pt1) << std::endl;
	std::cout << (Fixed(MAX - 1) - Fixed(MIN) == Fixed(MAX - 1)) << std::endl;
	return 0;
}