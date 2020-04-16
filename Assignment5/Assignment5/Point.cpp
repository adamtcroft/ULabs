#include "Point.h"

namespace VG
{
	Point::Point(VG::Point&& other)
	{
		if (&other != this)
		{
			x = other.x;
			y = other.y;
			other.x = 0;
			other.y = 0;
		}
	}

	bool operator==(const VG::Point& lhs, const VG::Point& rhs)
	{
		return lhs.getX() == rhs.getX() && lhs.getY() == rhs.getY();
	}

	bool operator!=(const VG::Point& lhs, const VG::Point& rhs)
	{
		return !(lhs == rhs);
	}

	std::ostream& operator<<(std::ostream& output, const VG::Point& p)
	{
		output << "(" << p.getX() << ", " << p.getY() << ")";
		output.flush();

		return output;
	}
}


