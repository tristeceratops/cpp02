/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <ewoillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 15:17:19 by ewoillar          #+#    #+#             */
/*   Updated: 2024/08/27 13:40:20 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed c = 100;
	Fixed d = 3;
	
	std::cout << "1) " << a << std::endl;
	std::cout << "2) " << ++a << std::endl;
	std::cout << "3) " << a << std::endl;
	std::cout << "4) " << a++ << std::endl;
	std::cout << "5) " << a << std::endl;
	std::cout << "6) " << --a << std::endl;
	std::cout << "7) " << a << std::endl;
	std::cout << "8) " << a-- << std::endl;
	std::cout << "9) " << a << std::endl;
	std::cout << "10) " << b << std::endl;
	int i = b.toInt();
	float f = b.toFloat();
	std::cout << "11) " << i << std::endl;
	std::cout << "12) " << f << std::endl;
	
	std::cout << "13) " << Fixed::max( a, b ) << std::endl;
	std::cout << "14) " << Fixed::min( a, b ) << std::endl;
	std::cout << "15) " << Fixed::max( a, c ) << std::endl;
	
	std::cout << "16) " << c + d << std::endl;
	std::cout << "17) " << d - c << std::endl;
	std::cout << "18) " << c - d << std::endl;
	std::cout << "19) " << c * d << std::endl;
	std::cout << "20) " << c / d << std::endl;
	std::cout << "21) " << d / c << std::endl;

	return 0;
}