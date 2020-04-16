#include "BasicCanvas.h"
#include "BasicCanvasBitmapIterator.h"

namespace BitmapGraphics
{
	BasicCanvas::BasicCanvas(int width, int height, Color const& background) :
		myWidth(width), myHeight(height), myBackground(background)
	{
	}

	bool BasicCanvas::inBounds(VG::Point const& location) const
	{
		if ((location.getX() >= 0 && location.getX() <= myWidth) &&
			(location.getY() >= 0 && location.getY() <= myHeight))
			return true;
		else
			return false;
	}

	void BasicCanvas::setPixelColor(VG::Point const& location, Color const& color)
	{
		if (inBounds(location))
		{
			myPointMap[location] = color;
		}
		else
			throw std::runtime_error("Error: Can't set pixel out of bounds.");
	}

	Color BasicCanvas::getPixelColor(VG::Point const& location) const
	{
		if (inBounds(location))
		{
			if (myPointMap.find(location) == myPointMap.end())
				return myBackground;
			else
				return myPointMap.at(location);
		}
		else
			throw std::runtime_error("Error: Can't get pixel out of bounds.");
	}

	int BasicCanvas::getWidth() const
	{
		return myWidth;
	}

	int BasicCanvas::getHeight() const
	{
		return myHeight;
	}

	HBitmapIterator BasicCanvas::createBitmapIterator()
	{
		if (myWidth == 0 || myHeight == 0)
			throw std::runtime_error("Error: Cannot return iterator if canvas has no size.");
		else
		{
			return std::make_shared<BasicCanvasBitmapIterator>(*this);
		}
	}
}
