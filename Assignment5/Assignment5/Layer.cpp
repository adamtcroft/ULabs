#include "Layer.h"

namespace Framework
{
	Layer::Layer(std::string const& initialAlias) :
		alias(initialAlias)
	{
	}

	void Layer::remove(const PlacedGraphic& pg)
	{
		graphics.remove(pg);
	}

	Layer::PlacedGraphicIterator Framework::Layer::begin() const
	{
		return graphics.begin();
	}

	Layer::PlacedGraphicIterator Framework::Layer::end() const
	{
		return graphics.end();
	}

	PlacedGraphic const& Framework::Layer::getGraphic(const int& index)
	{
		if (index > graphics.size())
			throw std::out_of_range("The graphic requested does not exist.");
		else
		{
			PlacedGraphicIterator iterator = graphics.begin();
			std::advance(iterator, index);
			return *iterator;
		}

	}

	void Layer::setAlias(const std::string& referenceAlias)
	{
		alias = referenceAlias;
	}

	std::string const& Layer::getAlias() const
	{
		return alias;
	}

	void Layer::draw(BitmapGraphics::HCanvas& canvas)
	{
		for (auto& graphic : graphics)
		{
			graphic.draw(canvas);
		}
	}

	bool Layer::operator==(const Framework::Layer& rhs) const
	{
		return (graphics == rhs.graphics) && (alias == rhs.alias);
	}

	bool Layer::operator!=(const Framework::Layer& rhs) const
	{
		return !operator==(rhs);
	}
}
