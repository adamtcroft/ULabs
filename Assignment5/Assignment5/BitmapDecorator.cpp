#include "BitmapDecorator.h"

namespace BitmapGraphics
{
	BitmapDecorator::BitmapDecorator(HBitmapIterator const& iterator) :
		originalIterator(iterator)
	{
	}

	void BitmapDecorator::nextScanLine()
	{
		originalIterator->nextScanLine();
	}

	bool BitmapDecorator::isEndOfImage()
	{
		return originalIterator->isEndOfImage();
	}

	void BitmapDecorator::nextPixel()
	{
		originalIterator->nextPixel();
	}

	bool BitmapDecorator::isEndOfScanLine()
	{
		return originalIterator->isEndOfScanLine();
	}

	int BitmapDecorator::getBitmapWidth() const
	{
		return originalIterator->getBitmapWidth();
	}

	int BitmapDecorator::getBitmapHeight() const
	{
		return originalIterator->getBitmapHeight();
	}

	int BitmapDecorator::getBitmapFileSize() const
	{
		return originalIterator->getBitmapFileSize();
	}
}
