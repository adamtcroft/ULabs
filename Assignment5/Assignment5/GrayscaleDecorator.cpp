#include "GrayscaleDecorator.h"

namespace BitmapGraphics
{
	GrayscaleDecorator::GrayscaleDecorator(HBitmapIterator const& iterator) :
		BitmapDecorator(iterator)
	{
	}

	Color GrayscaleDecorator::getColor() const
	{
		Color const oldColor = originalIterator->getColor();

		int redValue = oldColor.getRed().getValue();
		int greenValue = oldColor.getGreen().getValue();
		int blueValue = oldColor.getBlue().getValue();

		auto grayValue = (redValue + greenValue + blueValue) / 3;

		Binary::Byte gray{ static_cast<uint8_t>(grayValue) };

		return Color(gray, gray, gray);
	}
}
