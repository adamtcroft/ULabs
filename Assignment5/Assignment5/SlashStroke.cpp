#include "SlashStroke.h"
#include "SlashPen.h"

namespace BitmapGraphics
{
	void SlashStroke::setSize(int size)
	{
		mySize = size;
	}

	int SlashStroke::getSize() const
	{
		return mySize;
	}

	void SlashStroke::setColor(Color const& color)
	{
		myColor = color;
	}

	Color SlashStroke::getColor() const
	{
		return myColor;
	}

	HPen SlashStroke::createPen(HCanvas const& canvas)
	{
		return std::make_shared<SlashPen>(*this);
	}
}
