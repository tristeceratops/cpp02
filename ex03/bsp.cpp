/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <ewoillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:47:49 by ewoillar          #+#    #+#             */
/*   Updated: 2024/08/27 17:21:26 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//si vecteur 

float triangle_area(Point const a, Point const b, Point const c){
	float xa, ya, xb, yb, xc, yc;

	xa = a.getx(); ya = a.gety();
	xb = b.getx(); yb = b.gety();
	xc = c.getx(); yc = c.gety();

	float area = (xa * (yb - yc) + xb * (yc - ya) + xc * (ya - yb)) / 2;
	if (area < 0)
		area = -area;
	return area;
}

bool bsp(Point const a, Point const b, Point const c, Point const point){
	
	float area1, area2, area3, area4;

	if (point == a || point == b || point == c)
		return false;

	area1 = triangle_area(a, b, c);
	if ((area2 = triangle_area(point, b, c)) == 0)
		return false;
	if ((area3 = triangle_area(a, point, c)) == 0)
		return false;
	if ((area4 = triangle_area(a, b, point)) == 0)
		return false;

	return (area1 == area2 + area3 + area4);
}