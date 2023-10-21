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

	int getRawBits() const;

	void setRawBits(int row);

private:
	int fixedPointNumber;

	static const int fractionalBits;
};


#endif //EX00_FIXED_HPP
