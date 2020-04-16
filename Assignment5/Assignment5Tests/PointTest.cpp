//
//  PointTest.cpp
//  Assignment1
//
//  Created by Chris Elderkin on 4/26/15.
//  Copyright (c) 2015 Chris Elderkin. All rights reserved.
//

#include "Point.h"
#include "TestHarness.h"

TEST(equality, Point)
{
	CHECK_EQUAL(VG::Point(1, 2), VG::Point(1, 2));
}

TEST(inequality, Point)
{
	CHECK(VG::Point(1, 2) != VG::Point(3, 4));
}

TEST(inequality2, Point)
{
	CHECK(VG::Point(1, 2) != VG::Point(1, 4));
}

TEST(inequality3, Point)
{
	CHECK(VG::Point(2, 4) != VG::Point(1, 4));
}

TEST(constexprPoint, Point)
{
	constexpr int i = VG::Point{ 4,5 }.getX();

	CHECK_EQUAL(i, 4);
}

TEST(constexprPointY, Point)
{
	constexpr int i = VG::Point{ 4,5 }.getY();

	CHECK_EQUAL(i, 5);
}

//TEST(setters, Point)
//{
//	VG::Point p;
//
//	p.setX(0);
//	p.setY(1);
//
//	CHECK_EQUAL(0, p.getX());
//	CHECK_EQUAL(1, p.getY());
//}

TEST(ostream, Point)
{
	VG::Point p{ 8,10 };

	std::ostringstream oss;
	oss << p;
	std::string myString = oss.str();

	CHECK_EQUAL("(8, 10)", myString);
}

TEST(copyCtor, Point)
{
	VG::Point p{ 1,0 };
	VG::Point p2(p);

	CHECK_EQUAL(p, p2);
}

TEST(moveCtor, Point)
{
	VG::Point p{ 1,1 };
	VG::Point p2(std::move(p));

	CHECK_EQUAL(0, p.getX());
	CHECK_EQUAL(0, p.getY());
	CHECK_EQUAL(1, p2.getX());
	CHECK_EQUAL(1, p2.getY());

	VG::Point p3{ 0,0 };
	VG::Point p4(std::move(p3));

	CHECK_EQUAL(p3, p4);


	VG::Point p5{ 0, 2 };
	VG::Point p6(std::move(p5));
	
	CHECK_EQUAL(p5.getX(), p6.getX());
	CHECK_EQUAL(0, p5.getY());
	CHECK_EQUAL(2, p6.getY());
}

TEST(getters, Point)
{
	VG::Point p{ 8,9 };

	CHECK_EQUAL(8, p.getX());
	CHECK_EQUAL(9, p.getY());
}

//TEST(lessThanZero, Point)
//{
//	VG::Point p{ -3, -9 };
//
//	CHECK_EQUAL(0, p.getX());
//	CHECK_EQUAL(0, p.getY());
//	
//	p.setX(-100);
//	p.setY(-10);
//
//	CHECK_EQUAL(0, p.getX());
//	CHECK_EQUAL(0, p.getY());
//}
