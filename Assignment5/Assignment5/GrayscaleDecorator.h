#pragma once
#include "BitmapDecorator.h"

namespace BitmapGraphics
{
	class GrayscaleDecorator final : public BitmapDecorator
	{
	public:
		explicit GrayscaleDecorator(HBitmapIterator const& iterator);
		GrayscaleDecorator(const GrayscaleDecorator&) noexcept = default;
		GrayscaleDecorator(GrayscaleDecorator &&) noexcept  = default;
		GrayscaleDecorator& operator=(const GrayscaleDecorator&) = default;
		GrayscaleDecorator& operator=(GrayscaleDecorator&&) = default;
		~GrayscaleDecorator() = default;

		Color getColor() const override final;
	};
}
