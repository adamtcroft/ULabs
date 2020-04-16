#pragma once
#include "BitmapDecorator.h"
#include <algorithm>

namespace BitmapGraphics
{
	class BrightnessDecorator final : public BitmapDecorator
	{
	public:
		BrightnessDecorator(HBitmapIterator const& iterator, int adjustment);
		BrightnessDecorator(const BrightnessDecorator&) noexcept = default;
		BrightnessDecorator(BrightnessDecorator &&) noexcept  = default;
		BrightnessDecorator& operator=(const BrightnessDecorator&) = default;
		BrightnessDecorator& operator=(BrightnessDecorator&&) = default;
		~BrightnessDecorator() = default;

		Color getColor() const override final;

	private:
		int brightnessAdjustment{ 0 };
	};
}

