#include "ColorInversionDecorator.h"


namespace BitmapGraphics
{
	ColorInversionDecorator::ColorInversionDecorator(HBitmapIterator const& iterator) :
		BitmapDecorator(iterator)
	{
	}

	Color ColorInversionDecorator::getColor() const
	{
		Color const oldColor = originalIterator->getColor();

		const int MAX_COLOR_VALUE{ 255 };

		return MAX_COLOR_VALUE - oldColor;
	}
}
