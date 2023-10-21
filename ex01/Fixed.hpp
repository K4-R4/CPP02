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

	Fixed(float floatingPointNumber);

	Fixed(const Fixed &obj);

	Fixed &operator=(const Fixed &obj);

	~Fixed();

	int getRawBits() const;

	void setRawBits(int row);

	int toInt() const;

	float toFloat() const;

private:
	int fixedPointNumber;

	static const int fractionalBits;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif //EX00_FIXED_HPP
