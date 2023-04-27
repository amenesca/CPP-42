#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point {

	public:
		Point(); // Default constructor
		Point(float const x, float const y); // Constructor that receives float
		Point(Point const& point); // Copy Constructor
		~Point(); // Destructor
		Point& operator=(Point const& point); // Copy assignment operator overload

	private:
		Fixed const x;
		Fixed const y;

};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif