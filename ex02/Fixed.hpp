/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <ewoillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 15:17:21 by ewoillar          #+#    #+#             */
/*   Updated: 2024/08/29 10:29:01 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed &src);
		Fixed(const int raw);
		Fixed(const float raw);
		~Fixed(void);

		Fixed	&operator=(const Fixed &rhs);
		bool	operator>(const Fixed &rhs);
		bool	operator<(const Fixed &rhs);
		bool	operator>=(const Fixed &rhs);
		bool	operator<=(const Fixed &rhs);
		bool	operator==(const Fixed &rhs);
		bool	operator!=(const Fixed &rhs);
		Fixed	operator+(const Fixed &rhs);
		Fixed	operator-(const Fixed &rhs);
		Fixed	operator*(const Fixed &rhs);
		Fixed	operator/(const Fixed &rhs);
		Fixed	&operator++();
		Fixed	operator++(int);
		Fixed	&operator--();
		Fixed	operator--(int);
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
 		static Fixed &min(Fixed &f1, Fixed &f2);
    	static const Fixed &min(const Fixed &f1, const Fixed &f2);
    	static Fixed &max(Fixed &f1, Fixed &f2);
    	static const Fixed &max(const Fixed &f1, const Fixed &f2);

	private:
		int					_raw;
		static const int	_bits = 8;
};

std::ostream	&operator<<(std::ostream &o, const Fixed &rhs);
