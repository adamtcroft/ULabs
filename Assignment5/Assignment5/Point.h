#pragma once
#include <iostream>

namespace VG
{
	class Point
	{
	public:
		Point() = default;
		constexpr Point(unsigned int initialX, unsigned int initialY) :
			x(initialX),
			y(initialY) {};

		Point(const Point& other) = default;
		Point(Point&& other);
		Point& operator=(const Point& other) = default;
		Point& operator=(Point&& other) = default;
		~Point() = default;

		constexpr int getX() const { return x; };
		constexpr int getY() const { return y; };

	private:
		int x{ 0 };
		int y{ 0 };
	};

	bool operator==(const VG::Point& lhs, const VG::Point& rhs);
	bool operator!=(const VG::Point& lhs, const VG::Point& rhs);
	std::ostream& operator<<(std::ostream& output, const VG::Point& p);

	struct mapComparePoints
	{
		bool operator()(Point const& lhs, Point const& rhs) const
		{
			return (lhs.getX() < rhs.getX()) || (lhs.getX() == rhs.getX() && lhs.getY() < rhs.getY());
		}
	};
}
