#include "BasicCanvasBitmapIterator.h"

namespace BitmapGraphics
{

	BasicCanvasBitmapIterator::BasicCanvasBitmapIterator(BasicCanvas& canvas) :
		myCanvas(&canvas)
	{
		myX = 0;
		myY = myCanvas->getHeight();
	}

	void BasicCanvasBitmapIterator::nextScanLine()
	{
		--myY;
		myX = 0;
	}

	bool BasicCanvasBitmapIterator::isEndOfImage()
	{
		if (myY <= 0)
			return true;
		else
			return false;
	}

	void BasicCanvasBitmapIterator::nextPixel()
	{
		if (myX < myCanvas->getWidth())
			++myX;
		else
		{
			nextScanLine();
		}
	}

	bool BasicCanvasBitmapIterator::isEndOfScanLine()
	{
		if (myX >= myCanvas->getWidth())
			return true;
		else
			return false;
	}

	BitmapGraphics::Color BasicCanvasBitmapIterator::getColor() const
	{
		return myCanvas->getPixelColor(VG::Point{ myX, myY });
	}

	int BasicCanvasBitmapIterator::getBitmapWidth() const
	{
		return myCanvas->getWidth();
	}

	int BasicCanvasBitmapIterator::getBitmapHeight() const
	{
		return myCanvas->getHeight();
	}
}
