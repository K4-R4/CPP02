/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:45:36 by tkuramot          #+#    #+#             */
/*   Updated: 2023/10/21 16:54:59 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by k.t. on 2023/10/20.
//

#ifndef EX00_FIXED_HPP
#define EX00_FIXED_HPP

#include <ostream>

class Fixed {
 public:
  Fixed();
  Fixed(int integer);
  Fixed(float floating_point_number);
  Fixed(const Fixed &obj);
  bool operator>(const Fixed &obj) const;
  bool operator<(const Fixed &obj) const;
  bool operator>=(const Fixed &obj) const;
  bool operator<=(const Fixed &obj) const;
  bool operator==(const Fixed &obj) const;
  bool operator!=(const Fixed &obj) const;
  Fixed operator+(Fixed obj) const;
  Fixed operator-(Fixed obj) const;
  Fixed operator*(Fixed obj) const;
  Fixed operator/(Fixed obj) const;
  Fixed &operator=(const Fixed &obj);
  Fixed &operator++();
  Fixed operator++(int);
  Fixed &operator--();
  Fixed operator--(int);
  ~Fixed();
  int GetRawBits() const;
  void SetRawBits(int row);
  int ToInt() const;
  float ToFloat() const;
  static Fixed &Min(Fixed &f1, Fixed &f2);
  static const Fixed &Min(const Fixed &f1, const Fixed &f2);
  static Fixed &Max(Fixed &f1, Fixed &f2);
  static const Fixed &Max(const Fixed &f1, const Fixed &f2);

 private:
  int fixed_point_number_;
  static const int kFractionalBits;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif //EX00_FIXED_HPP
