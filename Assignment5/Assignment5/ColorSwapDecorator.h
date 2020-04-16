#pragma once
#include "BitmapDecorator.h"

namespace BitmapGraphics
{
	class ColorSwapDecorator final : public BitmapDecorator
	{
	public:
		ColorSwapDecorator(HBitmapIterator const& iterator, int adjustment);
		ColorSwapDecorator(const ColorSwapDecorator&) noexcept = default;
		ColorSwapDecorator(ColorSwapDecorator &&) noexcept  = default;
		ColorSwapDecorator& operator=(const ColorSwapDecorator&) = default;
		ColorSwapDecorator& operator=(ColorSwapDecorator&&) = default;
		~ColorSwapDecorator() = default;

		Color getColor() const override final;

	private:
		int swapChoice{ 0 };
	};

}
