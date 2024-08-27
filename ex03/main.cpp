/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <ewoillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 15:17:19 by ewoillar          #+#    #+#             */
/*   Updated: 2024/08/27 17:21:03 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int main() {
    // Define points to form a triangle
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(5.0f, 10.0f);

    // Test 1: Point inside the triangle
    Point p1(5.0f, 5.0f);
    std::cout << "Test 1 (Point inside the triangle): " 
              << (bsp(a, b, c, p1) ? "Passed" : "Failed") 
              << std::endl;

    // Test 2: Point on the edge of the triangle
    Point p2(5.0f, 0.0f);
    std::cout << "Test 2 (Point on the edge of the triangle): " 
              << (bsp(a, b, c, p2) ? "Failed" : "Passed") 
              << std::endl;

    // Test 3: Point outside the triangle
    Point p3(10.0f, 10.0f);
    std::cout << "Test 3 (Point outside the triangle): " 
              << (bsp(a, b, c, p3) ? "Failed" : "Passed") 
              << std::endl;

    // Test 4: Point coincides with a vertex of the triangle
    Point p4(0.0f, 0.0f);
    std::cout << "Test 4 (Point coincides with a vertex): " 
              << (bsp(a, b, c, p4) ? "Failed" : "Passed") 
              << std::endl;

    // Test 5: Degenerate case (collinear points)
    Point a2(0.0f, 0.0f);
    Point b2(5.0f, 5.0f);
    Point c2(10.0f, 10.0f);
    Point p5(7.5f, 7.5f);  // Point on the line formed by a2, b2, c2
    std::cout << "Test 5 (Degenerate case with collinear points): " 
              << (bsp(a2, b2, c2, p5) ? "Failed" : "Passed") 
              << std::endl;
    Point a4(0.0f, 0.0f);
    Point b4(1.0f, 5.0f);
    Point c4(10.0f, 8.0f);
    Point pp(10.0f, 50.0f);  // Point on the line formed by a2, b2, c2
  	std::cout << "Test 5.2 (Degenerate case with collinear points): " 
              << (bsp(a4, b4, c4, pp) ? "Failed" : "Passed") 
              << std::endl;

    // Test 6: Triangle with negative coordinates and point inside
    Point a3(-10.0f, -10.0f);
    Point b3(-5.0f, -10.0f);
    Point c3(-7.5f, -5.0f);
    Point p6(-7.5f, -7.5f);
    std::cout << "Test 6 (Triangle with negative coordinates and point inside): " 
              << (bsp(a3, b3, c3, p6) ? "Passed" : "Failed") 
              << std::endl;

    // Test 7: Triangle with negative coordinates and point outside
    Point p7(-15.0f, -15.0f);
    std::cout << "Test 7 (Triangle with negative coordinates and point outside): " 
              << (bsp(a3, b3, c3, p7) ? "Failed" : "Passed") 
              << std::endl;

    return 0;
}