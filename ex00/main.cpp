/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:48:04 by tkuramot          #+#    #+#             */
/*   Updated: 2023/10/21 11:58:52 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by k.t. on 2023/10/20.
//
#include <iostream>
#include "Fixed.hpp"

int main() {
  Fixed a;
  Fixed b(a);
  Fixed c;
  c = b;
  std::cout << a.GetRawBits() << std::endl;
  std::cout << b.GetRawBits() << std::endl;
  std::cout << c.GetRawBits() << std::endl;
  return 0;
}