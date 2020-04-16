#pragma once
#include "BitmapDecorator.h"

namespace BitmapGraphics
{
	class ColorInversionDecorator final : public BitmapDecorator
	{
	public:
		explicit ColorInversionDecorator(HBitmapIterator const& iterator);
		ColorInversionDecorator(const ColorInversionDecorator&) noexcept = default;
		ColorInversionDecorator(ColorInversionDecorator &&) noexcept  = default;
		ColorInversionDecorator& operator=(const ColorInversionDecorator&) = default;
		ColorInversionDecorator& operator=(ColorInversionDecorator&&) = default;
		~ColorInversionDecorator() = default;

		Color getColor() const override final;
	};
}

