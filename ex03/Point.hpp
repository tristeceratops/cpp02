/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <ewoillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:47:43 by ewoillar          #+#    #+#             */
/*   Updated: 2024/08/27 16:18:09 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Fixed.hpp"

class Point
{
	private:
		const Fixed x;
		const Fixed y;
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point &p);
		~Point();
		Point	&operator=(const Point &p);
		bool	operator==(const Point &p) const;
		float	getx() const;
		float	gety() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);
