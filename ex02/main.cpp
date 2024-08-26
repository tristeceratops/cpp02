/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <ewoillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 15:17:19 by ewoillar          #+#    #+#             */
/*   Updated: 2024/08/26 18:34:14 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
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
	//std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}