/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <ewoillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:47:45 by ewoillar          #+#    #+#             */
/*   Updated: 2024/08/27 16:18:17 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const float x, const float y) : x(x), y(y) {}

Point::Point(const Point &p) : x(p.x), y(p.y) {}

Point::~Point(){}

Point &Point::operator=(const Point &p){
	(Fixed)this->x = p.x;
	(Fixed)this->y = p.y;
	return *this;
}

bool Point::operator==(const Point &p) const{
	return (this->x.toFloat() == p.x.toFloat() && this->y.toFloat() == p.y.toFloat());
}

float Point::getx() const {
	return this->x.toFloat();
}

float Point::gety() const{
	return this->y.toFloat();
}