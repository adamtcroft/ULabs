#include "RandomDecorator.h"

namespace BitmapGraphics
{
	RandomDecorator::RandomDecorator(HBitmapIterator const& iterator) : 
		BitmapDecorator(iterator), seed(std::chrono::system_clock::now().time_since_epoch().count())
	{
	}

	Color RandomDecorator::getColor() const
	{
		Color const oldColor = originalIterator->getColor();

		std::vector<Binary::Byte> storedBytes
		{
			oldColor.getRed(),
			oldColor.getGreen(),
			oldColor.getBlue()
		};

		std::shuffle(storedBytes.begin(), storedBytes.end(), std::default_random_engine(seed));

		return Color(storedBytes[0], storedBytes[1], storedBytes[2]);
	}
}
