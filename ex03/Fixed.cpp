/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <ewoillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 15:17:23 by ewoillar          #+#    #+#             */
/*   Updated: 2024/08/27 15:33:02 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _raw(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(const int raw)
{
	//std::cout << "Int constructor called" << std::endl;
	this->_raw = raw << Fixed::_bits;
}

Fixed::Fixed(const float raw)
{
	//std::cout << "Float constructor called" << std::endl;
	this->_raw = (int)roundf(raw * (1 << Fixed::_bits));
}

Fixed::~Fixed(void)
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &rhs)
{
	//std::cout << "Copy assignement operator called" << std::endl;
	if (this != &rhs)
		this->_raw = rhs.getRawBits();
	return (*this);
}

bool	Fixed::operator>(const Fixed &rhs)
{
	return this->_raw > rhs._raw;
}

bool	Fixed::operator<(const Fixed &rhs)
{
	return this->_raw < rhs._raw;
}

bool	Fixed::operator>=(const Fixed &rhs)
{
	return this->_raw >= rhs._raw;
}

bool	Fixed::operator<=(const Fixed &rhs)
{
	return this->_raw <= rhs._raw;
}

bool	Fixed::operator==(const Fixed &rhs)
{
	return this->_raw == rhs._raw;
}

bool	Fixed::operator!=(const Fixed &rhs)
{
	return this->_raw == rhs._raw;
}

Fixed	Fixed::operator+(const Fixed &rhs)
{
	Fixed f;
	f.setRawBits(this->_raw + rhs.getRawBits());
	return f;
}

Fixed	Fixed::operator-(const Fixed &rhs)
{
	Fixed f;
	f.setRawBits(this->_raw - rhs.getRawBits());
	return f;
}

Fixed	Fixed::operator*(const Fixed &rhs)
{
	Fixed f;
	long long result = (long long)this->_raw * rhs._raw;
	f.setRawBits((int)(result >> _bits));
	return f;
}

Fixed	Fixed::operator/(const Fixed &rhs)
{
	Fixed f;
	if (rhs.getRawBits() == 0)
		return std::cout << "Div by 0 not supported" << std::endl, f;
	f.setRawBits((this->_raw / rhs.getRawBits()) << _bits); //fonctionne si resultat <= 1
	return f;
}

Fixed	&Fixed::operator++()
{
	++this->_raw;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed temp = *this;
	++_raw;
	return temp;
}

Fixed	&Fixed::operator--()
{
	--this->_raw;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed temp = *this;
	--_raw;
	return temp;
}

std::ostream	&operator<<(std::ostream &o, const Fixed &rhs)
{
	o << rhs.toFloat();
	return (o);
}

int		Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->_raw);
}

void	Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member function called" << std::endl;
	this->_raw = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_raw / (1 << Fixed::_bits));
}

int		Fixed::toInt(void) const
{
	return (this->_raw >> Fixed::_bits);
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2) {
    return (f1._raw < f2._raw) ? f1 : f2;
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2) {
    return (f1._raw < f2._raw) ? f1 : f2;
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2) {
    return (f1._raw > f2._raw) ? f1 : f2;
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2) {
    return (f1.getRawBits() > f2.getRawBits()) ? f1 : f2;
}