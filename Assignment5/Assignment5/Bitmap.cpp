#include "Bitmap.h"
#include "BitmapIterator.h"

namespace BitmapGraphics
{
	Bitmap::Bitmap(const uint32_t& width, const uint32_t& height) :
		bitmapWidth(width), bitmapHeight(height)
	{
	}

	HBitmapIterator Bitmap::createIterator()
	{
		return std::make_shared<BitmapIterator>(BitmapIterator(*this));
	}

	void Bitmap::setPixelColor(VG::Point const& location, Color const& color)
	{
		slCollection[location.getY()][location.getX()] = color;
	}
}
