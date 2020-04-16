#include "BrightnessDecorator.h"

namespace BitmapGraphics
{
	BrightnessDecorator::BrightnessDecorator(HBitmapIterator const& iterator, int adjustment) :
		BitmapDecorator(iterator), brightnessAdjustment(adjustment)
	{
	}

	Color BrightnessDecorator::getColor() const
	{
		Color const oldColor = originalIterator->getColor();

		return oldColor + brightnessAdjustment;
	}
}
