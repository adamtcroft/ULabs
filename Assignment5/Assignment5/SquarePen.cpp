#include "SquarePen.h"

namespace BitmapGraphics
{
	void SquarePen::drawPoint(const HCanvas& canvas, const VG::Point& point)
	{
		unsigned int sizeX = 0;
		unsigned int sizeY = 0;
		while (sizeX < myStroke->getSize())
		{
			while (sizeY < myStroke->getSize())
			{
				VG::Point p{ point.getX() + sizeX, point.getY() + sizeY };
				canvas->setPixelColor(p, myStroke->getColor());
				++sizeY;
			}
			++sizeX;
			sizeY = 0;
		}
	}
}
