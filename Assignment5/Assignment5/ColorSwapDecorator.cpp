#include "ColorSwapDecorator.h"

namespace BitmapGraphics
{
	ColorSwapDecorator::ColorSwapDecorator(HBitmapIterator const& iterator, int adjustment) :
		BitmapDecorator(iterator), swapChoice((adjustment % 3))
	{
	}

	Color ColorSwapDecorator::getColor() const
	{
		Color const oldColor = originalIterator->getColor();

		switch (swapChoice)
		{
		case 0:
			return oldColor;
			break;
		case 1:
			return Color(oldColor.getGreen(), oldColor.getBlue(), oldColor.getRed());
			break;
		case 3:
			return Color(oldColor.getBlue(), oldColor.getRed(), oldColor.getGreen());
		default:
			return oldColor;
			break;
		}
	}
}
