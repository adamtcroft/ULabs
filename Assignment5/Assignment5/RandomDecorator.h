#pragma once
#include "BitmapDecorator.h"
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>

namespace BitmapGraphics
{
	class RandomDecorator final : public BitmapDecorator
	{
	public:
		explicit RandomDecorator(HBitmapIterator const& iterator);
		RandomDecorator(const RandomDecorator&) noexcept = default;
		RandomDecorator(RandomDecorator &&) noexcept  = default;
		RandomDecorator& operator=(const RandomDecorator&) = default;
		RandomDecorator& operator=(RandomDecorator&&) = default;
		~RandomDecorator() = default;

		Color getColor() const override final;

	private:
		unsigned seed{ 0 };
	};
}

