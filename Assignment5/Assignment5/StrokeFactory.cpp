#include "StrokeFactory.h"

namespace BitmapGraphics
{
	StrokeFactory::StrokeFactory()
	{
		addStroke("square", std::make_shared<SquareStroke>());
		addStroke("slash", std::make_shared<SlashStroke>());
	}

	void StrokeFactory::addStroke(std::string const& tip, HStroke const& stroke)
	{
		myStrokes[tip] = stroke;
	}

	HStroke StrokeFactory::createStroke(std::string const& tip, std::string& color, int size)
	{
		if (myStrokes[tip])
		{
			auto stroke = myStrokes[tip];

			stroke->setColor(
				BitmapGraphics::Color
				(
					Binary::Byte(std::stoi("0x" + color.substr(0,2), nullptr, 0)),
					Binary::Byte(std::stoi("0x" + color.substr(2,2), nullptr, 0)),
					Binary::Byte(std::stoi("0x" + color.substr(4,2), nullptr, 0))
				)
			);
			stroke->setSize(size);
			return stroke;
		}
		else
			throw std::runtime_error("Pen type does not exist.");
	}
}
