/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:45:36 by tkuramot          #+#    #+#             */
/*   Updated: 2023/10/21 00:52:22 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by k.t. on 2023/10/20.
//

#ifndef EX00_FIXED_HPP
#define EX00_FIXED_HPP

class Fixed {
 public:
  Fixed();
  Fixed(const Fixed &obj);
  Fixed &operator=(const Fixed &obj);
  ~Fixed();
  int GetRawBits() const;
  void SetRawBits(int row);

 private:
  int fixed_point_number_;
  static const int kFractionalBits = 8;
};

#endif //EX00_FIXED_HPP
