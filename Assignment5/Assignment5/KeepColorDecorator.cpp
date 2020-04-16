#include "KeepColorDecorator.h"

namespace BitmapGraphics
{
	KeepColorDecorator::KeepColorDecorator(HBitmapIterator const& iterator, int adjustment) :
		BitmapDecorator(iterator), colorChoice(std::clamp(adjustment, 0, 2))
	{
	}

	Color KeepColorDecorator::getColor() const
	{
		Color const oldColor = originalIterator->getColor();

		auto redValue = oldColor.getRed().getValue();
		auto greenValue = oldColor.getGreen().getValue();
		auto blueValue = oldColor.getBlue().getValue();

		auto grayValue = (redValue + greenValue + blueValue) / 3;

		switch (colorChoice)
		{
		case 0:
			return Color(Binary::Byte(redValue), Binary::Byte(grayValue), Binary::Byte(grayValue));
			break;

		case 1:
			return Color(Binary::Byte(grayValue), Binary::Byte(greenValue), Binary::Byte(grayValue));
			break;

		case 2:
			return Color(Binary::Byte(grayValue), Binary::Byte(grayValue), Binary::Byte(blueValue));
			break;

		default:
			return Color(Binary::Byte(redValue), Binary::Byte(greenValue), Binary::Byte(blueValue));
			break;
		}
	}
}

