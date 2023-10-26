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

class Point {
 public:
  Point(float x, float y);
  Point(const Point &obj);
  Point operator-(Point obj) const;
  Point &operator=(const Point &obj);
  ~Point();
  static float CrossProduct(const Point &v1, const Point &v2);

 private:
  Fixed x_;
  Fixed y_;
};

#endif //EX03_POINT_HPP
