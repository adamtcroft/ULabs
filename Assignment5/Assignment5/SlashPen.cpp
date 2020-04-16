#include "SlashPen.h"

namespace BitmapGraphics
{
	void SlashPen::drawPoint(const HCanvas& canvas, const VG::Point& point)
	{
		unsigned int sizeX = 0;
		while (sizeX < myStroke->getSize())
		{
			if (sizeX >= (myStroke->getSize() / 2))
			{
				VG::Point p{ (point.getX() + sizeX), (point.getY() - (sizeX + 2)) };
				canvas->setPixelColor(p, myStroke->getColor());
			}
			else
			{
				VG::Point p{ (point.getX() + sizeX), (point.getY() - (sizeX + 1)) };
				canvas->setPixelColor(p, myStroke->getColor());
			}
			++sizeX;
		}
	}
}
