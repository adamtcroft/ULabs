#include "SquareStroke.h"
#include "SquarePen.h"

namespace BitmapGraphics
{
	void SquareStroke::setSize(int size)
	{
		mySize = size;
	}

	int SquareStroke::getSize() const
	{
		return mySize;
	}

	void SquareStroke::setColor(Color const& color)
	{
		myColor = color;
	}

	Color SquareStroke::getColor() const
	{
		return myColor;
	}

	HPen SquareStroke::createPen(HCanvas const& canvas)
	{
		return std::make_shared<SquarePen>(*this);
	}
}
