#include "BitmapIterator.h"

namespace BitmapGraphics
{
	BitmapIterator::BitmapIterator(Bitmap& bitmap) :
		myBitmap(&bitmap)
	{
		myWidth = myBitmap->getWidth();
		myHeight = myBitmap->getHeight();
		rowIterator = myBitmap->begin();
		if (!isEndOfImage())
			columnIterator = rowIterator->begin();
	}

	void BitmapIterator::nextScanLine()
	{
		++rowIterator;
		if (!isEndOfImage())
			columnIterator = rowIterator->begin();
	}

	bool BitmapIterator::isEndOfImage()
	{
		return (rowIterator == myBitmap->end());
	}

	void BitmapIterator::nextPixel()
	{
		++columnIterator;
	}

	bool BitmapIterator::isEndOfScanLine()
	{
		return(columnIterator == rowIterator->end());
	}

	BitmapGraphics::Color BitmapIterator::getColor() const
	{
		return *columnIterator;
	}
}
