#pragma once
#include "BitmapDecorator.h"

namespace BitmapGraphics
{
	class KeepColorDecorator final : public BitmapDecorator
	{
	public:
		KeepColorDecorator(HBitmapIterator const& iterator, int adjustment);
		KeepColorDecorator(const KeepColorDecorator&) noexcept = default;
		KeepColorDecorator(KeepColorDecorator &&) noexcept  = default;
		KeepColorDecorator& operator=(const KeepColorDecorator&) = default;
		KeepColorDecorator& operator=(KeepColorDecorator&&) = default;
		~KeepColorDecorator() = default;

		Color getColor() const override final;

	private:
		int colorChoice{ 0 };
	};
}

