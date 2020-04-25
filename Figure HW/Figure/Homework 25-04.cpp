#include <iostream>

#include "Figure.h"
#include "Polygone.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h" 
#include "Square.h"

int main()
{
	Point p1 = { 1, 0 };
	Point p2 = { 1, 1 };
	Point p3 = { 3, 1 };
	Point p4 = { 10, 10 };
	Point p5 = { 2, 2 };
	Point p6 = { 4, 4 };
	Point p7 = { 6, 2 };

	std::cout << "1)" << std::endl;
	p4.printP();
	std::cout << std::endl << std::endl;

	std::cout << "2)" << std::endl;
	p4.Set_x(1);
	p4.Set_y(2);
	p4.printP();
	std::cout << std::endl << std::endl;
	
	Figure f1 = { 10 };
	Figure f2 = { 10 };

	std::cout << "3)" << std::endl;
	f1.print_coord();
	std::cout << std::endl << std::endl;

	std::cout << "4)" << std::endl;
	f1.Set_point(p1);
	f1.print_coord();
	std::cout << std::endl << std::endl;

	std::cout << "5)" << std::endl;
	f1.Set_point(p1);
	f1.print_coord();
	std::cout << std::endl << std::endl;

	Circle c1 = { 3 };
	Circle c2 = { 3 };

	std::cout << "6)" << std::endl;
	c1.Set_point(p1);
	c1.print();
	std::cout << std::endl << std::endl;

	std::cout << "7)" << std::endl;
	c2.Set_point(p1);
	c2.set_r(10);
	c2.print();
	std::cout << std::endl << std::endl;

	Rectangle bad_rectangle = { 4 };
	Rectangle rectangle = { 4 };
	Rectangle rectangle2 = { 4 };

	std::cout << "8)" << std::endl;
	rectangle.Set_point(p1);
	rectangle.Set_point(p2);
	rectangle.Set_point(p3);
	rectangle.Check_rectangle();
	std::cout << std::endl << std::endl;


	std::cout << "9)" << std::endl;
	bad_rectangle.Set_point(p1);
	bad_rectangle.Set_point(p1);
	bad_rectangle.Set_point(p2);
	bad_rectangle.Check_rectangle();
	std::cout << std::endl << std::endl;

	std::cout << "10)" << std::endl;
	rectangle2.Set_point(p5);
	rectangle2.Set_point(p6);
	rectangle2.Set_point(p7);
	rectangle2.Check_rectangle();
	std::cout << std::endl << std::endl;


	Triangle t1 = { 3 };
	Triangle bad_t1 = { 3 };

	std::cout << "11)" << std::endl;
	t1.Set_point(p1);
	t1.Set_point(p2); 
	t1.Set_point(p3);
	t1.Check_triangle();
	std::cout << std::endl << std::endl;

	std::cout << "12)" << std::endl;
	bad_t1.Set_point(p1);
	bad_t1.Set_point(p1);
	bad_t1.Set_point(p3);
	bad_t1.Check_triangle();
	std::cout << std::endl << std::endl;
	
	Square bad_s1 = { 10 };
	Square s2 = { 10 };

	std::cout << "13)" << std::endl;
	bad_s1.Set_point(p1);
	bad_s1.Set_point(p2);
	bad_s1.Check_Square();
	std::cout << std::endl << std::endl;

	std::cout << "14)" << std::endl;
	s2.Set_point(p1);
	s2.Set_point(p3);
	s2.Check_Square();
	std::cout << std::endl << std::endl;









	
}

